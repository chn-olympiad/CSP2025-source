//吴泊成 SN-S00114 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[100],a[100][1000005],mp[1000005][1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>n>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(mp[u][v]!=0){
			mp[u][v]=min(mp[u][v],w);
			mp[v][u]=min(mp[v][u],w);
		}
		else{
			mp[u][v]=w;
			mp[v][u]=w;
		}
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
