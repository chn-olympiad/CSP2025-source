#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

const int N = 1e4 + 500;
const int M = 1e6 + 10;
const ll INF = 1e18;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n, m, k;
ll c[N], a[15][N];
ll ans = INF, tmp = 0;
int tot, fa[N], cnt;
struct Edge{
	int u, v; 
	ll w;
}e[M<<1];

int find( int x ){
	if( fa[x] == x )return fa[x];
	else return fa[x] = find(fa[x]);
}
void init( int state ){
	int now = 1;
	tot = m;cnt = n;tmp = 0;
	while( state ){
		if( state & 1 ){
			cnt++;
			for( int i = tot + 1 ; i <= tot + n ; ++i ){
				e[i].u = i - tot;
				e[i].v = cnt;
				e[i].w = a[now][i - tot];
			}
			tot += n;
			tmp += c[now];
		}
		now++;
		state >>= 1;
	}
}
bool cmp( Edge A , Edge B ){return A.w < B.w;}
ll kruskal(){
	ll res = 0, num = 0;
	for( int i = 1 ; i <= cnt ; ++i )fa[i] = i;
	sort(e+1,e+tot+1,cmp);
	for( int i = 1 ; i <= tot ; ++i ){
		int x = e[i].u, y = e[i].v;
		if( (x = find(x)) != (y = find(y)) ){
			fa[x] = y;
			num++;
			res += e[i].w;
		}
		else continue;
		if( num == cnt - 1 )return res;
	}
	if( num == cnt - 1 )return res;
	else return INF;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ll sum = 0;
	n = read();m = read();k = read();
	for( int i = 1 ; i <= m ; ++i ){
		e[i].u = read();e[i].v = read();e[i].w = read();
	}
	for( int i = 1 ; i <= k ; ++i ){
		c[i] = read();
		sum += c[i];
		for( int j = 1 ; j <= n ; ++j )a[i][j] = read();
	}
	if( sum == 0 ){
		init(((1<<k)-1));
		cout << kruskal() << "\n";
		return 0;
	}
	for( int i = 0 ; i < (1<<k) ; ++i ){
		init(i); 
		ans = min(ans,(kruskal() + tmp));
	}
	cout << ans << "\n";
	return 0;
}
