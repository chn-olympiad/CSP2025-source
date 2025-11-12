#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;cin>>n>>m>>k;
	vector<vector<int>> e[m+1];
	long long ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;cin>>u>>v>>w;
		e[u].push_back({u,w});
		e[v].push_back({v,w});
		ans+=w;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
