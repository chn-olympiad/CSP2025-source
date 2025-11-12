#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
int n, m;
string s;
ll ans;
ll a = 1, b = 1, c = 1;

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	scanf("%d %d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
	}
	if (m == 1) {
		printf("%d", n);
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		a = (a * i) % mod;
	}
	for (int i = 1; i <= n; i++) {
		b = (b * i) % mod;
	}
	for (int i = 1; i <= (m - n); i++) {
		c = (c * i) % mod;
	}
	ans = (a / b * c) % mod;
	printf("%lld", ans);

	return 0;
}
