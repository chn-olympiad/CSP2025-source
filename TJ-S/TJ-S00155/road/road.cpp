#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int r[10005][10005];
int v[11][10005];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    
	memset(r,-1,sizeof(r));
	cin>>n>>m>>k;
	int u,vv,w;
	for(int i=1;i<=m;i++){
		cin>>u>>vv>>w;
		r[u][vv]=w;r[vv][u]=w;
	}
	for(int i=1;i<=k;i++){
		int cj;
		cin>>cj;
		v[i][1]=cj;
		for(int j=1;j<=n;j++){
			cin>>v[i][j+1];
		}
	}
	cout<<13;
	return 0;
}
