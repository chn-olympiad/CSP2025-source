#include<iostream>
#include<cstdio>
#define ll long long
#define re register
#define endl '\n'
using namespace std ;
template<class T>inline void read (T &x) {x = 0 ;T f = 1 ;char c = getchar() ;while (c < '0' || c > '9') {if (c =='-') {f = -1 ;}c = getchar() ;}while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ;c = getchar() ;}x *= f ;}
template<class T>inline void nout (T x) {if (x < 0) {x = -x ;putchar('-') ;}if (x > 9) {nout(x / 10) ;}putchar(x % 10 + '0') ;}
template<class T>inline void write(T x,const char &c) {nout(x),putchar(c) ;}
int n,q ;
int main () {
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ;
	read(n),read(q) ;
	while (q--) {
		write(0,endl) ;
	}
	return 0 ;
}

