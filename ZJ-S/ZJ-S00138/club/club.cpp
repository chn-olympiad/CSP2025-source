#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005],c[100005];
int ma;
int n;

void dfs(int now,int sum,int anum,int bnum,int cnum)
{
	if(now == n + 1)
	{
		ma = max(ma,sum);
		return;
	}
	if(anum + 1 <= n / 2)
	{
		dfs(now + 1,sum + a[now],anum + 1,bnum,cnum);
	}
	if(bnum + 1 <= n / 2)
	{
		dfs(now + 1,sum + b[now],anum,bnum + 1,cnum);
	}
	if(cnum + 1 <= n / 2)
	{
		dfs(now + 1,sum + c[now],anum,bnum,cnum + 1);
	}
}

bool cmp(int x,int y)
{
	return x > y;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		ma = 0;
		cin >> n;
		bool ok = 1;
		for(int i = 1;i <= n;i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			if(b[i] != 0 || c[i] != 0)
			{
				ok = 0;
			}
		}
		if(ok)
		{
			sort(a + 1,a + n + 1,cmp);
			int cnt = 0;
			for(int i = 1;i <= n / 2;i++)
			{
				cnt += a[i];
			}
			cout << cnt << '\n';
		}
		else
		{
			dfs(1,0,0,0,0);
			cout << ma << '\n';	
		}
	}
	return 0;
}
