#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m, c = 0, r = 0, i, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	cin >> n >> m;
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9;
	for (i = 1; i < 2; i++) {
		if (a1 == 100 || a2 < 100 || a3 < 100 || a4 < 100)
			cout << c + 1 << " " << r + 1;
		else if ((a1 < 100 || a2 == 100 || a3 < 100 || a4 < 100) && (a2 > a1 || a1 > a3 || a3 > a4))
			cout << c + 1 << " " << r + 2;
		else if ((a1 < 100 || a2 == 100 || a3 < 100 || a4 < 100) && (a2 > a3 || a3 > a1 || a1 > a4))
			cout << c + 2 << " " << r + 1;
		else if ((a1 < 100 || a2 == 100 || a3 < 100 || a4 < 100) && (a2 > a4 || a4 > a3 || a3 > a1))
			cout << c + 2 << " " << r + 2;
		else if ((a1 < 100 || a2 < 100 || a3 == 100 || a4 < 100) && (a3 > a2 || a2 > a1 || a1 > a4))
			cout << c + 2 << " " << r + 1;
		else if ((a1 < 100 || a2 < 100 || a3 == 100 || a4 < 100) && (a3 > a1 || a1 > a2 || a2 > a4))
			cout << c + 1 << " " << r + 2;
		else if ((a1 < 100 || a2 < 100 || a3 == 100 || a4 < 100) && (a3 > a4 || a4 > a2 || a2 > a1))
			cout << c + 2 << " " << r + 2;
		else if ((a1 < 100 || a2 < 100 || a3 < 100 || a4 == 100) && (a4 > a3 || a3 > a2 || a2 > a1))
			cout << c + 2 << " " << r + 2;
		else if ((a1 < 100 || a2 < 100 || a3 < 100 || a4 == 100) && (a4 > a1 || a1 > a2 || a2 > a3))
			cout << c + 1 << " " << r + 2;
		else if ((a1 < 100 || a2 < 100 || a3 < 100 || a4 == 100) && (a4 > a3 || a3 > a1 || a1 > a2))
			cout << c + 2 << " " << r + 1;
		else if (a1 == 100 || a2 < 100 || a3 < 100 || a4 < 100 || a5 < 100 || a6 < 100 || a7 < 100 || a8 < 100 || a9 < 100)
			cout << c + 1 << " " << r + 1;
		else if ((a1 < 100 || a2 == 100 || a3 < 100 || a4 < 100 || a5 < 100 || a6 < 100 || a7 < 100 || a8 < 100 || a9 < 100)
		         && (a2 > a1 || a1 > a3 || a3 > a4 || a4 > a5 || a5 > a6 || a6 > a7 || a7 > a8 || a8 > a9))
			cout << c + 1 << " " << r + 2;
	}
	return 0;
}
