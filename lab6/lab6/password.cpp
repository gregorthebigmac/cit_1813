#include "pch.h"
#include "password.h"


password::password() {}
password::~password(){}

bool password::new_password_matches_any_old_passwords() {
	for (int i = 0; i < m_old_passwords.size(); i++) {
		if (m_temp_passwords[0] == m_old_passwords[i])
			return true;
	}
	return false;
}

bool password::check_length(std::string temp_pass) {
	if (m_temp_passwords[0].size() < 8)
		return false;
	else { return true; }
}

bool password::contains_number(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isdigit(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::contains_letter(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isalpha(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::contains_upper_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isupper(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::contains_lower_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (islower(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::contains_special_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (ispunct(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::contains_no_bad_chars(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (!isprint(temp_pass[i]))
			return false;
		if (isspace(temp_pass[i]))
			return false;
	}
	return true;
}

bool password::is_password_valid() {
	std::string temp_pass = m_temp_passwords[0];
	if (!temp_passwords_match()) {
		std::cout << "Sorry, but your passwords do not match. Try again." << std::endl;
		return false;
	}
	if (!new_password_matches_any_old_passwords()) {
		std::cout << "Sorry, but you already used that password. Please enter a *new* password." << std::endl;
		return false;
	}
	if (!check_length(temp_pass)) {
		std::cout << "Sorry, but passwords must be at least 8 characters in length." << std::endl;
		return false;
	}
	if (!contains_number(temp_pass)) {
		std::cout << "Sorry, but passwords must contain at least one number." << std::endl;
		return false;
	}
	if (!contains_letter(temp_pass)) {
		std::cout << "Sorry, but passwords must contain at least one letter." << std::endl;
		return false;
	}
	if (!contains_upper_char(temp_pass)) {
		std::cout << "Sorry, but passwords must contain at least one upper case and one lower case letter." << std::endl;
		return false;
	}
	if (!contains_lower_char(temp_pass)) {
		std::cout << "Sorry, but passwords must contain at least one upper case and one lower case letter." << std::endl;
		return false;
	}
	if (!contains_special_char(temp_pass)) {
		std::cout << "Sorry, but passwords must contain at least one special character." << std::endl;
		return false;
	}
	if (!contains_no_bad_chars(temp_pass)) {
		std::cout << "Sorry, but passwords cannot contain any spaces or control characters." << std::endl;
		return false;
	}
	return true;
}

void password::_store_valid_password() {
	m_password = m_temp_passwords[0];
	// this is acceptable because at this point, we have already stored the validated password, and
	// therefore it will never be valid again if the user decides to change it. Waiting until the
	// user decides to change the password to store it in old_passwords (I believe) is only inviting
	// errors to occur, as the program will be entering a state of validating the password if/when
	// the user decides to change it.
	m_old_passwords.push_back(m_password);
	m_temp_passwords.clear();
}
