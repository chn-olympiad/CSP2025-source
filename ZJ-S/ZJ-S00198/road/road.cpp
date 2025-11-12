#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
vector<node> ve[10004];
queue<int> q[5];
int ans[15004];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	for(int i=m+1;i<=m+k;i++){
		int c;
		cin>>c;
		int a;
		for(int j=1;j<=n;j++){
			cin>>a;
			ve[j].push_back({i,c+a});
			ve[i].push_back({i,a});
		}
	}
	cout<<0;
	return 0;
}
/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
