#include <bits/stdc++.h>
using namespace std;
int c[515];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, p = 0;
	long long k = 1;
	string s;
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			p++;
		}
	}
	if (p == n) {
		for (int i = 1; i <= n; i++) {
			k *= i;
			k = k % 998244353;
		}
	}
	cout << k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
