#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t, n, a[4][1000005], dp[4][20005], pos[5];
long long anss;
long long maxn(long long a, long long b)
{
	if(a > b) return a;
	return b;
}
void dfs(int cnt, long long ans)
{
	if(cnt > n)
	{
		anss = maxn(anss, ans);
		return;
	}
	for(int i = 1; i <= 3; i++)
	{
		if(pos[i] < n/2)
		{
			pos[i]++;
			dfs(cnt+1, ans+a[i][cnt]);
			pos[i]--;
		}
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--)
	{
		cin >> n;
		anss = 0;
		pos[1] = pos[2] = pos[3] = 0;
		bool kt = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			if(a[2][i] != 0 || a[3][i] != 0) kt = 0;
		}
		if(kt)
		{
			sort(a[1]+1, a[1]+1+n);
			long long ans = 0;
			for(int i = n; i > n / 2; i--) ans += a[1][i];
			cout << ans << '\n';
			continue;
		}
		if(n <= 20)
		{
			dfs(1, 0);
			cout << anss << '\n';
			continue;
		}
	}
	return 0;
}
