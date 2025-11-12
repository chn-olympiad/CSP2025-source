#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>tu[1015];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	ll ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	cout<<ans;
	return 0;
} 
