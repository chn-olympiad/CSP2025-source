#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,e[5005][5005];
vector<int> g[10005];
int fa[10005],c[10005],mx,h;
int ans;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		e[u][v]=e[v][u]=w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	  fa[i]=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j],e[u][v]=e[v][u]=0;
			int x=i,y=j;
			if(x>y) swap(x,y);
			int px=find(x),py=find(y);
			if(px!=py){
				fa[px]=py;
			} 
		}
	}
	for(int i=1;i<=n;i++){
		c[f[i]]++;
	}
	for(int i=1;i<=n;i++)
	  if(c[i]>mx)
	    mx=c[i],h=i;
	for(int i=1;i<=n;i++){
		if(f[i]==h) continue;
		int mn=INT_MAX;
		for(int j=1;j<=n;j++){
			if(f[j]==h)
			  mn=min(mn,e[i][j]);
		}
		ans=ans+mn;
	}
	cout<<ans;
	return 0;
}
