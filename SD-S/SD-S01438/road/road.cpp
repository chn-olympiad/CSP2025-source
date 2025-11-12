#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e7+5;
const int N=1e4+5;


struct e{
	int u,v,w;
}g[M];

bool cmp(e x,e y){
	return x.w<y.w;
}


ll fa[N],vis[N],c[15],tot;
int fd(ll u){
	if(fa[u]==u)return u;
	return fd(fa[u]);
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		g[++tot]=((e){u,v,w});
		g[++tot]=((e){v,u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];ll w;
		for(int j=1;j<=n;j++){
			
			cin>>w;
			g[++tot]=((e){n+i,j,w});
			g[++tot]=((e){j,n+i,w});
		}
	}
	sort(g+1,g+1+tot,cmp);
	ll ans=0;
	for(int i=1;i<=tot;i++){
		ll u=g[i].u,v=g[i].v,w=g[i].w;
		//if(w==2)
			//cout<<u<<"}"<<v<<" "<<w<<endl;
		if(!vis[u] || !vis[v] || fa[u]!=fa[v]){
			//cout<<u<<" "<<v<<" "<<w<<endl;
			vis[u]=vis[v]=1;
			ans+=w;
			if(fa[v]!=v)fa[u]=fa[v];
			else fa[v]=fa[u];
			//cout<<fa[u]<<"}"<<fa[v]<<endl;
		}
	}
	cout<<ans;
	return 0;
}
