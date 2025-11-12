#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin (), (x).end ()
#define vec vector
#define MAXN 2005

template <typename T> inline void read (T &x) {
	x = 0; T f = 1; char ch = getchar ();
	while (!isdigit (ch)) { if (ch == '-') f = -1; ch = getchar (); }
	while (isdigit (ch)) { x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar (); }
	x *= f;
}

template <typename T, typename ...Arp> inline void read (T &x, Arp &...arp) {
	read (x), read (arp...);
}

int n, q;
string s1, s2;
unordered_map <string, string> eq;

//int p = 13, mod = 1e9 + 7;
//
//struct str {
//	int n;
//	int h, H[MAXN];
//	char s[MAXN];
//	
//	void hs () {
//		for (int i = 0; i < s.size (); ++i) {
//			H[i] = (H[i - 1] + s[i] *)  % mod
//		}
//	}
//};
//
//void init () {
//	pw[0] = 1;
//	for (int i = 1; i <= 1000000; ++i) pw[i] = pw[i - 1] * p % mod;	
//}

signed main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	read (n, q);
	
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2;
		
		eq[s1] = s2;
	}
	
	
	while (q--) {
		cin >> s1 >> s2;
		int len = s1.size ();
		int l = 0, r = len - 1;
		
		while (s1[l] == s2[l] && l <= r) ++l;
		while (s1[r] == s2[r] && r >= l) --r;

		ll ans = 0;
		
		for (int i = 0; i <= l; ++i) {
			for (int j = len - 1; j >= r && j >= i; --j) {
				if (eq[s1.substr (i, j - i + 1)] == s2.substr (i, j - i + 1)) {
					++ans;
				}
			}
		}
		
		printf ("%lld\n", ans);
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