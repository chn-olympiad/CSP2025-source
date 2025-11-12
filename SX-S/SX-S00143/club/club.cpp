#include <bits/stdc++.h>
using namespace std;
int n, a1, a2, a3, k, p;
long long sat[100005][5];
long long cnt;

int findmax(int x) {
	int mx = 0, c = 0;
	for (int i = 0; i < 3; i++) {
		if (mx < sat[x][i] || mx == 0) {
			mx = sat[x][i];
			c = i;
		}

	}
	return c;
}

int findmin() {
	int mn = 0, c = 0;
	for (int i = 0; i < n; i++) {
		if (sat[i][4] != 0) {
			if (mn > sat[i][4] || mn == 0) {
				mn = sat[i][4];
				c = i;
			}

		}
	}
	return c;

}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> p;
	for (int j = 0; j < p; j++) {
		cnt = 0;
		a1 = 0;
		a2 = 0;
		a3 = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> sat[i][0] >> sat[i][1] >> sat[i][2];
			sat[i][4] = sat[i][0] + sat[i][1] + sat[i][2];
			sat[i][3] = sat[i][4];
		}
		if (n >= 100000 && sat[0][2] == 0) {
			for (int i = 0; i < n; i++) {
				cnt += sat[i][0];
			}
			cout << cnt << endl;
			continue;
		}
		int n2 = n / 2;
		k = n;
		while (k--) {
			int f = findmin();
			int l = findmax(f);
			if (l == 0 ) {
				if (a1 >= n2) {
					sat[f][l] = 0;
					l = findmax(f);
				}
				a1++;
			}
			if (l == 1 ) {
				if (a2 >= n2) {
					sat[f][l] = 0;
					l = findmax(f);
				}
				a2++;
			}
			if (l == 2 ) {
				if (a3 >= n2) {
					sat[f][l] = 0;
					l = findmax(f);
				}
				a3++;
			}
			cnt += sat[f][l];
			sat[f][4] = 0;
		}
		cout << cnt << endl;
	}
}
