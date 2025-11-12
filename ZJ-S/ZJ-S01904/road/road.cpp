#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
int u[N],v[N],w[N];
int n,m,k;
int c[15],a[15][10005];
vector<int>G[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
