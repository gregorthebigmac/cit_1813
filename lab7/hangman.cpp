/*
Yes, I overachieved on this one, but it wasn't terribly hard. I just grabbed the
standard Linux dictionary file (usually located in /usr/share/dict/words) and
copied it into the repo directory. After cleaning up words containing non-
English characters--for example:
Ångström, éclair, éclair's, éclairs
I put the "cropped" version into the git repo and use that for this program. The
way it works is at start, it grabs a random word from the dictionary file and
uses it as the word the player needs to guess. It allows the user 2 guesses for
every letter in the word, but caps out at 20 guesses. (for instance, if the word
has 5 letters, the player gets 10 guesses, but if the word has 11 letters, the
player gets 20 guesses instead of 22 because it caps at 20). Other than that, I
think the implementation is pretty straightforward.
*/

#include "random_word.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main() {
    random_word word("words");
    return 0;
}