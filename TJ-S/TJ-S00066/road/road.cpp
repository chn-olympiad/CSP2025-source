#include <bits/stdc++.h>
#define int long long
constexpr int MAXN=10000, MAXK=10, MAXM = 1000000;
using namespace std;
struct edge{
	int u,v,w;
	bool operator<(edge& x){
		return w<x.w;
	}
};
edge g[MAXM+MAXN*MAXK*3];
bool vis[MAXK+10][MAXN+10];
int a[MAXK+10][MAXN+10];
int dsu[MAXN+10];
int rsp = 0;
int n,m,k;
int ufind(int x){
	while(x != dsu[x]){
		x = dsu[x];
	}return x;
}
edge make_edge(int u,int v,int w){
	edge r;
	r.u=u;r.v=v;r.w=w;
	return r;
}
signed main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin >> n >> m >> k;
	for(int i=0;i<m;i++){
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	int c, cnt = m;
	for(int i=1;i<=k;i++){
		cin >> c;
		for(int j=1;j<=n;j++)  cin >> a[i][j];
		if(!c){
			for(int j=1;j<=n;j++){
				g[cnt++] = make_edge(i*2+n, j, a[i][j]);
			}
		}else{
			for(int j=1;j<=n;j++){
				g[cnt++] = make_edge(i*2+n, j, a[i][j]);
				g[cnt++] = make_edge(i*2+n+1, j, a[i][j]);
			}
			g[cnt++] = make_edge(i*2+n, i*2+n+1, c);
			//cout << cnt << " " << g[cnt-1].v << endl;
		}
	}
	//cout << endl;
	//mgt
	iota(dsu+1, dsu+n+k*2+3, 1);
	sort(g, g+cnt);
	cout << endl;
	int rec = n*(n+1);
	for(int i=0;i<cnt;i++){
		int ru = ufind(g[i].u), rv = ufind(g[i].v);
		if(ru != rv){
			if(g[i].u>n && g[i].v<=n){
				int b = g[i].u/2;
				if(vis[b*2-n][g[i].v] or vis[b*2+1-n][g[i].v]){
					continue;
				}else{
					int b = g[i].u/2;
					vis[g[i].u-n][g[i].v];
				}
			}
			//cout << g[i].u << " " << g[i].v << " " << g[i].w << endl;
			rsp += g[i].w;
			dsu[rv] = ru;
			if(g[i].u<=n)  rec-=g[i].u;
			if(g[i].v<=n)  rec-=g[i].v;
		}
		bool flag = true;
		//for(int i=1;i<=n;i++)  cout << ufind(i) << " ";
		//for(int i=1;i<=n;i++)  cout << dsu[i] << " ";
		//cout << endl << endl;
		int ch = ufind(1);
		for(int j=2;j<=n && flag;j++){
			if(ufind(j) != ch)  flag=false;
		}
		if(flag)  break;
	}
	//meaningless connection
	for(int i=1;i<=k*2;i++){
		int cnt0 = 0, ext;
		for(int j=1;j<=n;j++){
			//cout << vis[i][j] << " ";
			if(vis[i][j]){
				cnt0++;ext=a[i][j];
				//cout << i << cnt0 << " " << ext << endl;
			}
		}
		//cout << endl;
		if(cnt0==1)  rsp-=ext;
	}
	cout << rsp << endl;
	return 0;
}


