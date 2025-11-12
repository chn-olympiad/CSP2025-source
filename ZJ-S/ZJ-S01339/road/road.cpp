#include<bits/stdc++.h>
#define mp make_pair
#define fo(i , x , y) for(int i = x ; i <= y ; i++)
#define go(i , x , y) for(int i = x ; i >= y ; i--)
using namespace std;
const int maxn = 10005;
const int maxm = 1000005;
const int maxk = 13;
int n , m , k;
struct Edge{
	int u , v , w;
	friend bool operator < (const Edge & a , const Edge & b){
		return a.w < b.w;
	}
}edge[maxm] , e[maxn] , d[maxk][maxn];
class Kru{
private:
	int fa[maxn];
	int getf(int u){
		if(fa[u] == u) return u;
		fa[u] = getf(fa[u]);
		return fa[u];
	}
public:
	void kru(){
		int cnt = 0;
		sort(edge + 1 , edge + 1 + m);
		fo(i , 1 , n)
			fa[i] = i;
		fo(i , 1 , m){
			int u = edge[i].u;
			int v = edge[i].v;
			u = getf(u) , v = getf(v);
			if(u == v) continue;
			fa[u] = v;
			e[++cnt] = edge[i];
		}
		return;
	}
}qwq;

int c[maxk] , a[maxk][maxn];
int mixcnt;
Edge mix[maxn + maxn * maxk];
long long ans = 1e18;
int chose[maxk];
class Kru2{
private:
	int fa[maxn + maxk];
	int getf(int u){
		if(fa[u] == u) return u;
		fa[u] = getf(fa[u]);
		return fa[u];
	}
public:
	long long kru(){
		long long ans = 0;
		sort(mix + 1 , mix + 1 + mixcnt);
		fo(i , 1 , n + k)
			fa[i] = i;
		fo(i , 1 , mixcnt){
			int u = mix[i].u;
			int v = mix[i].v;
			u = getf(u) , v = getf(v);
			if(u == v) continue;
			fa[u] = v;
			ans += mix[i].w;
		}
		return ans;
	}
}qaq;
long long cal(){
	long long ans = 0;
	fo(i , 1 , k)
		ans += chose[i] * c[i];
	fo(i , 1 , n - 1)
		mix[++mixcnt] = e[i];
	fo(j , 1 , k){
		if(chose[j] == 0) continue;
		fo(i , 1 , n)
			mix[++mixcnt] = d[j][i];
	}
	ans += qaq.kru();
	mixcnt = 0;
	return ans;
}
void dfs(int now){
	if(now > k){
		ans = min(ans , cal());
		return;
	}
	chose[now] = 0;
	dfs(now + 1);
	chose[now] = 1;
	dfs(now + 1);
	chose[now] = 0;
}
int main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m >> k;
	fo(i , 1 , m)
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
	qwq.kru();
//	fo(i , 1 , n - 1)
//		print(e[i]);
	fo(i , 1 , k){
		cin >> c[i];
		fo(j , 1 , n){
			cin >> a[i][j];
			d[i][j].u = n + i;
			d[i][j].v = j;
			d[i][j].w = a[i][j];
		}
	}
	dfs(1);
	cout << ans << '\n';
}
