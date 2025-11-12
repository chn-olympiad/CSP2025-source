#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200010;
const int M = 5000010;
const int Mod = 998244353;

int n, m, q, cur, C;
LL fac[M], hs[M], ht[M];
LL nhs[N], nht[N], sz[N];
int spe;
vector<pair<int, int> > v[N];
map<int, int> mpp;

LL q_pow(LL x, LL y) {
	LL s = 1;
	while(y) {
		if(y & 1) s = s * x % Mod;
		x = x * x % Mod;
		y >>= 1;
	}
	return s;
}

LL Fac(int x) {
	if(x == 0) return 1;
	if(fac[x]) return fac[x];
	return fac[x] = Fac(x - 1) * 30 % Mod;
}

LL get(LL *h, int l, int r) {
	return (h[r] - h[l - 1] + Mod) % Mod * q_pow(Fac(l), Mod - 2) % Mod;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q; m = n;
	for(int i = 1; i <= n; ++ i) {
		string s, t;
		cin >> s >> t;
		LL h1 = 0, h2 = 0;
		int cnta = 0, posa = 0, posb = 0;
		for(int j = 0; j < (int)s.size(); ++ j) {
			if(s[j] == 'a') ++ cnta;
			if(s[j] == 'b') posa = j;
			if(t[j] == 'b') posb = j;
			h1 = (h1 + s[j] * Fac(j) % Mod) % Mod;
			h2 = (h2 + t[j] * Fac(j) % Mod) % Mod;
		}
		if(cnta == (int)s.size() - 1) spe ++;
		if(!mpp[posb - posa]) mpp[posb - posa] = ++ C;
		v[mpp[posb - posa]].push_back({min(posa, posb), s.size() - max(posa, posb) - 1});
		nhs[i] = h1, nht[i] = h2; sz[i] = s.size();
	}
	if(spe == n) {
		while(q --) {
			string s, t; cin >> s >> t;
			if(s.size() != t.size()) {
				cout << "0\n";
				continue;
			}
			int posa = 0, posb = 0;
			for(int j = 0; j < (int)s.size(); ++ j) {
				if(s[j] == 'b') posa = j;
				if(t[j] == 'b') posb = j;
			}
			int ans = 0;
			int l = min(posa, posb);
			int r = s.size() - max(posa, posb) - 1;
			if(!mpp[posb - posa]) {
				cout << "0\n";
				continue;
			}
			for(pair<int, int> x : v[mpp[posb - posa]])
				if(x.first <= l && x.second <= r) ++ ans;
			cout << ans << '\n';
		}
		return 0;
	}
	for(int qq = 1; qq <= q; ++ qq) {
		string s, t; int ans = 0;
		cin >> s >> t; n = s.size();
		if(s.size() != t.size()) {
			cout << "0\n";
			continue;
		}
		hs[0] = s[0]; ht[0] = t[0];
		for(int i = 1; i < n; ++ i) {
			hs[i] = (hs[i - 1] + s[i] * Fac(i) % Mod) % Mod;
			ht[i] = (ht[i - 1] + t[i] * Fac(i) % Mod) % Mod;
		}
		int l = 0, r = n - 1;
		while(s[l] == t[l] && l + 1 < n) ++ l;
		while(s[r] == t[r] && r > 0) -- r;
		if(1) {
			for(int i = 0; i <= l; ++ i) {
				for(int j = 1; j <= m; ++ j) {
					if(i + sz[j] - 1 < r || i + sz[j] - 1 >= n) continue;
					if(get(hs, i, i + sz[j] - 1) != nhs[j]) continue;
					if(get(ht, i, i + sz[j] - 1) != nht[j]) continue;
					++ ans;
				}
			}
			cout << ans << '\n';
			continue;
		}
	}
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


3 4
a b
b c
c d
aa bb
aa b
a c
b a


*/
