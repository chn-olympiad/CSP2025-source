#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int N2 = 5e6 + 10;
const int p = 131;
int n, m, hsh[N], pw[N], hsh2[N];
string s[N][2];
map<pair<int, int>, int> mp;
inline int gethsh(int *hsh, int l, int r) {
	return (hsh[r] - hsh[l - 1] * pw[r - l + 1] % mod + mod) % mod;
}
inline void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	int l = 1, r = s1.size();
	int len = r;
	s1 = ' ' + s1, s2 = ' ' + s2;
	for(int i = 1; i <= len; i ++) hsh[i] = (hsh[i - 1] * p + s1[i] - 'a' + 1) % mod;
	for(int i = 1; i <= len; i ++)
		hsh2[i] = (hsh2[i - 1] * p + s2[i] - 'a' + 1) % mod;
	for(int i = 1; i <= len; i ++)if(s1[i] != s2[i]) {
			l = i;
			break;
		}
	for(int i = len; i >= 1; i --)if(s1[i] != s2[i]) {
			r = i;
			break;
		}
	int ans = 0;
	for(int i = 1; i <= l; i ++) {
		for(int j = r; j <= len; j ++) {
			ans += mp[ {gethsh(hsh, i, j), gethsh(hsh2, i, j)}];
		}
	}
	cout << ans << '\n';
}
inline int gethsh(string s) {
	int num = 0;
	for(int i = 0; i < s.size(); i ++)num = (num * p + s[i] - 'a' + 1) % mod;
	return num;
}
inline bool check(string s) {
	int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < s.size(); i ++) {
		cnt1 += s[i] == 'a';
		cnt2 += s[i] == 'b';
	}
	return cnt1 + cnt2 == s.size() && cnt2 == 1;
}
namespace Sol1 {
	int cnt[N2 * 2];
	inline int getpos(string s) {
		for(int i = 0;i < s.size();i ++)if(s[i] == 'b')return i;
	}
	inline void solve() {
		for(int i = 1; i <= n;i ++){
			int p1 = getpos(s[i][0]), p2 = getpos(s[i][1]);
			cnt[p1 - p2 + N2] ++;
		}
		while(m --) {
			string s1, s2;
			cin >> s1 >> s2;
			cout << cnt[getpos(s1) - getpos(s2) + N2] << '\n';
		} 
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	pw[0] = 1;
	for(int i = 1; i < N; i ++)pw[i] = pw[i - 1] * p % mod;
	int flag = 1;
	for(int i = 1; i <= n; i ++) {
		cin >> s[i][0] >> s[i][1];
		flag &= check(s[i][0]) && check(s[i][1]);
		mp[ {gethsh(s[i][0]), gethsh(s[i][1])}] ++;
	}
	if(flag) {
		Sol1 :: solve();
		return 0;
	}
	while(m --) {
		solve();
	}
	return 0;
}
