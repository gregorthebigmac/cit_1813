#pragma once
#include "random_word.h"

class hangman {
public:
	hangman();
	~hangman();

	void set_word_length();
	void set_number_of_guesses();
	void play();
	void print_game_screen();
	void player_guess_letter();

	// DEBUG
	void toggle_debug_mode() { _debug_mode = !_debug_mode; }

private:
	int m_word_length;
	std::string m_password;
	std::vector<bool> m_pass_check;
	uint8_t _last_guess;
	int m_num_of_allowed_guesses;
	std::vector<char> _letters_guessed;
	int _score;
	// DEBUG
	bool _debug_mode;
};
