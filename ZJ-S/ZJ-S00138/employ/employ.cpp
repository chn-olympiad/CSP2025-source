#include<bits/stdc++.h>
using namespace std;

char s[505];
bool lq[505];
int c[505];
int n,m;
int cnt;
int mod = 998244353;
bool vis[505];
int dqsx[505];

bool check()
{
	int sum = 0;
	int bjj = 0;
	for(int i = 1;i <= n;i++)
	{
		if(bjj >= c[dqsx[i]])
		{
			bjj++;
		}
		else
		{
			if(lq[i])
			{
				sum++;
			}
			else
			{
				bjj++;
			}
		}
	}
	return sum >= m;
}

void dfs(int now)
{
	if(now == n + 1)
	{
		if(check())
		{
			cnt++;
			cnt %= mod;
		}
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 0)
		{
			vis[i] = 1;
			dqsx[now] = i;
			dfs(now + 1);
			vis[i] = 0;
		}
	}
}

long long pl(int now)
{
	long long cnt = 1;
	for(int i = 1;i <= now;i++)
	{
		cnt *= now;
		cnt %= mod;
	}
	return cnt;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	cin >> s + 1;
	bool ok = 1;
	for(int i = 1;i <= n;i++)
	{
		if(s[i] == '1')
		{
			lq[i] = 1;
		}
		else
		{
			ok = 0;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	if(ok)
	{
		cout << pl(n);
		return 0;
	}
	dfs(1);
	cout << cnt;
	return 0;
}
