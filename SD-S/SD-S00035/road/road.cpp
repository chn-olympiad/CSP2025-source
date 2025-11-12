#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
long long ans = 0;
int n, m, k, xz[N], f[N];
bool pd = 1;
struct Node
{
	long long v, w;
};
vector <Node> u[N];
int find(int x)
{
	if (f[x] != x)
	return f[x] = find(f[x]);
	return f[x];
} 
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		if (k == 0)
		{
			if (f[aa] != f[bb])
			{
				f[bb] = find(aa);
				ans += cc;
			}
		}
		u[aa].push_back({bb, cc});
	}
	for (int i = 1; i <= k; i++)
	{
		int c;
		cin >> c;
		if (c != 0)
			pd = 0;
		xz[i] = c;
		for (int j = 1; j <= n; j++)
		{
			int tt;
			cin >> tt;
			if (tt != 0)
				pd = 0;
			u[i].push_back({j, tt});
		}
	}
	if (pd && k != 0)
	{
		cout << 0;
		return 0;
	}
	cout << ans;
	return 0;
}
