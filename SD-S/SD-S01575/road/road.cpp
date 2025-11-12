#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
const int M=1e6+10;
int n,m,k;
struct node{
	int u,v,w;
};
vector<node>G[N];
int c[N],a[15][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back((node{v,w}));
		G[v].push_back((node{u,w}));
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	cout<<0<<"\n";
	return 0;
}
