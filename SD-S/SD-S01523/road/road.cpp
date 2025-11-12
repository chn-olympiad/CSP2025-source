#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Node
{
	int v,w;	
};
long long ans=INT_MAX;
vector<Node> to[4000005];
int rd[10005][15];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		to[u].push_back({v,w});
	}
	for(int i=1;i<=k;i++)
	{
		long long um=0;
		for(int j=1;j<=n+1;j++)
		{
			cin >> rd[i][j];
			um+=rd[i][j];
		}
		ans=min(ans,um);
	}
	cout << ans << endl;
	return 0;
} 


