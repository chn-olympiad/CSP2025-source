#include<bits/stdc++.h>
using namespace std;
vector<int> g[10010];
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for(int i = 1;i<=n;i++)
	{
		int ui,wi,vi;
		cin >> ui >> vi >> wi;
		g[ui].push_back(vi);
		g[ui][vi] = wi;
		g[vi].push_back(ui);
		g[vi][ui] = wi;
	}
	
	return 0;
 }

