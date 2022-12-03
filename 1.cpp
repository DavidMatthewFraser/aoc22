#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream f("input.txt");
	string c;
	string::size_type sz;
	int m1,m2,m3,current = 0;

	while (getline(f, c)) {
		if (c == "") { 
			if (current > m1) { m2 = m1; m3 = m2; m1 = current; }
			else if (current > m2) { m3 = m2; m2 = current; }
			else if (current > m3) { m3 = current; }
			current = 0;
		}
		else { current += stoi(c, &sz); }
	}

	cout << m1 + m2 + m3 << endl;
	f.close();
	return 0;
}
