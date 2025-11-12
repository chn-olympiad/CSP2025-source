// SN-S00253  张笑语  西安高新第一中学
#include<bits/stdc++.h>
#define int long long
#define il inline
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
using namespace std;
namespace asbt{
const int maxn=1e4+5,maxm=1e6+5,inf=1e18;
int n,m,kk,dis[maxn],a[15][maxn],b[15],fa[maxn];
bool vis[maxn];
vector<pii> e[maxn];
struct edge{
	int u,v,w;
	il bool operator<(const edge &x)const{
		return w<x.w;
	}
}c[maxm];
il int find(int x){
	return x!=fa[x]?fa[x]=find(fa[x]):x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>kk;
	if(!kk){
		for(int i=1,u,v,w;i<=m;i++){
			cin>>u>>v>>w;
			c[i]={u,v,w};
		}
		sort(c+1,c+m+1);
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			int u=find(c[i].u),v=find(c[i].v);
			if(u!=v){
				ans+=c[i].w,fa[u]=v;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	for(int i=1;i<=kk;i++){
		cin>>b[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=inf;
	for(int S=0;S<1<<kk;S++){
		int res=0;
		for(int i=1;i<=kk;i++){
			if(S>>(i-1)&1){
				res+=b[i];
			}
		}
		for(int i=0;i<=n;i++){
			dis[i]=inf,vis[i]=0;
		}
		dis[1]=0;
		for(int i=1;i<=n;i++){
			int u=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&dis[u]>dis[j]){
					u=j;
				}
			}
			vis[u]=1,res+=dis[u];
			for(pii k:e[u]){
				int v=k.fir,w=k.sec;
				if(!vis[v]&&dis[v]>w){
					dis[v]=w;
				}
			}
			for(int k=1;k<=kk;k++){
				if(S>>(k-1)&1){
					for(int v=1;v<=n;v++){
						int w=a[k][u]+a[k][v];
						if(!vis[v]&&dis[v]>w){
							dis[v]=w;
						}
					}
				}
			}
		}
		ans=min(ans,res);
	}
	cout<<ans;
	return 0;
}
}
signed main(){return asbt::main();}

