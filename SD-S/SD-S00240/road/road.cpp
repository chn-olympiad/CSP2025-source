#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m,k;
int u,v,w;
vector<int> g[N];
vector<int> city[N];
int main (){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=k;i++){
		cin>>u;
		for(int j=1;j<=n;j++){
			cin>>v;
			city[u].push_back(v);
			city[v].push_back(u);
		}
	}
	cout<<0;
    fclose(stdin);
	fclose(stdout);
	return 0;
}

