#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n , a[N] , ans;
bool vis[N];
void dfs(int step)
{
	if(step == n + 1)
	{
		int mx = 0 , sum = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i])
			{
				sum += a[i];
				mx = max(a[i] , mx);
			}
		}
		if(sum > mx * 2)
		{
			ans++;
			ans %= 998244353;
		}
		return;
	}
	vis[step] = 1;
	dfs(step + 1);
	vis[step] = 0;
	dfs(step + 1);
}
int main()
{
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	int sum = 0;
	int maxx = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
		maxx = max(maxx , a[i]);
	}
	if(sum < maxx * 2)
	{
		cout << 0;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}