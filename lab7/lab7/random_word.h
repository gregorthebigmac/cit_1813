#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class random_word {
public:
	random_word(std::string file_name);
	random_word(std::string file_name, bool debug_mode);
	~random_word() {}

	void generate_list_from_file(std::string file_name);
	void populate_word_list(std::vector<std::string> unsorted_word_list);
	std::string pick_random_word(int word_length);
	void toggle_debug_mode() { _debug_mode = !_debug_mode; }

private:
	bool _debug_mode;
	void _debug_print_word_list();
	void _verify_contents();
	std::string m_password;

	// I'm using a 2D vector for sorting (and finding) words by size. The word list is already in alphabetical order (mostly), so the
	// final 2D vector should be (nearly) sorted, as it goes through the word list from start to end (in order), and puts them in their
	// appropriate vector "buckets" by their size.
	std::vector<std::vector <std::string> > m_word_list;
};
