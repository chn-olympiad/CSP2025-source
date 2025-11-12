//Fight until the end like I promised to
#include<bits/stdc++.h>
#define AK 0
#define int long long
#define D(x) cout<<#x<<": "<<x<<'\n'
#define De(x) cout<<#x<<": "<<x<<' '
#define ctn continue
#define brk break
#define space putchar(' ')
#define enter putchar('\n')
#define pii pair<int,int>
#define mkp make_pair
#define up(l,r,i) for(int i=l;i<=r;i++)
#define dn(r,l,i) for(int i=r;i>=l;i--)
using namespace std;
inline int read(){
	bool f = 0;
	int x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') f = 1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();}
	return f ? -x : x;
}
const int N = 2e4 + 7, M = 1e6 + 7, mod = 1e9 + 7;
int n, m, k, tot;
struct edge{
	int u, v, w;
	bool operator<(const edge&o) const{
		return w < o.w;
	}
}a[M], b[N << 1], c[200007];
int fa[N];
int zb[12][N];
inline int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	up(1, m, i){
		int u = read(), v = read(), w = read();
		a[i] = edge{u, v, w};
	}
	up(1, n, i) fa[i] = i;
	sort(a + 1, a + 1 + m);
	int ans = 0;
	up(1, m, i){
		int u = a[i].u, v = a[i].v, w = a[i].w;
		int U = find(u), V = find(v);
		if(U == V) ctn;
		b[++tot] = a[i];
		fa[U] = V;
		ans += w;
		if(tot == n - 1) brk;
	}
	up(1, k, i){
		up(0, n, j) zb[i][j] = read();
	}
	up(1, (1 << k) - 1, S){
		int tt = 0, sum = 0, kk = 0;
		up(1, tot, i) c[i] = b[i];
		up(1, k, i){
			if((S >> (i - 1)) & 1){
				sum += zb[i][0];
				kk++;
				up(1, n, j){
					tt++;
					c[tt + tot] = edge{n + kk, j, zb[i][j]};
				}
			}
		}
		sort(c + 1, c + 1 + tt + tot);
		up(1, n + kk, i) fa[i] = i;
		int cnt = 0;
//		De(sum);
		up(1, tt + tot, i){
			int u = c[i].u, v = c[i].v, w = c[i].w;
			int U = find(u), V = find(v);
			if(U == V) ctn;
			cnt++;
			fa[U] = V;
			sum += w;
			if(cnt == n + kk - 1) brk;
		}
//		De(S), D(sum);
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return AK;
}
/*

*/