#include<bits/stdc++.h>
#define ll long long
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std; 
const int N = 1e4+4;
const int M = 1e6+5;



struct edge{
	int u,v;
	ll w;
}lis[M<<1],ls[M<<1];
edge d[M<<1];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int fa[N+10];
int n,m,k,p;
int find(int u){
	if(fa[u]==u)return u;
	return fa[u] = find(fa[u]);
}

ll C[15],V[15][N];
int vis[15];
ll ANS;
void dfs(int ii){
	if(ii==k+1){
		int cnt = 0;
		int P = n-1;
		ll ans = 0;
		For(i, 1, P){
			d[i].u = ls[i].u;
			d[i].v = ls[i].v;
			d[i].w = ls[i].w;
		}
		For(i, 1, k){
			if(vis[i]==0)continue;
			cnt++;
			ans += C[i];
			For(j, 1, n){
				d[++P] = {cnt+n,j,V[i][j]};
			}
		}
		sort(d+1,d+P+1,cmp);
		int t = 0;
		For(i, 1, n+cnt)fa[i] = i;
		For(i, 1, P){
			int u = d[i].u,v=d[i].v,w=d[i].w;
			if(find(u)!=find(v)){
				fa[find(u)] = find(v);
				t++;
				ans += w;
				if(t==n+cnt-1)break;
			}
		}
		ANS = min(ANS,ans);
		return;
	}
	vis[ii] = 1;
	dfs(ii+1);
	vis[ii] = 0;
	dfs(ii+1);
}


void solve(){
	For(i, 1, k){
		int id = 0;
		For(j, 1, n){
			if(V[i][j]==0){
				id = j;
				break;
			}
		}
		For(j, 1, n){
			if(i==id)continue;
			lis[++m] = {id,j,V[i][j]};
		}
	}
	sort(lis+1,lis+m+1,cmp);
	For(i, 1, n)fa[i] = i;
	int p = 0;
	ll ans = 0;
	For(i, 1, m){
		int u=lis[i].u,v=lis[i].v,w=lis[i].w;
		if(find(u)!=find(v)){
			ans += w;
			fa[find(u)]=find(v);
			p++;
			if(p==n-1)break;
		}
	}
	cout << ans;
	exit(0);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k;
	For(i, 1, m){
		cin >> lis[i].u >> lis[i].v >> lis[i].w;
	}
	int tag = 0;
	For(i, 1, k){
		cin >> C[i];
		For(j, 1, n){
			cin >> V[i][j];
		}
		if(C[i]!=0)tag = 1;
	}
	if(tag == 0){
		solve();
	}
	sort(lis+1,lis+m+1,cmp);
	For(i, 1, n)fa[i] = i;
	int p = 0;
	For(i, 1, m){
		int u=lis[i].u,v=lis[i].v,w=lis[i].w;
		if(find(u)!=find(v)){
			p++;
			ls[p] = {u,v,w};
			ANS += w;
			if(p==n-1)break;
		}
	}

	if(k!=0)dfs(1);
	cout << ANS;
	return 0;
}


