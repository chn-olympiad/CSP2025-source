#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 2e6 + 10;
int n, k, a[N], sum[N], lst[N], ans;

signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;++ i) cin >> a[i], sum[i] = (sum[i - 1] ^ a[i]);
	memset(lst, -1, sizeof(lst));
	int r = 0;
	sum[0] = k;
	lst[k] = 0;
	for(int i = 1;i <= n;++ i){
		if(lst[sum[i]] != -1) {
			if(lst[sum[i]] >= r) {
				ans++;
				r = i;
			}
		}
		sum[i] ^= k;
		lst[sum[i]] = i;
	}
	cout << ans;
	return 0;
}