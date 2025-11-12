#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m, x;
	char a;
	scanf("%d%d", &n, &m);
	if (m == 1)
		cout << n;
	else {
		scanf("%s", &a);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
		}
		long long b = 1, c;
		for (int i = 0; i < m; i++) {
			b *= (n - i);
		}
		c = b % 998244353;
		cout << c;
	}
	return 0;
}
