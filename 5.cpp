#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream f("input.txt");
    string line;
    vector<string> lines;
    vector<stack<char> > towers;
    int columns = 9; // hard coded cuz i can!!
    int rows = 8;

    for (int i=0; i<columns; i++) { // initialize wack data structure
        stack<char> s;
        towers.push_back(s);
    }

    for (int i=0; i<rows; i++) {
        getline(f, line);
        lines.push_back(line);
    }
    
    for (int i=rows-1; i >= 0; i--) { // build towers
        line = lines.at(i);
        int it = 0;
        for (int j=1; j<=line.length()-1; j+=4) {
            char c = line.at(j);
            if (c != ' ') { towers.at(it).push(c); }
            it++;
        }
    }

    for (int i=0; i<2; i++) { getline(f, line); } // dont need these lines

    int amount, a, b;
    string dummy;
    stack<char> temp;
    while (f >> dummy >> amount >> dummy >> a >> dummy >> b) { // move payload
        a--;
        b--;
        for (int i=0; i<amount; i++) {
            char payload = towers.at(a).top();
            temp.push(payload);
            towers.at(a).pop();
        }
        for (int i=0; i<amount; i++) {
            char payload = temp.top();
            towers.at(b).push(payload);
            temp.pop();
        }
    }

    for (int i=0; i<columns; i++) { // result
        cout << towers.at(i).top();
    }
    cout << endl;
}