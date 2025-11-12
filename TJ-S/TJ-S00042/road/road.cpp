#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[10005][10005],a[100][100000],c[10000],d[10005][10005]={10000000000},sl[10005][10005],sq[10005][10005],zz[10005],sv[10005][10005],v[10005][10005];
ll n,m,k;
vector<int> g[10005];
int main(){
	freopen("road.in","r",stdout);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		t[u][v]=w;
		t[v][u]=w;
		g[u].push_back(v);
		//g[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			for(int z=0;z<g[i].size();z++){
				if(g[j]==g[z]) continue; 
				d[j][g[j][z]]=min(d[j][g[j][z]],t[i][g[j][z]]+t[i][j]);
				d[g[j][z]][j]=min(d[g[j][z]][j],t[i][g[j][z]]+t[i][j]);
			}
		}
	}
	for(int i=1;i<=k;i++){
		int sheng=0;
		int yuan=0;
		for(int j=1;j<=n;j++){
			for(int x=0;x<g[j].size();x++){
				if(a[i][j]+a[i][g[j][x]]<d[j][g[j][x]]){
					sheng+=(d[j][g[j][x]]-(a[i][j]+a[i][g[j][x]]));
					sl[j][g[j][x]]=i;
					sl[g[j][x]][j]=i;
					sq[j][g[j][x]]=(d[j][g[j][x]]-(a[i][j]+a[i][g[j][x]]));
					sq[g[j][x]][j]=(d[j][g[j][x]]-(a[i][j]+a[i][g[j][x]]));
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			if(sq[i][g[i][j]]&&sv[i][g[i][j]]==0){
				zz[sl[i][g[i][j]]]+=sq[i][g[i][j]];
				sv[i][g[i][j]]=1;
			}
		}
	}
	int ans=0,ans1=0;
	for(int i=1;i<=k;i++){
		if(zz[i]>c[i]){
			ans+=c[i];
			ans1+=zz[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<g[i].size();j++){
			ans+=d[i][g[i][j]];
		}
	}
	cout<<ans-ans1;
	return 0;
}
