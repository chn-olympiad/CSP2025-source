#include <bits/stdc++.h>
using namespace std;

int a[505],n,m,cnt;
bool b[505];
long long q = 998244353;
string s;

void dfs(int x,int g,int r)
{
	if(g == m)
	{
		long long k = 1;
		for(int i = 2;i <= n-x;i++)
		{
			k *= i;
			k %= q;
		}
		cnt += k;
		cnt %= q;
		return;
	}
	if(x == n)
		return;
	for(int i = 1;i <= n;i++)
	{
		if(!b[i])
		{
			b[i] = true;
			if(s[x] == '0' || a[i] <= r)
				dfs(x+1,g,r+1);
			else
				dfs(x+1,g+1,r);
			b[i] = false;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int l = 0;
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	int len = s.size();
	for(int i = 0;i <= len;i++)
		if(s[i] == '1')
			l++;
	if(l < m)
	{
		cout << 0;
		return 0;
	}
	dfs(0,0,0);
	cout << cnt;
	return 0;
}
