#include <iostream>
#include <fstream>

using namespace std;

int result(char a, char b) 
{
    /* rock, paper, scissors => 1, 2, 3
       loose, tie, win => 1, 2, 3 */
    int you = int(a) - 64;
    int res = int(b) - 87;
    int moves[3] = {1,2,3};
    int move, diff;

    /* [rock, paper, scissors], 
       looses to next element, wins against previous element */
    if (res == 1) {move = moves[(you+1)%3];}
    if (res == 2) {move = moves[you-1];}
    if (res == 3) {move = moves[you%3];}
    
    diff = (you - move);

    /* win cases: 1-2=-1, 2-3=-1, 3-1=2
       -1 is odd and negative, 2 is even and positive */
    /* loose cases: 2-1=1, 3-2=1, 1-3=-2 
       1 is odd positive, -2 is even negative */
    if (diff == 0) { return 3 + move; }
    if (((diff)%2 == 0) == (diff > 0)) { return 6 + move; }
    return 0 + move;


}

int main() 
{
	ifstream f("input.txt");
    int total = 0;
	char c, c2;

	while (f >> c >> c2) { total += result(c, c2); }
    cout << total << endl;
}
