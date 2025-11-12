#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
#define per(i, r, l) for(int i = r; i >= l; --i)
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], f[N];
map<int, int> mp;
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], a[i] ^= a[i - 1];
	mp[0] = 0;
	rep(i, 1, n){
		f[i] = f[i - 1];
		if (mp.count(a[i] ^ k))
			f[i] = max(f[i], f[mp[a[i] ^ k]] + 1);
//		if (a[i] == k)
//			f[i] = max(f[i], f[i - 1] + 1);
		mp[a[i]] = i;
	}
	cout << f[n] << '\n';
	return 0;
}

