#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ifstream f("test.txt");
	char c;
    vector<char> cs;

	while (f >> c) { cs.push_back(c); }

    for (int i=0; i<cs.size(); i++) { 
        set<char> s;
        for (int j=0; j<14; j++) {
            s.insert(cs.at(i+j));
        }
        if (s.size() == 14) { cout << i + 14 << endl; break; }
    }

    return 0;
}
