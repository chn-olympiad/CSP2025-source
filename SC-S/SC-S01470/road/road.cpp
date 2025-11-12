#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int sum;
int V[N][N],z[N][N];
int jian[N];
int minn=2147483646;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(V,-1,sizeof V);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
		V[u][v]=w;
		V[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>jian[i];
		for(int j=1;j<=n;j++){
			cin>>z[i][j];
		}
	}
	if(k==0)cout<<sum;
	return 0;
}
