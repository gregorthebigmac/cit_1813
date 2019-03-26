/*
Yes, I overachieved on this one, but it wasn't terribly hard. I just grabbed the
standard Linux dictionary file (usually located in /usr/share/dict/words) and
copied it into the repo directory. After cleaning up words containing non-
English characters--for example:
Ångström, éclair, éclair's, éclairs
I put the "cropped" version into the git repo and use that for this program. The
way it works is at start, it asks the user for the length of the word they want to
guess, then chooses a random word of that length from the list. Then it asks the
user how many guesses they want (max: 20). The more guesses they *allow* for, the
lower their score will be. The fewer guesses they *use* (assuming they correctly
guess the word), the higher their score will be.
*/
#include "pch.h"
#include "hangman.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

hangman game;

int main() {
	game.play();
	cout << "That was fun! Play again? y/n" << endl;
	string play_again;
	getline(cin, play_again);
	if (play_again[0] == 'y' || play_again[0] == 'Y') {
		game.play(); }
	else { cout << "Thanks for playing! Bye!" << endl; }
	return 0;
}
