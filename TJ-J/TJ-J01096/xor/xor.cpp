#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
struct range {int l, r;};
bool cmp(range a, range b) {
	if (a.l != b.l) return a.l < b.l;
	return a.r < b.r;
}
ll a[500005];
ll x[500005];
ll dp[500005];
vector<range> rg;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		x[i] = x[i - 1] ^ a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			ll sum = x[j] ^ x[i - 1];
			if (sum == k) rg.push_back({i, j});
		}
	sort(rg.begin(), rg.end(), cmp);
	for (int i = 0; i < rg.size(); i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
			if (rg[j].r < rg[i].l)
				dp[i] = max(dp[i], dp[j] + 1);
	}
	printf("%lld", dp[rg.size() - 1]);
	return 0;
}

