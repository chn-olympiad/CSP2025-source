#include<bits/stdc++.h>
using namespace std;
long long a[1000][1000],c[10000],t,a1[100100],a2[100100],a3[100100],maxn,flaga,flagb,ans,n,m,k,d[1000][1000],u[1000000],v[1000000],w[1000000],vis[1000000];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		if(vis[u[i]]==vis[v[i]]&&vis[u[i]]!=0){
			if(d[vis[u[i]]][v[i]]>d[vis[u[i]]][v[i]]&&d[vis[u[i]]][v[i]]>d[u[i]][v[i]]){
				d[vis[u[i]]][v[i]]=1e9;
			}
			else if(d[vis[u[i]]][v[i]]<d[vis[u[i]]][v[i]]&&d[vis[u[i]]][v[i]]>d[u[i]][v[i]]){
				d[vis[u[i]]][v[i]]=1e9;
			}
			else{
				d[u[i]][v[i]]=1e9;
			}
		}
		d[u[i]][v[i]]=w[i];
		d[v[i]][u[i]]=w[i];
		vis[v[i]]=u[i];
		vis[u[i]]=v[i];
	}
	for(int i=1;i<=k;i++){
	cin>>c[i];
		for(int j=1;j<=n;j++){
		cin>>a[i][j];
		}
	}
		for(int i=1;i<=n;i++){
			if(d[u[i]][v[i]]!=1e9&&d[v[i]][u[i]]!=1e9){
				ans+=d[u[i]][v[i]];
			}
		}
		cout<<ans;
return 0;
}
//6 0 5
//5 0 0
//4 0 0
//3 0 0
