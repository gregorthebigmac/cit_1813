#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctype.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

vector<string> final_word_list;
vector<string> temp_word_list;

int read_from_file(string filename);
void all_to_lower();
void eliminate_duplicates();
int write_to_file(string filename);

int main() {
    vector<int> error_list;
    error_list.push_back(read_from_file("words"));
    if (error_list[0] == 0) {
        cout << "words read from file. Converting all to lower...";
        all_to_lower();
        cout << "[OK]" << endl;
        cout << "Checking for duplicates...";
        eliminate_duplicates();
        cout << "[OK]" << endl;
        cout << "Final word list now contains " << final_word_list.size() << " words." << endl;
        cout << "Culled word list complete. Printing to new file [culled]...";
        error_list.push_back(write_to_file("culled"));
        if (error_list[1] == 0) {
            cout << "Done!" << endl;
            return 0;
        }
        else return error_list[1];
    }
    else return error_list[0];
}

int read_from_file(string filename) {
    std::ifstream fin;
    fin.open("words");
    if (fin.is_open()) {
        while (!fin.eof()) {
            bool word_is_valid = true;
            string temp;
            std::getline(fin, temp);
            for (int i = 0; i < temp.size(); i++) {
                if (!isalpha(temp[i])) {
                    word_is_valid = false;
                    break;
                }
            }
            if (word_is_valid)
                temp_word_list.push_back(temp);
        }
        fin.close();
        return 0;
    }
    else {
        cout << "file [words] not found!" << endl;
        return 1;
    }
    return 99;  // denotes that the function behaved abnormally. It should NEVER return 99
}

void all_to_lower() {
    for (int x = 0; x < temp_word_list.size(); x++) {
        for (int y = 0; y < temp_word_list[x].size(); y++) {
            char temp = tolower(temp_word_list[x].at(y));
            temp_word_list[x].at(y) = temp;
        }
    }
}

void eliminate_duplicates() {
    for (int x = 0; x < temp_word_list.size(); x++) {
        bool duplicate_found = false;
        cout << "Checking for duplicates of " << temp_word_list[x] << "...";
        for (int y = 0; y < temp_word_list.size(); y++) {
            if (x != y) {
                if (temp_word_list[x] == temp_word_list[y]) {
                    duplicate_found = true;
                    cout << "[FOUND]" << endl;
                    cout << "temp_word_list[" << x << "] = temp_word_list[" << y << "]" << endl;
                    break;
                }
            }
            else {
                cout << "[SKIPPING]" << endl;
                cout << "x = " << x << " and y = " << y << endl;
            }
        }
        if (!duplicate_found)
            final_word_list.push_back(temp_word_list[x]);
    }
}

int write_to_file(string filename) {
    std::ofstream fout;
    fout.open("culled");
    if (fout.is_open()) {
        for (int i = 0; i < final_word_list.size(); i++) {
            fout << final_word_list[i] << endl;
        }
        cout << "[OK]" << endl;
        fout.close();
        return 0;
    }
    else {
        cout << "[FAIL]" << endl;
        return 1;
    }
    return 99;  // denotes that the function behaved abnormally. It should NEVER return 99
}