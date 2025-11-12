#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5 * 1e5+10;
ll n, k;
ll a[N];
ll qzh[N];
ll cnt;
ll re;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1)
			qzh[i] = a[i];
		else
			qzh[i] = a[i] ^ qzh[i - 1];
	}
	re = 1;
	for (int l = 1; l <= n; l = re) {
		for (int r = l; r <= n; r++) {
			if ((qzh[r]^qzh[l - 1]) == k) {
				cnt++;
				re = r + 1;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}