#include<bits/stdc++.h>
using namespace std;

void io()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
} 
const int maxn = 1e5+5;
int t,n,ans;
short num[5][maxn];
void dfs(int x,int a,int b,int c,int tot)
{
	if(x == n+1)
	{
		ans = max(ans,tot);
		return;
	}
	if(a+1 <= n/2)dfs(x+1,a+1,b,c,tot+num[1][x]);
	if(b+1 <= n/2)dfs(x+1,a,b+1,c,tot+num[2][x]);
	if(c+1 <= n/2)dfs(x+1,a,b,c+1,tot+num[3][x]);
}
void dfs1(int x,int a,int b,int tot)
{
	if(x == n+1)
	{
		ans = max(ans,tot);
		return;
	}
	if(a+1 <= n/2)dfs1(x+1,a+1,b,tot+num[1][x]);
	if(b+1 <= n/2)dfs1(x+1,a,b+1,tot+num[2][x]);
}
bool cmp(int a,int b)
{
	return a > b;
}
signed main()
{
	io();
	cin >>t;
	while(t--)
	{
		ans = 0;
		cin >>n;
		bool flag1 = 1,flag2 = 1;
		for(int i = 1; i <= n; i++)
		{
			cin >>num[1][i]>>num[2][i]>>num[3][i];
			if(num[2][i] != 0)flag1 = 0;
			if(num[3][i] != 0)
			{
				flag1 = 0;
				flag2 = 0;
			}
		}
		if(flag1)
		{
			sort(num[1]+1,num[1]+n+1,cmp);
			for(int i = 1; i <= n/2; i++)
			{
				ans+=num[1][i];
			}
			cout<<ans<<"\n";
			continue;
		}
		else if(flag2)
		{
			dfs1(1,0,0,0);
			cout<<ans<<"\n";
			continue; 
		}
		else
		{
			dfs(1,0,0,0,0);
			cout<<ans<<"\n";
			continue;
		}
	}
	return 0;
}