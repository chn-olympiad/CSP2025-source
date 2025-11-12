#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	unordered_map<int, bool> mp;
	int yh = 0, res = 0;
	for(int i = 1; i <= n; i++) {
		yh ^= a[i];
		if(yh == k) {
			res++;
			yh = 0;
			mp.clear();
		} else {
			if(mp[k ^ yh]) {
				yh = 0;
				res++;
				mp.clear();
			} else {
				mp[yh] = 1;
			}
		}
	}
	cout << res;
	return 0;
} // Easy