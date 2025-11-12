#include<bits/stdc++.h>
using namespace std;

int a[10010][4];
int n;
int vis[10010][4];
long long ans;
long long maxans;
int maxn[4];
void dfs(int dep)
{
	if(dep == n+1)
	{
		maxans =  max(ans, maxans);
		return ;
	}
	//1a, 2b, 3c;
	for(int i = 1; i <= 3; i++)
	{
		if(maxn[i] <= n/2)
		{
			ans += a[dep][i];
			maxn[i]++;
			
			dfs(dep+1);
			maxn[i] = 0;
			ans=0;
		}
	}
}


int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(vis, 0, sizeof(vis));
		if(n == 2){
			int a1, b1, c1;
			int a2, b2, c2;
			cin >> a1 >> b1 >> c1;
			cin >> a2 >> b2 >> c2;
			int ans[10];
			ans[0] = a1 + b2;
			ans[1] = a1 + c2;
			ans[2] = b1 + a2;
			ans[3] = b1 + c2;
			ans[4] = c1 + a2;
			ans[5] = c1 + b2;
			sort(ans, ans + 6);
			cout << ans[5] << '\n';
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1);
		cout << maxans;
	}
	return 0;
}
