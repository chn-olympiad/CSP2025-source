#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+3;

struct node{
	int to;
	long long int w;
};

int n,m,k,u,z;
int vis[N];
long long int w,sum,cnt,ans;
vector <node> v[N];

long long int dfs(int p,int t)
{
	long long int c = 0;
	for (unsigned int j=0; j< v[p].size(); j++)
	{
		if (vis[v[p][j].to] > 1)
		{
			if (t == 1) return v[p][j].w;
			vis[j]--;
			c = max(c,dfs(v[p][j].to,t-1) + v[p][j].w);
			vis[j]++;
		}
	}
	return c;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int f = 0;
	for (int i=1; i<=m; i++)
	{
		cin >> u >> z >> w;
		if (u != z)
		{
			v[u].push_back({z,w});
			v[z].push_back({u,w});
			vis[u]++;
			vis[z]++;
			sum += w;
		}
		else f++;
	}
	m -= f;
	int tot = m - n + 1;
	for (int i = 1; i<= n; i++)
	{
		if (vis[i] > 1)
		{
			vis[i]--;
			cnt = max(cnt,dfs(i,tot));
			vis[i]++;
		}
	}
	ans = sum - cnt;
	cout << ans;
	
	return 0;
}
