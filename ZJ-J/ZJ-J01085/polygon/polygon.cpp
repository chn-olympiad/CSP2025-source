#include<bits/stdc++.h>
using namespace std;
int n, a[5005], f[2][5005], maxn, ans;
int mod(int x)	{
	if (x >= 998244353)	x -= 998244353;
	return x;
}
int main()	{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)	{
		scanf("%d", a + i);
		maxn = max(maxn, a[i]);
	}
	maxn++;
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i < n; ++i)	{
		for (int j = 0; j <= maxn; ++j)	f[i & 1][j] = f[(i & 1) ^ 1][j];
		for (int j = 0; j <= maxn; ++j)	{
			int p = min(j + a[i], maxn);
			f[i & 1][p] = mod(f[i & 1][p] + f[(i & 1) ^ 1][j]);
			if (j > a[i + 1])	ans = mod(ans + f[i & 1][j]);
		} 
	}
	cout << ans << endl;
	return 0;
}