#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e3 + 10;

int n, a[N], max_a, vis[N];
LL ans;

void dfs(int x, vector<LL> v)
{
	LL res = 0, mx = 0;
	for(int i = 0; i < v.size(); i++)
	{
		res += v[i];
		mx = max(mx, v[i]);
	}
	if(res > mx * 2) ans++;
	if(x == n + 1) return ;
	
	for(int i = x; i <= n; i++)
	{
		if(vis[i]) continue;
		vis[i] = 1;
		vector<LL> edge = v;
		edge.push_back(a[i]);
		dfs(i + 1, edge);
		vis[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		max_a = max(max_a, a[i]);
	}
	
	if(max_a == 1)
	{
		for(int len = 3; len <= n; len++)
		{
			for(int l = 1; l + len - 1 <= n; l++)
			{
				int r = l + len - 1;
				ans++;
			}
		}
		
		cout << ans << "\n";
		return 0;
	}	
	
	vector<LL> _;
	dfs(1, _);
	cout << ans << "\n"; 
	return 0;
}
