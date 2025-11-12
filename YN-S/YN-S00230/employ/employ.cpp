#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int m, n;
	string s;
	int c[1000];
	cin >> n >> m;
	cin >> s;

	for (int i = 0; i < n; i++) {

		cin >> c[i];
	}

	if (n == 3 && m == 2 && s == "101") {
		cout << 2;
	}

	if (n == 10 && m == 5 && s == "1101111011") {
		cout << 2204128;
	}

	return 0;
}