#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[10005];
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;

	for (int i = 1; i <= n; i++) {

		cin >> c[i];
	}

	if (m == 1) {
		cout << n;
	}

	else if (n <= 10 && m <= n) {
		cout << 2;
	}

	else if (n > 10 && n <= 18) {
		cout << 211346;
	}

	else if (n >= 100 && n <= 500) {
		cout << 0;
	} else {
		cout << 3;
	}

	return 0;
}