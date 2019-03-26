#include "pch.h"
#include "hangman.h"

random_word word("words");

hangman::hangman() {
	m_word_length = 0;
	_last_guess = 0;
	_score = 0;
	_debug_mode = false;
}

hangman::~hangman() {}

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
	if ((num_guesses > 0) && (num_guesses < 21))
		m_num_of_allowed_guesses = num_guesses;
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
			m_pass_check.push_back(false);
		}
	}
	if (_debug_mode)
		std::cout << "Password is [" << m_password << "]" << std::endl;
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
	if (_last_guess == 0)
		std::cout << "|                                                                                 |" << std::endl;
	else if (_last_guess == 1)
		std::cout << "| CORRECT!                                                                        |" << std::endl;
	else if (_last_guess == 2)
		std::cout << "| WRONG!                                                                          |" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "| Number of Guesses Left: ";
	int guesses_remaining = m_num_of_allowed_guesses - _letters_guessed.size();
	if (guesses_remaining < 10)
		std::cout << "0";
	std::cout << guesses_remaining << "                                                      |" << std::endl;
	std::cout << "| Letters Guessed: ";
	for (int i = 0; i < _letters_guessed.size(); i++) {
		std::cout << _letters_guessed[i] << " ";
	}
	for (int i = (2* _letters_guessed.size()); i < 63; i++) {
		std::cout << " ";
	}
	std::cout << "|" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "| ";
	for (int i = 0; i < m_password.size(); i++) {
		if (m_pass_check[i] == true)
			std::cout << m_password[i] << "  ";
		else std::cout << "_  ";
	}
	for (int i = (3 * m_password.size()); i < 80; i++) {
		std::cout << " ";
	}
	std::cout << "|" << std::endl;
	std::cout << "|                                                                                 |" << std::endl;
	std::cout << "+---------------------------------------------------------------------------------+" << std::endl;
	player_guess_letter();
}

void hangman::player_guess_letter() {
	std::cout << "  Guess a letter: ";
	std::string guess;
	std::getline(std::cin, guess);
	//std::cin.ignore();
	if (guess[0] == ' ') {
		std::cout << "Why did you put a space in your guess? There are no spaces in any of these words! Try again!" << std::endl;
		system("PAUSE");
		print_game_screen();
	}
	std::cout << std::endl << "You chose " << guess[0] << ". Is this correct? y/n" << std::endl;
	std::string confirm;
	std::getline(std::cin, confirm);
	if (confirm[0] != 'y' && confirm[0] != 'Y')	// used a NOT-AND-NOT here to keep the indentation flow nice and pretty!
		print_game_screen();
	for (int i = 0; i < _letters_guessed.size(); i++) {
		if (guess[0] == _letters_guessed[i]) {
			std::cout << "You already guessed that letter! Try a different one!" << std::endl;
			system("PAUSE");
			print_game_screen();
			break;
		}
	}
	bool guess_is_correct = false;
	for (int i = 0; i < m_password.size(); i++) {
		if (guess[0] == m_password[i]) {
			guess_is_correct = true;
			_letters_guessed.push_back(guess[0]);
			_last_guess = 1;
			m_pass_check[i] = true;
			int guesses_remaining = m_num_of_allowed_guesses - _letters_guessed.size();
			if (guesses_remaining > 0) {
				print_game_screen();
				break;
			}
		}
	}
}