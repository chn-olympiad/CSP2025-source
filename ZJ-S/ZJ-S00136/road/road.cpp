#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int ,int > >a[1000006];
int a1[1000006],a2[1000006],a3[1000006],a4[1000006];
int d[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
		ans+=w;
	}	
	for(int j=0;j<k;j++){
		cin>>d[j];
		for(int i=0;i<n;i++){
			cin>>a1[i]>>a2[i]>>a3[i]>>a4[i];
		}
	}
	cout<<ans;
	return 0;
}
