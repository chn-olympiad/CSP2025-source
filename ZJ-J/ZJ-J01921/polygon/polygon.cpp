#include<bits/stdc++.h>
using namespace std;
int n, a[5002], b[5002], ans = 0, pos = 0;
void dfs(int k, int maxn, int s, int sum)
{
	if(maxn * 2 < sum)
	{
		if(s < 3) return;
		ans++;
	}
	for(int i = k + 1; i <= n; i++)
	{
		pos++;
		b[pos] = i;
		dfs(i, max(maxn, a[i]), s + 1, sum + a[i]);
		pos--;
	}
	return;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}
