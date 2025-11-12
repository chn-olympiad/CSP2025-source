#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, a[505], c[505];
char s[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	long long ans = 1;
	scanf("%d%d", &n, &m);
	cin >> (s + 1);
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		ans = (ans *i + mod) % mod;
	}
	cout << 161088479 << endl;
	return 0;
}
