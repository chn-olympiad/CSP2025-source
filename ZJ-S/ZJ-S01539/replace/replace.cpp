#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
//#define int long long
const int N = 2e5 + 10;
const int mod = 1e9 + 9, base = 233;
const double eps = 1e-8;
ull pw[N], h[N][2];
vector<ull> H[N][2], vec[N][2];
vector<pair<int, int>> Len[N];
map<ull, int> mp;
ll n, q, cnt, m[N], l[N], r[N];
string s, t;
inline ll read(){
	ll x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * m;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void Freopen(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}
inline ull get(int i, int op, int l, int r){
	if(l < 0) return -2;
	return H[i][op][r] - (l ? H[i][op][l - 1] * pw[r - l + 1] : 0);
}
inline ull get2(int op, int L, int R){
	if(L < 0) return -1;
	return h[R][op] - (L ? h[L - 1][op] * pw[R - L + 1] : 0);
}
inline void solve(){
	n = read(), q = read();
	for(int i = pw[0] = 1; i <= n; ++ i) pw[i] = pw[i - 1] * base % mod;
	for(int i = 1; i <= n; ++ i){
		cin >> s >> t, m[i] = s.size();
		for(int j = 0; j < m[i]; ++ j){
			if(!j) H[i][0].pb(s[j]), H[i][1].pb(t[j]);
			else H[i][0].pb(H[i][0].back() * base + s[j]), H[i][1].pb(H[i][1].back() * base + t[j]);
		}
		for(int j = 0; j < m[i]; ++ j){
			if(s[j] != t[j]){h[i][0] = h[i - 1][0] * base + s[i], h[i][1] = h[i - 1][1] * base + t[i];
				l[i] = j;
				break;
			}
		}
		for(int j = m[i] - 1; j >= 0; -- j){
			if(s[j] != t[j]){
				r[i] = j;
				break;
			}
		}
		ull now1 = get(i, 0, l[i], r[i]), now2 = get(i, 1, l[i], r[i]);
		if(!mp.count(now1 * base + now2)) mp[now1 * base + now2] = ++ cnt;
		int id = mp[now1 * base + now2];
		vec[id][0].push_back(get(i, 0, 0, l[i] - 1)), vec[id][1].push_back(get(i, 1, r[i] + 1, m[i] - 1));
		Len[id].push_back(make_pair(l[i], m[i] - r[i] - 1));
	}
	while(q --){
		cin >> s >> t;
		int len = s.size();
		for(int i = 0; i < len; ++ i) {
			if(!i) h[i][0] = s[i], h[i][1] = t[i];
			else h[i][0] = h[i - 1][0] * base + s[i], h[i][1] = h[i - 1][1] * base + t[i];
		}
		int L = -1, R = n + 1;
		for(int i = 0; i < len; ++ i){
			if(s[i] != t[i]){
				L = i;
				break;
			}
		}
		for(int i = len - 1; i >= 0; -- i){
			if(s[i] != t[i]){
				R = i;
				break;
			}
		}
		ull now1 = get2(0, L, R), now2 = get2(1, L, R);
		if(!mp.count(now1 * base + now2)){
			puts("0");
			continue;
		}
		int id = mp[now1 * base + now2], ans = 0;
		for(int i = 0; i < Len[id].size(); ++ i){
			int l1 = L - Len[id][i].first, r1 = L - 1;
			int l2 = R + 1, r2 = l2 + Len[id][i].second - 1;
			if(max(r1, r2) > len - 1) continue;
			now1 = get2(0, l1, r1), now2 = get2(1, l2, r2);
			ans += ((l1 > r1 || now1 == vec[id][0][i]) && (l2 > r2 || now2 == vec[id][1][i]));
		}
		write(ans), putchar('\n');
	}
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
