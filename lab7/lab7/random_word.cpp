#include "pch.h"
#include "random_word.h"


random_word::random_word(std::string file_name) {
	_debug_mode = false;
	generate_list_from_file(file_name);
}

random_word::random_word(std::string file_name, bool debug_mode) {
	_debug_mode = true;
	generate_list_from_file(file_name);
}

void random_word::generate_list_from_file(std::string file_name) {
	std::vector<std::string> _temp_word_list;
	std::string _file_name = file_name;
	std::ifstream fin;
	std::cout << "Loading words...";
	fin.open(_file_name.c_str());
	if (fin.is_open()) {
		int biggest_word = 0;
		while (!fin.eof()) {
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
		/*
		This is prepending each [x] coordinate with a string whose first [y] coordinate corresponds to the number of letters in each
		word. This will result in m_word_list[0] containing only 1 string, which will be m_word_list[0][0] = "0" and
		m_word_list[1][0] = "1", m_word_list[2][0] = "2", etc. I couldn't think of a better (i.e. more efficient) way of populating
		the 2D vector, because AFAIK the only way to push_back() on the first dimension of a 2D vector is if you're pushing back a
		1D vector of the same type. So to do this, I converted the integer of the index counter to a string, push *that* back into the
		temporary 1D string vector I create in the loop, and push *that* vector back into the 2D vector. This also ensures that whatever
		temporary vectors I create in this process are guaranteed to be destroyed once it leaves scope, which prevents memory leaks,
		and keeps performance high.
		This 2D vector scheme of populating m_word_list[0] and m_word_list[1] with a single string each avoids the off-by-one error
		commonly associated with vectors by allowing the number of letters in the string to	correspond exactly to the [x] coordinate
		of the vector it belongs to, with only two wasted [x][y] coordinates in the	entire 2D Vector, which is pretty small.
		*/
		for (int i = 0; i < biggest_word; i++) {
			std::string temp_str;
			std::ostringstream convert;
			convert << i;
			temp_str = convert.str();
			std::vector<std::string> temp_vec;
			temp_vec.push_back(temp_str);
			m_word_list.push_back(temp_vec);
		}
		populate_word_list(_temp_word_list);
		_verify_contents();
		if (_debug_mode) 
			_debug_print_word_list();
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
}

std::string random_word::pick_random_word(int word_length) {
	srand(time(NULL));
	int random_index = rand() % m_word_list[word_length].size();
	random_index++;	// otherwise we get 0 as a possible index, and that would just return a number.
	return m_word_list[word_length].at(random_index);
}

void random_word::_debug_print_word_list() {
	bool _should_i_pause = false;
	int _pause_this_often = 1000000;	// how many entries printed before pausing (default 1000000)
	std::cout << "########## DEBUG MODE ##########" << std::endl;
	std::cout << "Do you want me to pause the debug data periodically? y/n" << std::endl;
	std::string _pause;
	std::getline(std::cin, _pause);
	if (_pause[0] == 'y' || _pause[0] == 'Y') {
		_should_i_pause = true;
		std::cout << "How many lines should I print before pausing? [enter an integer]" << std::endl;
		std::cin >> _pause_this_often;	// NOTE! I'm not checking for accurate data types. It's assumed the user knows what they're doing.
	}
	for (int x = 0; x < m_word_list.size(); x++) {
		std::cout << "Printing contents of m_word_list[" << x << "]..." << std::endl;
		for (int y = 0; y < m_word_list[x].size(); y++) {
			if (y % _pause_this_often == 0)
				system("PAUSE");
			std::cout << "m_word_list[" << x << "] [" << y << "] = " << m_word_list[x][y] << std::endl;
		}
	}
}

void random_word::_verify_contents() {
	int word_count = 0;
	if (_debug_mode)
		std::cout << "Verifying contents of word list..." << std::endl;
	// I'm not sure why, but somehow the m_word_list[0] vector gets overpopulated with 2 empty (i.e. "") strings. It only happens to
	// m_word_list[0] and none of the others, so I threw in this while loop to trim it back down to what it's supposed to be.
	while (m_word_list[0].size() > 1) {
		m_word_list[0].pop_back();
	}
	for (int x = 0; x < m_word_list.size(); x++) {
		int inside_word_count = m_word_list[x].size() - 1;
		if (_debug_mode)
			std::cout << "Words of length [" << x << "] = " << inside_word_count << std::endl;
		word_count = word_count + m_word_list[x].size();
	}
	word_count = word_count - m_word_list.size();
	if (_debug_mode)
		std::cout << "Total count of words in list = " << word_count << std::endl;
}