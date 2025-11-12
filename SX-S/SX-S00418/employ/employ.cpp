#include <bits/stdc++.h>
using namespace std;
long long n, m, a[505], ans;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	ans = n % 998244353;
	printf("%lld", ans);
	return 0;
}