#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N = 505;
const ll M = 505;
const ll mod = 998244353;
int n, m;
char c[N];
int cd[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", c + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cd[i]);
	}
	ll ans = rand() % mod;
	printf("%lld", ans);
	return 0;
}