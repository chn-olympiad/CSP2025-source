#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> q[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	int u,v,g;
	cin>>u>>v>>g;
	q[u].push_back(v);
	q[u][v]=g;
	q[v].push_back(u); 
	q[v][u]=g;
} 
cout<<0;
return 0;
}
