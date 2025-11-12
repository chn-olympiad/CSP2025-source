#include <bits/stdc++.h>
using namespace std;
int c[505], n, m;
long long cnt;
string s;
const long long mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for (int x = m; x <= n; x++) {
		long long ans = 1;
		for (int i = n - x; i <= n; i++) {
			ans *= i;
			ans %= mod;
		}
		cnt += ans;
		cnt %= mod;
	}

	printf("%lld", cnt);
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
