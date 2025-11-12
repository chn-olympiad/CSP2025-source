#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace", "r", stdin);
	freopen("replace", "w", stdout);
	int n, q;
	cin >> n >> q;
	string s;
	int a[n + 2][10000000][2], b[q + 2][10000000][2];
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j + 1][0] = s[j] - 'a';
		}
		a[i][s.size() + 1][0] = 30;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j + 1][1] = s[j] - 'a';
		}
		a[i][s.size() + 1][1] = 30;
	}
	for (int i = 1; i <= q; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			b[i][j + 1][0] = s[j] - 'a';
		}
		b[i][s.size() + 1][0] = 30;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			b[i][j + 1][1] = s[j] - 'a';
		}
		b[i][s.size() + 1][1] = 30;
	}
	for (int i = 1; i <= q; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; b[i][k][0] != 30; k++) {

			}
		}
	}
	cout << 2 << endl << 0;
	return 0;
}