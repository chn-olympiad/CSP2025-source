#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define re register
#define endl '\n'
using namespace std ;
template<class T>inline void read (T &x) {x = 0 ;T f = 1 ;char c = getchar() ;while (c < '0' || c > '9') {if (c =='-') {f = -1 ;}c = getchar() ;}while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ;c = getchar() ;}x *= f ;}
template<class T>inline void nout (T x) {if (x < 0) {x = -x ;putchar('-') ;}if (x > 9) {nout(x / 10) ;}putchar(x % 10 + '0') ;}
template<class T>inline void write(T x,const char &c) {nout(x),putchar(c) ;}
const int N = 1e5 + 2 ;
int t,n ;
struct node {
	int x,y,z ;
	node(){x = y = z = 0 ;}
}a[N] ;
inline bool cmp (const node &p,const node &q) {
	int maxp = max(p.x,max(p.y,p.z)) ;
	int maxq = max(q.x,max(q.y,q.z)) ;
	int max2p,max2q ;
	if (maxp == p.x) max2p = max(p.y,p.z) ;
	else if (maxp == p.y) max2p = max(p.x,p.z) ;
	else max2p = max(p.x,p.y) ;
	if (maxq == q.x) max2q = max(q.y,q.z) ;
	else if (maxq == q.y) max2q = max(q.x,q.z) ;
	else max2q = max(q.x,q.y) ;
	return maxp + max2q > max2p + maxq ;
}
vector<node>a1,a2,a3 ;
int cntx,cnty,cntz ;
ll sum ;
int main () {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
	read(t) ;
	while (t--) {
		sum = cntx = cnty = cntz = 0 ;
		read(n) ;
		for (re int i = 1 ; i <= n ; ++i) read(a[i].x),read(a[i].y),read(a[i].z) ;
		sort(a + 1,a + 1 + n,cmp) ;
		for (re int i = 1,tmp ; i <= n ; ++i) {
			tmp = max(a[i].x,max(a[i].y,a[i].z)) ;
			if (tmp == a[i].x) {
				if (cntx == n / 2) {
					tmp = max(a[i].y,a[i].z) ;
					if (tmp == a[i].y) ++cnty ;
					else ++cntz ;
				}
				else ++cntx ;
			}
			else if (tmp == a[i].y) {
				if (cnty == n / 2) {
					tmp = max(a[i].x,a[i].z) ;
					if (tmp == a[i].x) ++cntx ;
					else ++cntz ;
				}
				else ++cnty ;
			}
			else {
				if (cntz == n / 2) {
					tmp = max(a[i].x,a[i].y) ;
					if (tmp == a[i].x) ++cntx ;
					else ++cnty ;
				}
				else ++cntz ;
			}
			sum += tmp ;
		}
		write(sum,endl) ;
	}
	return 0 ;
}
