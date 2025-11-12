#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+10;
ll n, q;
string s1[N], s2[N], t1[N], t2[N];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%lld%lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> t1[i] >> t2[i];
	}
	for (int i = 1; i <= q; i++) {
		ll ans = 0;
		for (int j = 1; j <= n; j++) {
			if (s1[j] == t1[i])
				ans += 1;
			if (s2[j] == t2[i])
				ans += 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}