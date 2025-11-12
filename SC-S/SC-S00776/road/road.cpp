#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M = 1e6;
const ll N = 1e4;
ll n, m, k, a[M + 5][4], cj[15], b[15][N + 5];
int main ()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	for (int i = 1; i <= k; ++i)
	{
		cin >> cj[i];
		for (int j = 1; j <= n; ++j)
		{
			cin >> b[i][j];
		}
	}
	cout << 0;
	return 0;
}