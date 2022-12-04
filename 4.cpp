#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
    ifstream f("test.txt");
    int total = 0;
    int a1, a2, b1, b2;
    char c;
    while (f >> a1 >> c >> a2 >> c >> b1 >> c >> b2) { 
        if ((a1 < b1 && a2 < b1) || (a1 > b1 && a1 > b2)) { continue; }
        total++;
    }
    cout << total << endl;
}