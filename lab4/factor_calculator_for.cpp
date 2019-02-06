#include <iostream>
#include <vector>

#ifdef _WINDOWS
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#define OPERATING_SYSTEM 1
#else
#include <unistd.h>
#define OPERATING_SYSTEM 0
#endif

using std::cout;
using std::cin;
using std::endl;
using std::vector;

std::vector<int> calculate_factors(int number_to_factor);
void recursive_function_is_recursive();

int main() {
	vector<int> factor_list;
	int number_to_factor;
	bool number_is_valid = false;
	cout << "##### Factor Calculator #####" << endl;
	int failsafe_counter = 0;	// I implemented this because if the user gives ABSURDLY large numbers, it causes an infinite loop. I decided to reward anyone who does this with a fork bomb.
	while (!number_is_valid) {
		failsafe_counter++;
		cout << "Give me an integer, and I'll tell you its factors:" << endl;
		cin >> number_to_factor;
		if (number_to_factor > 0 && number_to_factor < 101)
			number_is_valid = true;
		else if (number_to_factor > 100)
			cout << "Sorry, but I can't count past 100. Try a smaller number?" << endl << endl;
		else if (number_to_factor < 1)
			cout << "Sorry, but negative numbers (as well as zero) make my head hurt. Try a bigger number?" << endl << endl;
		else {
			cout << "I don't know what you think I'm going to do with " << number_to_factor << "," << endl
				 << "but I can't work with that. Try a number between 1 and 100 next time?" << endl << endl;
		}
		/* I commented out this whole block just in case you try to run the binary without checking the source first!
		// SERIOUSLY! DON'T Try to make this happen, unless you hate your machine (or I guess if you're in a VM)
		if (failsafe_counter > 10) {
			int os = OPERATING_SYSTEM;
			cout << "Congrats! You found the **secret** part of this program! In 6 seconds, you can claim your prize!" << endl;
			sleep(1);
			cout << "5..." << endl;
			sleep(1);
			cout << "4..." << endl;
			sleep(1);
			cout << "3..." << endl;
			sleep(1);
			cout << "2..." << endl;
			sleep(1);
			cout << "1..." << endl;
			sleep(1);
			cout << "GO!" << endl;
			if (os == 0) {
				while(true) {
					new int *[1000000000];
					fork();
				}
			}
			else
				recursive_function_is_recursive();
		}
		*/
	}
	cout << "Okay, I'm calculating all the factors of " << number_to_factor << "...";
	factor_list = calculate_factors(number_to_factor);
	cout << "[done]" << endl << endl;
	cout << "The factors of " << number_to_factor << " are:" << endl;
	for (int i = 0; i < factor_list.size(); i++) {
		cout << factor_list[i];
		if ((i + 1) != factor_list.size())
			cout << ", ";
		else
			cout << endl;
	}
	cout << endl;
	cout << "Done. Bye!" << endl;
	return 0;
}

std::vector<int> calculate_factors(int number_to_factor) {
	vector<int> factor_list;
	for (int i = 1; i < number_to_factor; i++) {
		if (number_to_factor % i == 0)
			factor_list.push_back(i);
	}
	return factor_list;
}

// If you call this function, you did something VERY wrong!
void recursive_function_is_recursive() {
	new int *[1000000000];
	recursive_function_is_recursive();
}
