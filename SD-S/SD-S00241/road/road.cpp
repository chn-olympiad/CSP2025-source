#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n,m,k,sum;
struct node
{
	int to,val;
} e;
vector<node> adj[N],adjj[N];
int change[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >>k;
	for(int i = 1;i <= m;i++)
	{
		int a,b,val;
		cin >> a >> b >> val;
		sum += val;
		adj[a].push_back({b,val});
		adj[b].push_back({a,val});
	}
	for(int j = 1;j <= m;j++)
	{
		int val;
		cin >> val;
		change[j] = val;
		for(int i = 1;i <= n;i++)
		{
			cin >> val;
			adjj[j].push_back({i,val});
		}
	}
	cout << sum;
	return 0;
}
