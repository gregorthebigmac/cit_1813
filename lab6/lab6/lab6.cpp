/*
You have been assigned to develop a new password system for our company.Here are steps for the user in your program(50 points).

1. The program first allows the user to enter a new password.The password must
	meet the requirements below before the program allows user to go to the next step.
2. After the new password is created, the program will ask if the user want to
	make change to the password or to exit the program.
3. If the user chooses to change the password, the old password will need to be
	entered first for verification before the new password can be created.
4. After that the user will enter the new password that must meet the requirements.
5. After the program accepts the new password, again the program will ask if
	the user want to make change to the password or to exit the program.

Password Requirements

1. Password must be at least 8 characters.
2. Password must contain at least one number.
3. Password must contain at least one special character.
4. Password must contain at least one letter of the alphabet.
5. Password must contain at least one uppercase letter.
6. Password must contain at least one lowercase letter.
7. Password must not contain a whitespace character such as a space, a tap (tab?), a newline character.
8. If the user modifies the old password, the new password must not be the same as the previous password.

*** Bonus 10 points *** 
Utilizing header file(the main function will call other functions that are stored in the header file).

*** Tip: Related example : The Create Account Program(pages 226 - 229) ***
*/
#include "pch.h"
#include <iostream>
#include "password.h"

using std::cout;
using std::endl;
using std::string;

password pw;

void password_creation();
void user_decision();

int main() {
	password_creation();
	return 0;
}

void password_creation() {
	cout << "****************************" << endl
		 << "**********Password**********" << endl
		 << "****************************" << endl << endl;
	cout << "All passwords must conform to the following standards:" << endl;
	cout << "1. Passwords must be at least 8 characters in length." << endl;
	cout << "2. Passwords must contain at least 1 number." << endl;
	cout << "3. Passwords must contain at least one special character:" << endl;
	cout << "   ex: ( ) [ ] - _ + = ! @ # $ % ^ & * ; : ' \" < > , . ~ `" << endl;
	cout << "4. Passwords must contain at least one uppercase letter." << endl;
	cout << "5. Passwords must contain at least one lowercase letter." << endl;
	cout << "6. Passwords may NOT contain the following:" << endl
		 << "     a whitespace character (i.e. the SPACEBAR key)" << endl
		 << "     a newline character (i.e. pressing the RETURN key)" << endl
		 << "     a tab character (i.e. pressing the TAB key)" << endl;
	cout << "7. You may NOT reuse any old passwords. Every time you create a" << endl
		 << "     new password, it must be unique." << endl << endl;
	cout << "Please enter a new password:" << endl;
	string temp_password;
	std::getline(std::cin, temp_password);
	pw.set_first_temp_password(temp_password);
	cout << "Please enter your password again:" << endl;
	std::getline(std::cin, temp_password);
	pw.set_second_temp_password(temp_password);
	cout << "validating password..." << endl;

	int pw_status = -1;
	pw_status = pw.is_password_valid();
	if (pw_status == 0) {
		pw.store_valid_password();
		cout << "Your password has been set." << endl << endl;
		user_decision();
	}
	else if (pw_status == 1) {
		cout << "Sorry, but your passwords do not match. Try again." << endl << endl;
		password_creation();
	}
	else if (pw_status == 2) {
		cout << "Sorry, but you already used that password. Please enter a *new* password." << endl << endl;
		password_creation();
	}
	else if (pw_status == 3) {
		cout << "Sorry, but passwords must be at least 8 characters in length." << endl << endl;
		password_creation();
	}
	else if (pw_status == 4) {
		cout << "Sorry, but passwords must contain at least one number." << endl << endl;
		password_creation();
	}
	else if (pw_status == 5) {
		cout << "Sorry, but passwords must contain at least one letter." << endl << endl;
		password_creation();
	}
	else if (pw_status == 6) {
		cout << "Sorry, but passwords must contain at least one upper case and one lower case letter." << endl << endl;
		password_creation();
	}
	else if (pw_status == 7) {
		cout << "Sorry, but passwords must contain at least one upper case and one lower case letter." << endl << endl;
		password_creation();
	}
	else if (pw_status == 8) {
		cout << "Sorry, but passwords must contain at least one special character." << endl << endl;
		password_creation();
	}
	else if (pw_status == 9) {
		cout << "Sorry, but passwords cannot contain any spaces or control characters." << endl << endl;
		password_creation();
	}
	else {
		cout << "I don't know what you did, but somehow you broke me. Try again." << endl << endl;
		password_creation();
	}
}

void user_decision() {
	string change_or_quit;
	cout << "Would you like to change your password [c] or quit [q]?" << endl;
	std::getline(std::cin, change_or_quit);
	if (change_or_quit[0] == 'c' || change_or_quit[0] == 'C') {
		cout << "Before you can change your password, you must enter your password to verify" << endl
			 << "your account. Please enter your current password:" << endl;
		string password_attempt;
		std::getline(std::cin, password_attempt);
		if (pw.verify_password_entry(password_attempt)) {
			cout << "Password confirmed." << endl << endl;
			password_creation();
		}
		else {
			cout << "Sorry, your password could not be verified." << endl;
			user_decision();
		}
	}
	else if (change_or_quit[0] == 'q' || change_or_quit[0] == 'Q')
		cout << "Goodbye!" << endl;
	else {
		cout << "That wasn't a 'c' or 'C' or 'q' or 'Q' and those are the only options I gave you. Try again." << endl;
		user_decision();
	}
}
