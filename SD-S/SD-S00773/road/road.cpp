#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>x;
		}
	}
	cout<<ans;
	return 0;
}
