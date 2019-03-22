#ifndef RANDOM_WORD_HPP
#define RANDOM_WORD_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class random_word {
public:
    random_word(std::string file_name);
    ~random_word() {}
    void generate_list_from_file(std::string file_name);

private:
    std::string m_password;
    std::vector<std::string> m_random_word_list;
};

random_word::random_word(std::string file_name) {
    generate_list_from_file(file_name);
}

void random_word::generate_list_from_file(std::string file_name) {
    std::string _file_name = file_name;
    std::ifstream fin;
    std::cout << "Loading words from dictionary file...";
    fin.open(_file_name.c_str());
    if (fin.is_open()) {
        while(!fin.eof()) {
            std::string temp;
            std::getline(fin, temp);
            m_random_word_list.push_back(temp);
        }
        std::cout << "[OK]" << std::endl
            << "Successfully loaded " << m_random_word_list.size() << " words." << std::endl;
    }
    else {
        std::cout << "[FAIL]" << std::endl;
        std::cout << "file [" << _file_name << "] not found! Please ensure the file exists before running again!" << std::endl;
    }
}

#endif