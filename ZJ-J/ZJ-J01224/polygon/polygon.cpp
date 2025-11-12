// rp++
// orz cyh sto

#include <bits/stdc++.h>

using namespace std;

const int N = 5000 + 10, V = 10000 + 10, p = 998244353;
int n, a[N];
long long f[V][5], g[V][5], h[V][5];

#define rqy(x) (x >= p ? x - p : x)

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i], h[i][0] = 1;
	sort(a + 1, a + 1 + n);
	/*
	cout << "debug" << "\n";
	for (int i = 1;i <= n;i++)
		cout << a[i] << " \n"[i == n];
	*/
	long long ans = 0;
	g[0][0] = h[0][0] = 1;
	for (int i = 1;i <= n;i++)
	{
		for (int j = a[i];j <= 10000;j++)
		{
			for (int k = 1;k <= 3;k++)
				f[j][k] = g[j-a[i]][k-1];
			f[j][4] = rqy(g[j-a[i]][3] + g[j-a[i]][4]);
		}
		for (int k = 1;k <= 3;k++)
			f[10001][k] = rqy(h[10001][k-1] - h[10001-a[i]-1][k-1] + p);
		f[10001][4] = rqy(rqy(h[10001][4] - h[10001-a[i]-1][4] + p) + rqy(h[10001][3] - h[10001-a[i]-1][3] + p));
		for (int j = a[i];j <= 10001;j++)
			for (int k = 1;k <= 4;k++)
				g[j][k] = rqy(g[j][k] + f[j][k]);
		for (int j = 1;j <= 10001;j++)
			for (int k = 0;k <= 4;k++)
				h[j][k] = rqy(h[j-1][k] + g[j][k]);
		for (int j = 2 * a[i] + 1;j <= 10001;j++)
			ans = rqy(ans + rqy(f[j][3] + f[j][4]));
	}
	cout << ans << "\n";

	return 0;
}