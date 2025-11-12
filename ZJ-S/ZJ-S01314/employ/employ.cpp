#include<bits/stdc++.h>
using namespace std;
int cnt = 0,n,m,f[507],a[507],c[507];
bool vis[507];
void dfs(int x)
{
	if(x > n)
	{
		int s1 = 0,s2 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(f[i] == 1&&a[c[i]] > s2)
			{
				s1++;
			}
			else
			{
				s2++;
			}
		}
		if(s1 >= m)
		{
			cnt++;
			if(cnt == 998244353)
			{
				cnt = 0;
			}
		}
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0)
		{	
			vis[i] = 1;
			c[x] = i;
			dfs(x+1);
			vis[i] = 0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		scanf("%1d",&f[i]);
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1);
	cout << cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
