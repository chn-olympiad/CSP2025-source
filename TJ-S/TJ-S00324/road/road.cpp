#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct as{
	int v,w;
};
vector <as> g[10015];
int b[1000005];
map <int,bool> f[10015];
map <int,int> id[10015];
int jb;
int c[15];
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		id[u][v]=g[v].size();
		id[v][u]=g[u].size();
//		if(u==1&&v==4) cout<<g[u][id[v][u]].v<<' '<<g[u][id[u][v]].w<<'\n';
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			as a;
			g[n+i].push_back({j,w});
			g[j].push_back({i+n,w});
		}
	}
	for(int i=1;i<=k;i++){
		for(int u=1;u<=n;u++){
			for(int v=1;v<=n;v++){
				if(u==v) continue;
				if(id[u][v]==0){
					as a;
					a.v=v;
					a.w=g[n+i][u-1].w+g[n+i][v-1].w+c[i];
					g[u].push_back(a);
					a.v=u;
					g[v].push_back(a);
				}
				g[u][id[v][u]].w=min(g[u][id[v][u]].w,g[n+i][u-1].w+g[n+i][v-1].w+c[i]);
			}
		}
	}
	for(int u=1;u<=n;u++){
		for(auto v:g[u]){
			if(f[u][v.v]||f[v.v][u]||v.v>n) continue;
			b[++jb]=v.w;
			f[u][v.v]=1;
			f[v.v][u]=1;
//			cout<<u<<' '<<v.v<<' '<<b[jb]<<'\n';
		}
	}
	sort(b+1,b+1+jb);
	for(int i=1;i<=n-1;i++){
		ans+=b[i];
//		cout<<b[i]<<' ';
	}
	cout<<ans;
	return 0;
}
