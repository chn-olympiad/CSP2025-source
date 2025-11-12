#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,m,k,u,v,w,ans;
vector<int> vec[1000005];
int c[105],a[105][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;ans+=w;
		vec[u].emplace_back(v),vec[v].emplace_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}cout<<w;
}
