#include<iostream>
#include<cstdio>
#include<string> 
#define ll long long
#define re register
#define endl '\n'
using namespace std ;
template<class T>inline void read (T &x) {x = 0 ;T f = 1 ;char c = getchar() ;while (c < '0' || c > '9') {if (c =='-') {f = -1 ;}c = getchar() ;}while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ;c = getchar() ;}x *= f ;}
template<class T>inline void nout (T x) {if (x < 0) {x = -x ;putchar('-') ;}if (x > 9) {nout(x / 10) ;}putchar(x % 10 + '0') ;}
template<class T>inline void write(T x,const char &c) {nout(x),putchar(c) ;}
const int N = 502,MOD = 998244353 ;
string s ;
int n,m,c[N] = {0} ;
int a[N] = {0} ;
bool vis[N] = {0} ;
ll ans ;
void check () {
	int ct = 0 ;
	for (re int i = 1 ; i <= n ; ++i) {
		if (ct >= a[i] || s[i] == '0') ++ct ;
	}
	if (n - ct >= m) {
		++ans ;
		if (ans >= MOD) ans -= MOD ;
	}
}
void dfs (int cnt) {
	if (cnt == n + 1) {
		check() ;
		return ;
	}
	for (re int i = 1 ; i <= n ; ++i) {
		if (!vis[i]) {
			vis[i] = 1 ;
			a[cnt] = c[i] ;
			dfs(cnt + 1) ;
			vis[i] = 0 ;
		}
	}
}
int main () {
	freopen("employ.in","r",stdin) ;
	freopen("employ.out","w",stdout) ;
	read(n),read(m) ;
	cin>>s ;
	s = ' ' + s ;
	for (re int i = 1 ; i <= n ; ++i) read(c[i]) ;
	if (n <= 30) {
		dfs(1) ;
		nout(ans) ;
	}
	return 0 ;
}
