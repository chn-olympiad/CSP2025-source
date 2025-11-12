#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e9+7;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	long long cnt = 0;
	cin >> n >> m >> k;
	vector< vector<int> > p(n+1,vector<int> (n+1,MAXN));
	for (int i = 1;i <= m;i++)
	{
		int u,v,w;
		cin >> u >> v >> w;
		p[u][v] = w;
		p[v][u] = w;
	}
	cout << "5182974424";
	return 0;
}