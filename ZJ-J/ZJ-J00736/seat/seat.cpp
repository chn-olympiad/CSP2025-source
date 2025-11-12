#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, a[110], a_r, cnt, rn, rm;
bool c[110];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n*m; i++) {
		scanf("%lld", &a[i]);
		c[a[i]] = 1;
	}
	for (ll i = 100; i >= a[1]; i--) {
		if (c[i]) cnt++;
	}
	rm = (cnt+n-1) / n, rn = cnt % n;
	if (rn == 0) rn = n;
	if (rm % 2 == 0) rn = n - rn + 1;
	printf("%lld %lld", rm, rn);
	return 0;
}
