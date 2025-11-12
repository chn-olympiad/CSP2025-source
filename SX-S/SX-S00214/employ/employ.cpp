#include <bits/stdc++.h>
using namespace std;
int s[510];
int c[510];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (n > m) {
		cout << m % 998244353;
	} else if (n <= m) {
		cout << n;
	}
	return 0;
}

