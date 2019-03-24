#pragma once
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
