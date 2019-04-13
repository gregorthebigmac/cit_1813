#include <iostream>
#include <string>

using namespace std;

struct student {
public:
	int id;
	string firstname;
	string lastname;

	int get_id() { return id; }
	string get_firstname() { return firstname; }
	string get_lastname() { return lastname; }
	
	void set_id(int arg_id) { id = arg_id; }
	void set_first_name(string first_name) { firstname = first_name; }
	void set_last_name(string last_name) { lastname = last_name; }

	bool is_equal(student a, student b) {
		if (a.get_id() == b.get_id()) {
			string temp_a = a.get_firstname();
			string temp_b = b.get_firstname();
			if (temp_a.compare(temp_b) == 0) {
				temp_a = a.get_lastname();
				temp_b = b.get_lastname();
				if (temp_a.compare(temp_b) == 0) {
					return true;
				}
				else return false;
			}
			else return false;
		}
		else return false;
	}
};


int main() {
	student s1, s2;
	s1.set_id(12345);
	s1.set_first_name("John");
	s1.set_last_name("Dole");
	s2.set_id(12346);
	s2.set_first_name("Jane");
	s2.set_last_name("Dole");
	if (s1.is_equal(s1, s2)) {
		cout << s1.get_firstname() << " " << s1.get_lastname() << " is equal to "
			 << s2.get_firstname() << " " << s2.get_lastname() << "." << endl;
	}
	else cout << "They are not the same!" << endl;
	return 0;
}
