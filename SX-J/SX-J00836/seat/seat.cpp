#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int c[a * b];
	for (int i = 0; i < a * b; i++) {
		cin >> c[i];
	}
	int mmm = c[0];
	sort(c, c + (a *b), cmp);

	int d[a][b], x = -1, y = 0, z = 0;
	for (int j = 0; j < a; j++) {
		for (int i = 0; i < b; i++) {
			if (x == a - 1 && y == 0 || x == 0 && y == 1) {
				y++;
				//x++;
				//cout << "/";
			}

			else if (y % 2 == 1) {
				x--;
				//cout << "?";
			} else if (y % 2 == 0) {
				x++;
				//cout << "#";
			}
			if (c[z++] == mmm) {
				cout << y + 1 << " " << x + 1;
				break;
			}
			//cout << x << " " << y << "\n";    //3 3 1 2 3 4 5 6 7 8 9
		}
	}
	//cout << "\n";


	return 0;
}
