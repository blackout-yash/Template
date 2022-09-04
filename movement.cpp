#include <bits/stdc++.h>

using namespace std;

int main() {

	// L Shape
	vector <vector <int>> lshape = {
		// up
		{ -1,  0, -1, -1},
		{ -1,  0, -1,  1},
		// down
		{  1,  0,  1, -1},
		{  1,  0,  1,  1},
		// left
		{  0, -1, -1, -1},
		{  0, -1,  1, -1},
		// right
		{  0,  1, -1,  1},
		{  0,  1,  1,  1}
	};

	int x = 1, y = 1;
	for (int i = 0; i < 8; i++) {
		int x1 = x, x2 = x + lshape[i][0], x3 = x + lshape[i][2];
		int y1 = y, y2 = y + lshape[i][1], y3 = y + lshape[i][3];

		cout << "(" << x1 << "," << y1 << "), ";
		cout << "(" << x2 << "," << y2 << "), ";
		cout << "(" << x3 << "," << y3 << ")";
		cout << endl;
	}


	return 0;
}