#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];
bool vis[5005];
long long mod = 998244353;
long long cnt = 0;


void dfs(int now,long long sum,int ma,int xs)
{
	if(now == n + 1)
	{
		if(sum > ma * 2 && xs >= 3)
		{
			cnt++;
			cnt %= mod;
		}
		return;
	}
	if(a[now] > ma)
	{
		dfs(now + 1,sum + a[now],a[now],xs + 1);
	}
	else
	{
		dfs(now + 1,sum + a[now],ma,xs + 1);
	}
	dfs(now + 1,sum,ma,xs);
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	dfs(1,0,0,0);
	cout << cnt;
	return 0;
}