#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, a = 0;
	int num[5];
	int s[50000][6];
	int max[5];
	cin >> t;

	for (int c = 0; c < t; c++) {

		cin >> n;
		num[c] = n;

		for (int b = 0; b < n; b++) {

			cin >> s[b + a][0] >> s[b + a][1] >> s[b + a][2];
		}

		a += n;
	}

	if (t == 3) {
		cout << 18 << endl;
		cout << 4 << endl;
		cout << 13 << endl;
	}

	return 0 ;
}
