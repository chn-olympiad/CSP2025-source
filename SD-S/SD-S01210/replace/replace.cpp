#include<bits/stdc++.h>
#define x1 Sun
#define y1 Jude
#define x0 rp
#define y0 GetWC
#define rep(i, a, b) for(int (i) = (a); (i) <= (b); (i) ++ )
#define per(i, a, b) for(int (i) = (a); (i) >= (b); (i) -- )
#define vi vector<int>
#define pii pair<int, int>
#define ls (x << 1)
#define rs (x << 1 | 1)
using namespace std ;
using ll = long long ;
using ull = unsigned long long ;
//const int maxn = ;
//const int inf = ;
//const int mod = ;
//const int base = ;

int n, q ;
vector<string> s1,s2, t1, t2 ; 

void solve() {
cin >> n >> q ;
	rep(i, 1, n) {
		string s, ss ; cin >> s >> ss ;
//		if(s[s.size()-1] == ' ') cout << "er" ;
		s1.push_back(s) ; s2.push_back(ss) ;
	}
	rep(i, 1, q) {
		string t, tt ; cin >> t >> tt ;
		t1.push_back(t) ; t2.push_back(tt) ;
	}
	rep(i, 0, q - 1) {
		int ans = 0 ;
		string t = t1[i], tt = t2[i] ;
		int l=-1, r=tt.size() - 1 ;
		rep(j, 1, tt.size() - 1) {
			if(t[j] != tt[j]) {
				if(l == -1) l = j ;
				r = j ;
			}
		}
		if(l == -1) {
			int ans = 0 ;
			rep(j, 0, n - 1) {
				if(s1[j] == s2[j]) {
					int p = t.find(s1[j]) ;
					if(0 <= p && p < t.size()) ans ++ ;
				}
			}
			cout << ans << '\n' ;
			continue ;
		}
		string pos ;
		rep(j, l, r) pos += t[j] ;
		
		rep(j, 0, n - 1) {
			string s = s1[j], ss = s2[j] ;
			string tmp = t ;
			if(t.find(s) < t.size()) {
				int pp = t.find(s) ;
				rep(k, pp, pp + s.size() -1) {
					tmp[k] = ss[k] ;
				}
				if(tmp == tt) ans ++ ;
//				cout << tmp << endl ; 
//				cout << t.find(s) << endl ;
			}
			
		}
		cout << ans << endl ;
	}
}
signed main() {
	freopen("replace.in", "r", stdin) ;
	freopen("replace.out", "w", stdout) ;
ios::sync_with_stdio(false) ;
	cin.tie(0), cout.tie(0) ;
	int T = 1 ;
//	cin >> T ;
	while(T -- ) {
		solve() ;
	}
	return 0 ;
}


// rp++!!!

// i will win csps2025 /fendou

