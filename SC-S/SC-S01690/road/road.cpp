#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=1e6+10;
int n,m,k;
int mp[1010][1010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1,z;i<=k;i++){
		cin>>z;
		for(int i=1,t;i<=n;i++){
			cin>>mp[n+i][i];
			mp[i][n+1]=mp[n+i][i];
		}
	}
	n+=k;
	int ans=0;
	int dis[N];
	
	return 0;
}
