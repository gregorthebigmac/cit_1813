#pragma once
#include "hangman.h"

random_word word("words");

void hangman::reset_new_game() {
	m_word_length = 0;
	_last_guess = 0;
	_score = 0;
	_game_won = false;
	_debug_mode = false;
	m_password = "";
	while (m_pass_check.size() > 0) {
		m_pass_check.pop_back(); }
	while (_letters_guessed.size() > 0) {
		_letters_guessed.pop_back(); }
}

void hangman::set_word_length() {
	system("CLS");
	int length;
	std::cout << "How long of a word do you want? Pick a number between 2 and 22." << std::endl;
	std::cin >> length;
	std::cin.ignore();
	if (length > 1 && length < 23) {
		m_word_length = length;
		set_number_of_guesses();
	}
	else {
		std::cout << "Sorry, that's not a number between 2 and 22. Try again." << std::endl;
		system("PAUSE");
		set_word_length();
	}
}

void hangman::set_number_of_guesses() {
	std::cout << "How many guesses would you like? Pick a number between 1 and 20" << std::endl;
	int num_guesses = 0;
	std::cin >> num_guesses;
	std::cin.ignore();
	if ((num_guesses > 0) && (num_guesses < 21)) {
		m_num_of_allowed_guesses = num_guesses; }
	else {
		std::cout << "Sorry, but " << num_guesses << " is NOT between 1 and 20. Try again." << std::endl;
		system("PAUSE");
		system("CLS");
		set_number_of_guesses();
	}
}

void hangman::play() {
	system("CLS");
	if (m_word_length == 0) {
		set_word_length();
		m_password = word.pick_random_word(m_word_length);
		for (int i = 0; i < m_password.size(); i++) {
			m_pass_check.push_back(false); }
	}
	if (_debug_mode) {
		std::cout << "Password is [" << m_password << "]" << std::endl; }
	print_game_screen();
}

void hangman::print_game_screen() {
	/*
	Finished product should look like:

	+---------------------------------------------------------------------------------+
	| WRONG!                                                                          |
	|                                                                                 |
	| Number of Guesses Left: 02                                                      |
	| Letters Guessed: A C D F H I L M O P S U                                        |
	|                                                                                 |
	|                                                                                 |
	| _  _  _  H  _  _  A  _  _  _  _  _  L  _  _  _  _  _  _  _  _  _                |
	|                                                                                 |
	+---------------------------------------------------------------------------------+

	  Guess a letter:

	With each underscore representing a letter which has not been guessed yet.
	*/
	system("CLS");
	std::cout << "+---------------------------------------------------------------------------------+" << std::endl;
	
	if (_last_guess == 0) {
		std::cout << "|                                                                                 |" << std::endl; }
	else if (_last_guess == 1) {
		std::cout << "| CORRECT!                                                                        |" << std::endl; }
	else {
		std::cout << "| WRONG!                                                                          |" << std::endl; }
	
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "| Number of Guesses Left: ";
	
	int guesses_remaining = m_num_of_allowed_guesses - _letters_guessed.size();
	if (guesses_remaining < 10) {
		std::cout << "0"; }

	std::cout << guesses_remaining << "                                                      |" << std::endl;
	std::cout << "| Letters Guessed: ";

	for (int i = 0; i < _letters_guessed.size(); i++) {
		std::cout << _letters_guessed[i] << " "; }

	for (int i = (2* _letters_guessed.size()); i < 63; i++) {
		std::cout << " "; }
	
	std::cout << "|" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "| ";
	
	for (int i = 0; i < m_password.size(); i++) {
		if (m_pass_check[i] == true) {
			std::cout << m_password[i] << "  "; }
		else { std::cout << "_  "; }
	}

	for (int i = (3 * m_password.size()); i < 80; i++) {
		std::cout << " "; }
	
	std::cout << "|" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "+---------------------------------------------------------------------------------+" << std::endl;
	
	if (guesses_remaining < 1) {
		std::cout << "All out of guesses! You lose!" << std::endl;
		return;
	}
	else {
		if (check_if_player_won() == false) {
			player_guess_letter(); }
		else {
			std::cout << "Congrats! You solved the puzzle!" << std::endl;
			return;
		}
	}
}
void hangman::player_solve_puzzle()
{
	std::cout << "Would you like to try to solve the puzzle? y/n" << std::endl;
	std::string answer;
	std::getline(std::cin, answer);
	if (answer[0] == 'y' || answer[0] == 'Y') {
		std::cout << "Enter your guess: ";
		std::string guess;
		std::getline(std::cin, guess);
		if (guess.size() != m_password.size()) {
			std::cout << "Your guess does not match the number of letters in the puzzle! Are you sure you want to submit this guess? y/n" << std::endl;
			std::getline(std::cin, answer);
			if (answer[0] == 'y' || answer[0] == 'Y') {
				if (guess == m_password) {
					std::cout << "I... don't know what just happened, but somehow... you... won? Congrats?" << std::endl;
					_game_won = true;
					return;
				}
				else {
					std::cout << "Oooookaay. Well, it should be no surprise that " << guess << " is WRONG!" << std::endl;
					system("PAUSE");
					m_num_of_allowed_guesses--;
					print_game_screen();
					return;
				}
			}
			else {
				std::cout << "Wise choice!";
				print_game_screen();
				return;
			}
		}
		else {
			if (guess == m_password) {
				std::cout << "You got it!" << std::endl;
				_game_won = true;
				return;
			}
			else {
				std::cout << "Nope! That counts as one incorrect guess!" << std::endl;
				m_num_of_allowed_guesses--;
				system("PAUSE");
				print_game_screen();
				return;
			}
		}
	}
	else { print_game_screen(); }
}
void hangman::player_guess_letter()
{
	std::cout << "  Guess a letter, or type \"1\" (without the quotes) to solve the puzzle: ";
	std::string guess;
	std::getline(std::cin, guess);
	if (guess[0] == '1') {
		player_solve_puzzle(); }
	else if (guess[0] == ' ') {
		std::cout << "Why did you put a space in your guess? There are no spaces in any of these words! Try again!" << std::endl;
		system("PAUSE");
		print_game_screen();
		return;
	}
	else if (guess == "") {
		print_game_screen();
		return;
	}
	else { check_player_guess(guess[0]); }
}

void hangman::check_player_guess(char guess)
{
	bool guess_is_correct = false;
	std::cout << std::endl << "You chose " << guess << ". Is this correct? y/n" << std::endl;
	std::string confirm;
	std::getline(std::cin, confirm);
	if (confirm[0] != 'y' && confirm[0] != 'Y') {	// used a NOT-AND-NOT here to keep the indentation flow nice and pretty!
		print_game_screen();
		return;
	}
	for (int i = 0; i < _letters_guessed.size(); i++) {
		if (guess == _letters_guessed[i]) {
			std::cout << "You already guessed that letter! Try a different one!" << std::endl;
			system("PAUSE");
			print_game_screen();
			return;
		}
	}
	for (int i = 0; i < m_password.size(); i++) {
		if (guess == m_password[i]) {
			guess_is_correct = true;
			m_pass_check[i] = true;
		}
	}
	if (guess_is_correct) {
		_last_guess = 1; }
	else { _last_guess = 2; }

	_letters_guessed.push_back(guess);
	int guesses_remaining = m_num_of_allowed_guesses - _letters_guessed.size();
	if (guesses_remaining > 0) {
		print_game_screen(); }
	else { std::cout << "All out of guesses! You lose!" << std::endl; }
}

bool hangman::check_if_player_won() {
	for (int i = 0; i < m_pass_check.size(); i++) {
		if (m_pass_check[i] == false) {
			return false; }
	}
	return true;
}