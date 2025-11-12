#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, t = 0, w = 1, d = 1;

int main() {
//	freopen("number.in", "r", stdin);
//	freopen("number.out", "w", stdout);
	cin >> n >> m;
	int s[n * m];
	for (int i = 1; i <= n * m ; i++) {
		cin >> s[i];
	}
	a = s[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = 1; j <= n * m; j++) {
			if (s[j] < s[j + 1]) {
				swap(s[j], s[j + 1]);
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		if (a == s[i]) {
			b = i;
			break;
		}
	}
	if (n != 1) {
		for (int i = 1; i < b; i++) {
			if (w != n && d % 2 != 0)
				w++;
			else if (d % 2 == 0 && w > 1)
				w--;
			else if (w == n || w == 1 && d % 2 == 0)
				d++;
		}
	} else {
		for (int i = 1; i < b; i++)
			w++;
	}
	cout << d << " " << w;
	return 0;
}