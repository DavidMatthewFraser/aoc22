#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int getPriority(char c) 
{
    if (int(c) < 97) { return int(c) - 38; }
    return int(c) - 96;
}

string findDup(string a, string b) 
{
        set<char> seen;
        string dup = "";
        for (int j=0; j<a.length(); j++) { seen.insert(a.at(j)); }
        for (int j=0; j<b.length(); j++) 
            if (seen.find(b.at(j)) != seen.end()) { dup += b.at(j); }
        return dup;
}

int main() 
{
	ifstream f("input.txt");
    vector<string> lines;
    string line;
    int total = 0;
	while (getline(f, line)) { lines.push_back(line); }

    for (int i=0; i<lines.size() - 2; i+=3) {
        string d = findDup(lines.at(i), lines.at(i+1));
        d = findDup(d, lines.at(i+2));
        total += getPriority(d.at(0));
    }

    cout << total << endl;
}
