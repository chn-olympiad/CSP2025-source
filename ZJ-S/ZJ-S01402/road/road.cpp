#include <bits/stdc++.h>
using namespace std;
int n,m,k,x,u,v,w,ans;
vector<int> g[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++)cin>>x;
	}
	cout<<ans;
	return 0;
}

