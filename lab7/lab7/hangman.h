#pragma once
#include "random_word.h"

class hangman {
public:
	hangman() { reset_new_game(); }
	~hangman() {}

	void reset_new_game();
	void set_word_length();
	void set_number_of_guesses();
	void play();
	void print_game_screen();
	void player_solve_puzzle();
	void player_guess_letter();
	void check_player_guess(char guess);

	// DEBUG
	void toggle_debug_mode() { _debug_mode = !_debug_mode; }

private:
	void done();
	int m_word_length;
	std::string m_password;
	std::vector<bool> m_pass_check;
	uint8_t _last_guess;
	int m_num_of_allowed_guesses;
	std::vector<char> _letters_guessed;
	int _score;
	bool _game_won;
	// DEBUG
	bool _debug_mode;
};
