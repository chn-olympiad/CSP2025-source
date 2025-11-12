#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e6 + 100;
const int base = 233;
const int Mod = 1e11 + 79;
struct node { int l, r, h; };
map<int, vector<node>> f;
int n, q, len, hsh[N], B[N];
string s, t;
inline int Hsh(int l, int r, int op) {
	int res = 0;
	for(int i = l; i <= r; ++i) res = (res * base + s[i]) % Mod;
	if(op) for(int i = l; i <= r; ++i) res = (res * base + t[i]) % Mod;
	return res;
}
inline int calc(int h, int l, int r) {
	if(r > len || l < 1) return 0;
	int H = (hsh[r] - (__int128)hsh[l - 1] * B[r - l + 1] % Mod);
	H = (H % Mod + Mod) % Mod;
//	cout << "chk" << h << ' ' << H << '\n';
	return h == H;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w",stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	B[0] = 1;
	for(int i = 1; i <= 5e6; ++i) B[i] = B[i - 1] * base % Mod;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) {
		cin >> s >> t;
		if(s == t) continue;
		len = s.size();
		int l = 0, r = len - 1;
		for(int i = 0; i < len; ++i) if(s[i] != t[i]) { l = i; break; }
		for(int i = len - 1; ~i; --i) if(s[i] != t[i]) { r = i; break; }
		int h1 = Hsh(l, r, 1);
		int h2 = Hsh(0, s.size() - 1, 0);
		f[h1].push_back({l, len - 1 - r, h2});
	}
	while(q--) {
		cin >> s >> t;
		int ans = 0;
		len = s.size();
		int l = 0, r = len - 1;
		for(int i = 0; i < len; ++i) if(s[i] != t[i]) { l = i; break; }
		for(int i = len - 1; ~i; --i) if(s[i] != t[i]) { r = i; break; }
		for(int i = 1; i <= len; ++i) hsh[i] = (hsh[i - 1] * base + s[i - 1]) % Mod;
		int h1 = Hsh(l, r, 1);
		for(auto e : f[h1]) ans += calc(e.h, l + 1 - e.l, r + 1 + e.r);
		cout << ans << '\n';
	}
	return 0;
}