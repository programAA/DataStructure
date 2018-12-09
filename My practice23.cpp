#include <iostream>
using namespace std;

int Move[4][2] = { 
{ 0,1 },//right  0
{ 1,0 },//down   1
{ 0,-1 },//left  2
{ -1,0 }//up     3
};
int mark[8][10] = { 
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 }
};
int maze[8][10] = {
{ 1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,1,1,0,1,0,1,1 },
{ 1,1,0,0,1,1,0,0,0,1 },
{ 1,0,0,0,0,0,0,1,1,1 },
{ 1,1,1,0,1,1,0,0,0,1 },
{ 1,0,0,0,0,0,1,0,1,1 },
{ 1,1,0,1,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1 }
};
int SeekPath(int x, int y) {
	int i;
	int row, col;
	if (x == 6 && y == 8) 
		return 1;
	for (i = 0; i < 4; i++) {
		row = x + Move[i][0];
		col = y + Move[i][1];
		if (maze[row][col] == 0 && mark[row][col] == 0) {
			mark[row][col] = 1;
			if (SeekPath(row, col)) {
				cout << '(' << row << ',' << col << ')' << endl;
				return 1;
			}
		}
	}
	return 0;
}


int main() {
	if (SeekPath(1, 1))
		cout << "OK" << endl;
	return 0;
}