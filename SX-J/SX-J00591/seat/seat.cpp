#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m, s[1000];
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];

		cout << s[i];
	}

	return 0;
}