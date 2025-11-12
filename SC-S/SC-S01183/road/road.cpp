#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
const int N=1e4+50;
int c[20];
struct node{
	int v,cost;
};
vector<node> g[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	bool flag_A=1;
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>c[i];
		if(c[i]) flag_A=0;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			g[i].push_back({j,w});
			g[j].push_back({i,w});
			if(w) flag_A=0; 
		}
	}
	if(flag_A) cout<<0;
	return 0;
}
