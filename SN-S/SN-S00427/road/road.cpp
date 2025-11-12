#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,k,cost[N];
vector<int> u,v;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		u.push_back(v);
		v.push_back(u);
		
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++){
			cin>>f[i][j];
		}
	
	}
	return 0;
} 
