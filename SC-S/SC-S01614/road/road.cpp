#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 2e4 + 5,M = 2e6 + 5;
const ll inf = 1e18;
int n,m,k;
int cnt,fa[N];
ll c[N],ap[15][N];
int root(int x){
	if(x == fa[x]) return x;
	return fa[x] = root(fa[x]);
}
struct edge{
	int u,v;
	int tag;
	ll w;
	friend bool operator < (edge xx,edge yy){
		return xx.w < yy.w;
	}
}e[M << 1];
void add(int u,int v,ll w,int tag){
	e[++ cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].tag = tag;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	ll tm = inf;
	for(int i = 1;i <= m;++ i){
		int u,v;ll w;
		cin >> u >> v >> w;
		tm = min(tm,w);
//		if(w == 1) cout << i << " ->> ";
		add(u,v,w,0);
	}
	bool fl = 1;
	for(int i = 1;i <= k;++ i){
		cin >> c[i];
		fl &= (c[i] == 0);
		for(int j = 1;j <= n;++ j){
			cin >> ap[i][j];
			add(i + n,j,ap[i][j],i);
		}
	}
	sort(e + 1,e + 1 + cnt);
	ll ans = inf;
	if(fl){
		for(int i = 1;i <= n + k;++ i) fa[i] = i;
		int pp = 0;
		ans = 0;
		for(int i = 1;i <= cnt;++ i){
			int ru = root(e[i].u),rv = root(e[i].v);
			if(ru != rv){
				fa[rv] = ru;
				++ pp;
				ans += e[i].w;
				if(pp == n + k - 1) break;
			}
		}
		cout << ans;
		return 0;
	}
	for(int s = 0;s < (1 << k);++ s){
		for(int i = 1;i <= n + k;++ i) fa[i] = i;
		ll res = 0;
		for(int i = 1;i <= k;++ i)
			if((1 << i - 1) & s) res += c[i];
		int op = 0;
		for(int i = 1;i <= cnt;++ i){
			int tg = e[i].tag;
			if((tg != 0) && (((1 << tg - 1) & s) == 0)) continue;
			int ru = root(e[i].u),rv = root(e[i].v);
			if(ru != rv){
				fa[rv] = ru;
				++ op;
				res += e[i].w;
				if(op == n + k - 1) break;
			}
		}
		ans = min(ans,res);
	}
	cout << ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/