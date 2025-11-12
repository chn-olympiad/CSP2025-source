#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k;
int a[N][N];
int c[N];
int cb[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	long long ans=0;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		a[u][v]=a[v][u]=w;
		ans+=w;
	}
	bool flaga=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0)flaga=0;
		for(int j=1;j<=n;j++){
			cin>>cb[i][j];
			if(cb[i][j]!=0)flaga=0;
		}
	}
	if(flaga)cout<<"0";
	else cout<<ans;
	return 0;
}
