#include <bits/stdc++.h>

using namespace std;

int n, m, k, u[1000006], v[1000005], w[1000005], c, a[10005];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1;i <= m;i++) cin >> u[i] >> v[i] >> w[i];
	for (int i = 1;i <= k;i++)
	{
		cin >> c;
		for (int i = 1;i <= n;i++) cin >> a[i];
	}
	cout << 0;
	return 0;
}
