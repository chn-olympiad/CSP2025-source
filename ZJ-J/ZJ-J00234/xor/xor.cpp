#include<bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int n, k, a[N];
bool vis[N];
inline int get(int l) {
	int num = 0;
	vis[0] = 1;
	for(int i = l; i <= n; i ++) {
		num ^= a[i];
		if(vis[num ^ k])return i;
		vis[num] = 1;
	}
	return n + 1;
}
inline void clear(int l, int r) {
	int num = 0;
	for(int i = l; i <= r; i ++) {
		num ^= a[i];
		vis[num] = 0;
	}
}
signed main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++)cin >> a[i];
	int ans = 0;
	for(int l = 1; l <= n; ) {
		int r = get(l);
		clear(l, r);
		if(r <= n) ans ++;
		l = r + 1;
	}
	cout << ans;
	return 0;
}
