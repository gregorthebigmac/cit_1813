/*
Yes, I overachieved on this one, but it wasn't terribly hard, although I will admit
it wound up being a lot more time-consuming than I thought it would be, lol. You may
have noticed my coding style has changed a bit since last time. I recently stumbled
across the Linux Kernel C coding convention as established by Linus Torvalds, and I
was surprised I already did a lot of what he says you should do, but there were some
differences, and I've decided to try them out for this project. Apologies in advance
if it makes it more difficult for you to read.
As for the project code itself, I just grabbed the standard Linux dictionary file
(usually located in /usr/share/dict/words) and copied it into the repo directory.
I removed words containing non-English characters (or even words containing
punctuation, like apostrophes--for example:
Ångström, éclair, éclair's, éclairs
I put the new cleaned up version of this file into the git repo and use that for
this program. The way it works is at start, it asks the user for the length of the
word they want to guess, then chooses a random word of that length from the list.
Then it asks the user how many guesses they want (max: 20). The more guesses they
*allow* for, the lower their score will be. The fewer guesses they *use* (assuming
they correctly guess the word), the higher their score will be.
*/
#include "hangman.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


int main() {
	bool play_again = true;
	while (play_again) {
		hangman *game = NULL;
		game = new hangman;

		game->play();
		delete game;
		
		cout << "That was fun! Play again? y/n" << endl;
		string choice;
		getline(cin, choice);
		if (choice[0] == 'y' || choice[0] == 'Y') {
			play_again = true; }
		else {
			cout << "Thanks for playing! Bye!" << endl;
			play_again = false;
		}
	}
	return 0;
}
