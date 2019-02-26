// No lazy coding here! Even if it lengthens the code significantly and is a bit more tedious, I
// would rather have clear, compartmentalized code that's easy to read and modify, rather than
// making some new guy spend hours trying to decypher what you did after you're gone! It also
// significantly cuts down on how much you need to comment when you simply give methods and vars
// meaningful names and keep your code blocks short, sweet, and compartmentalized!
// Also, this code is designed to be *fast* because it fails as soon as it encounters a single
// failure point, rather than testing everything even after encountering a failure.

#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>

class password {
public:
	password();
	~password();

	// check for valid password
	bool temp_passwords_match() { return (m_temp_passwords[0] == m_temp_passwords[1]); }
	bool new_password_matches_any_old_passwords();
	bool check_length(std::string temp_pass);
	bool contains_number(std::string temp_pass);
	bool contains_letter(std::string temp_pass);
	bool contains_upper_char(std::string temp_pass);
	bool contains_lower_char(std::string temp_pass);
	bool contains_special_char(std::string temp_pass);
	bool contains_no_bad_chars(std::string temp_pass);
	bool is_password_valid();
	bool verify_password_entry(std::string password) { return (password == m_password); }

	// setters
	void set_first_temp_password(std::string pass1) { m_temp_passwords[0] = pass1; }
	void set_second_temp_password(std::string pass2) { m_temp_passwords[1] = pass2; }

private:
	void _store_valid_password();
	std::string m_password;	// password is stored here once it passes validity checks and confirms they match.
	std::vector<std::string> m_temp_passwords; // used for storing the password before validity checks and to make sure they match.
	std::vector<std::string> m_old_passwords;	// old valid passwords stored here
};
