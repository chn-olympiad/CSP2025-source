#include<bits/stdc++.h>
using namespace std;
int mp[10005][10005];
int c[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int pans=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v][w];
		pans+=w;
		
	}
	for(int i=0;i<k;i++){
		cin>>c[i][0];
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	cout<<pans;
}
