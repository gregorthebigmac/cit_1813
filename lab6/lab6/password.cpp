#include "pch.h"
#include "password.h"

bool password::_new_password_matches_any_old_passwords() {
	for (int i = 0; i < m_old_passwords.size(); i++) {
		if (m_temp_passwords[0] == m_old_passwords[i])
			return true;
	}
	return false;
}

bool password::_check_length(std::string temp_pass) {
	if (m_temp_passwords[0].size() < 8)
		return false;
	else { return true; }
}

bool password::_contains_number(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isdigit(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::_contains_letter(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isalpha(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::_contains_upper_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (isupper(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::_contains_lower_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (islower(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::_contains_special_char(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (ispunct(temp_pass[i]))
			return true;
	}
	return false;
}

bool password::_contains_no_bad_chars(std::string temp_pass) {
	for (int i = 0; i < temp_pass.size(); i++) {
		if (!isprint(temp_pass[i]))
			return false;
		if (isspace(temp_pass[i]))
			return false;
	}
	return true;
}

int password::is_password_valid() {
	std::string temp_pass = m_temp_passwords[0];
	if (!_temp_passwords_match())
		return 1;
	if (_new_password_matches_any_old_passwords()) // this is the only one where "TRUE" is bad
		return 2;
	if (!_check_length(temp_pass))
		return 3;
	if (!_contains_number(temp_pass))
		return 4;
	if (!_contains_letter(temp_pass))
		return 5;
	if (!_contains_upper_char(temp_pass))
		return 6;
	if (!_contains_lower_char(temp_pass))
		return 7;
	if (!_contains_special_char(temp_pass))
		return 8;
	if (!_contains_no_bad_chars(temp_pass))
		return 9;
	return 0;
}

void password::store_valid_password() {
	m_password = m_temp_passwords[0];
	// this is acceptable because at this point, we have already stored the validated password, and
	// therefore it will never be valid again if the user decides to change it. Waiting until the
	// user decides to change the password to store it in old_passwords (I believe) is only inviting
	// errors to occur, as the program will be entering a state of validating the password if/when
	// the user decides to change it.
	m_old_passwords.push_back(m_password);
	m_temp_passwords.clear();
	_populate_temp_passwords();
}

void password::_populate_temp_passwords() {
	m_temp_passwords.resize(2);
	m_temp_passwords[0] = ("0");
	m_temp_passwords[1] = ("1");
}