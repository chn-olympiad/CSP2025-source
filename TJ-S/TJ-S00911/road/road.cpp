#include <bits/stdc++.h>
using namespace std;
int n,m,k,w,u,v;
int mp[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int cnt=0;
	for(int i=1;i<=m;i++){
//		u=rand()%10,v=rand()%10,w=rand()%10;
		cin>>u>>v>>w;
		if(mp[u][v]!=0){
			mp[u][v]=min(mp[u][v],w);
			mp[v][u]=min(mp[v][u],w);
		}else{
			mp[u][v]=w;
			mp[v][u]=w;
		}
		
	}
	int f=0;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>f;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cnt+=mp[i][j];
		}	
	}
	cnt/=2;
	cout<<cnt;
	return 0;
}
