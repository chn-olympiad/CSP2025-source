#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, a[5010], ans, num[5010], cnt = 0;
void dfs(int bi, int depth, int li) {
	if (depth > bi) {
		ll sum = 0, maxx = 0;
		for (ll i = 1; i <= bi; i++) {
			sum += num[i];
			maxx = max(maxx, num[i]);
		}
		if (sum > maxx*2) ans++;
		ans %= 998244353;
		return ;
	}
	for (ll i = li+1; i <= n-bi+depth; i++) {
		num[depth] = a[i];
		dfs(bi, depth+1, i);
		num[depth] = 0;
	}
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (ll i = 3; i <= n; i++) {
		dfs(i, 1, 0);
	}
	printf("%lld", ans%998244353);
	return 0;
}
