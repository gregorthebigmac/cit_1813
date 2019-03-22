#ifndef RANDOM_WORD_HPP
#define RANDOM_WORD_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

class random_word {
public:
    random_word(std::string file_name);
    ~random_word() {}
    void generate_list_from_file(std::string file_name);
    void populate_word_list(std::vector<std::string> unsorted_word_list);

private:
    std::string m_password;
    std::vector<std::vector <std::string> > m_word_list; // using a 2D vector for sorting (and finding) by size
};

random_word::random_word(std::string file_name) {
    generate_list_from_file(file_name);
}

void random_word::generate_list_from_file(std::string file_name) {
    std::vector<std::string> _temp_word_list;
    std::string _file_name = file_name;
    std::ifstream fin;
    std::cout << "Loading words from dictionary file...";
    fin.open(_file_name.c_str());
    if (fin.is_open()) {
        int biggest_word = 0;
        while(!fin.eof()) {
            std::string temp;
            std::getline(fin, temp);
            if (temp.size() > biggest_word) {
                biggest_word = temp.size();
            }
            _temp_word_list.push_back(temp);
        }
        std::cout << "[OK]" << std::endl;
        std::cout << "Successfully loaded " << _temp_word_list.size() << " words." << std::endl;
        biggest_word++;
        for (int i = 0; i < biggest_word; i++) {
            // this is prepending each [x] coordinate with a string whose first [y] coordinate corresponds to the number of letters in each
            // word. This will result in the [0] index of the [x] coordinate containing NO STRINGS except the first one, which will be the
            // string "0" This avoids the off-by-one error associated with zeros, and allows for the number of letters in the string to
            // correspond exactly to the [x] coordinate of the vector it belongs to, with only one wasted [x][y] coordinate in the vector.
            std::string temp_str;
            std::ostringstream convert;
            convert << i;
            temp_str = convert.str();
            std::vector<std::string> temp_vec;
            temp_vec.push_back(temp_str);
            m_word_list.push_back(temp_vec);
        }
        populate_word_list(_temp_word_list);
    }
    else {
        std::cout << "[FAIL]" << std::endl;
        std::cout << "file [" << _file_name << "] not found! Please ensure the file exists before running again!" << std::endl;
    }
}

void random_word::populate_word_list(std::vector<std::string> unsorted_word_list) {
    for (int i = 0; i < unsorted_word_list.size(); i++) {
        std::string temp = unsorted_word_list[i];
        m_word_list[temp.size()].push_back(temp);
    }
    for (int x = 0; x < m_word_list.size(); x++) {
        std::cout << "Printing contents of m_word_list[" << x << "]..." << std::endl;
        for (int y = 0; y < m_word_list[x].size(); y++) {
            std::cout << "m_word_list[" << x << "] [" << y << "] = " << m_word_list[x][y] << std::endl;
        }
    }
}

#endif