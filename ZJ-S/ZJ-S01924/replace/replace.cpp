#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define fi first
#define se second
#define mk_p make_pair
#define pii pair<int, int>
const int N = 200010, base = 1145141;
int n, q, m;
string sa[N], sb[N], ta, tb;
struct str {
	ull hpre, hmid, hsuf;
} H[N];
str chg(string &s, string &t) {
	str ans; ans.hmid = ans.hpre = ans.hsuf = 0;
	int n = s.length();
	int i, j;
	for(i = 0; i < n; i++) if(s[i] != t[i]) break;
	for(int o = i - 1; o >= 0; o--) ans.hpre = ans.hpre * base + s[o];
	for(j = n - 1; j >= 0; j--) if(s[j] != t[j]) break;
	for(int o = j + 1; o < n; o++) ans.hsuf = ans.hsuf * base + s[o];
	for(int o = i; o <= j; o++) {
//		cout << s[i];
		ans.hmid = ans.hmid * base + s[o];
		ans.hmid = ans.hmid * base + t[o];
	}
//	cout << '\n';
//	cout << "i = " << i << " j = " << j << ' ' << ans.hmid1 << ' ' << ans.hmid2 << '\n';
	return ans;
}
pii ask(string &s, string &t) {
	int n = s.length(); int i, j;
	for(i = 0; i < n; i++) if(s[i] != t[i]) break;
	for(j = n - 1; j >= 0; j--) if(s[j] != t[j]) break;
	return mk_p(i, j);
}
unordered_map<int, bool> mp1, mp2;
unordered_map<ull, vector<int> > v;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> sa[i] >> sb[i];
		H[i] = chg(sa[i], sb[i]);
		v[H[i].hmid].push_back(i);
	}
	while(q--) {
		string ta, tb; cin >> ta >> tb;
		int m = ta.length(); int L = tb.length();
		if(m != L) {
			cout << "0\n";
			continue;
		}
		mp1.clear(), mp2.clear();
		pii pos = ask(ta, tb);
		int l = pos.fi, r = pos.se;
		ull hmid = 0;
//		cout << "l = " << l << " r = " << r << '\n';
		for(int i = l; i <= r; i++) {
//			cout << ta[i];
			hmid = hmid * base + ta[i];
			hmid = hmid * base + tb[i];
		}
//		cout << '\n';
		ull hl = 0, hr = 0;
		mp1[0] = mp2[0] = 1;
		for(int i = l - 1; i >= 0; i--) {
			hl = hl * base + ta[i];
			mp1[hl] = 1;
		}
		for(int i = r + 1; i < m; i++) {
			hr = hr * base + tb[i];
			mp2[hr] = 1;
		}
		int cnt = 0;
		for(int i: v[hmid]) {
			if(mp1.count(H[i].hpre) && mp2.count(H[i].hsuf)) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
