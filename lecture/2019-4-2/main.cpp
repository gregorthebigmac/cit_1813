#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class movie {
public:
    movie();
    ~movie();

    void get_movie();
    void get_year();
    
private:
    string title;
    int year;
};

int main() {
    cout << "Movie = " << endl;
    cout << "Year = " << endl;
    return 0;
}

void movie::get_movie() {
    std::cout << title << endl;
}

void movie::get_year() {
    std::cout << year << endl;
}