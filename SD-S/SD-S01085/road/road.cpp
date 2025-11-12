#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 
#define ll long long
#define re register
#define endl '\n'
using namespace std ;
template<class T>inline void read (T &x) {x = 0 ;T f = 1 ;char c = getchar() ;while (c < '0' || c > '9') {if (c =='-') {f = -1 ;}c = getchar() ;}while (c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + (c ^ 48) ;c = getchar() ;}x *= f ;}
template<class T>inline void nout (T x) {if (x < 0) {x = -x ;putchar('-') ;}if (x > 9) {nout(x / 10) ;}putchar(x % 10 + '0') ;}
template<class T>inline void write(T x,const char &c) {nout(x),putchar(c) ;}
const int N = 1e4 + 15 ;
int n,m,k ;
int c[15] ;
struct node {
	int u,v,w ;
	node () {u = v = w = 0 ;}
	node (int _u,int _v,int _w) {u = _u,v = _v,w = _w ;}
	inline bool operator <(const node &x) const {
		if (w == x.w) {
			if (u == x.u) return v < x.v ;
			return u < x.u ;
		}return w < x.w ;
	}
};
vector<node> a ;

int fa[N] ;
ll len,cnt ;
void init () {
	len = cnt = 0 ;
	for (re int i = 0 ; i <= n + k ; ++i) fa[i] = i ;
}
inline int find (int x) {
	if (fa[x] == x) return x ;
	return fa[x] = find(fa[x]) ;
}
inline void merge (int x,int y) {
	int fx = find(x),fy = find(y) ;
	if (fx <= fy) fa[fy] = fx ;
	else fa[fx] = fy ;
}
bool mp[15] ;
void kruskal () {
	init() ;
	int N = n ;
	sort(a.begin(),a.end()) ;
	for (re int i = 1,u,v,w ; i <= m + k * n ; ++i) {
		u = a[i].u,v = a[i].v,w = a[i].w ;
		if (u > n || v > n) {
			if (u > n && !mp[u - n]) ++N,mp[u - n] = 1 ;
			else if (v > n && !mp[v - n]) ++N,mp[v - n] = 1 ;
		}
		if (find(u) == find(v)) continue ;
		merge(u,v) ;
		len += w,++cnt ;
		if (cnt == N - 1) break ;
	}
}
int main () {
	freopen("road.in","r",stdin) ;
	freopen("road.out","w",stdout) ;
	read(n),read(m),read(k) ;
	a.emplace_back(0,0,0) ;
	for (re int i = 1,u,v,w ; i <= m ; ++i) {
		read(u),read(v),read(w) ;
		a.emplace_back(u,v,w) ;
	}
	for (re int i = 1 ; i <= k ; ++i) {
		read(c[i]) ;
		for (re int j = 1,w ; j <= n ; ++j) {
			read(w) ;
			a.emplace_back(n + i,j,w) ;
		}
	}
	kruskal() ;
	nout(len) ;
	return 0 ;
}
