#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 5e2 + 10;
const ll mod = 998244353;
int n,m,num;
char s[MX];
ll ans;
int c[MX];
int vis[MX];
void dfs(int dep,int ca,int cnt)
{
	if(dep > n)
	{
		if(cnt >= m) ans++;
		return;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 1) continue;
		if(c[i] <= ca)
		{
			vis[i] = 1;
			dfs(dep + 1,ca + 1,cnt);
			vis[i] = 0;
		}
		else
		{
			if(s[dep] == '0')
			{
				vis[i] = 1;
				dfs(dep + 1,ca + 1,cnt);
				vis[i] = 0;
			}
			else
			{
				vis[i] = 1;
				dfs(dep + 1,ca,cnt + 1);
				vis[i] = 0;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	cin >> s + 1;
	for(int i = 1;i <= n;i++)
	{
		cin >> c[i];
		if(c[i] == 0) num++;
	}
	bool flag = 0;
	for(int i = 1;i <= n;i++)
	{
		if(s[i] == '0')
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		if(n - num < m)
		{
			ans = 0;
		}
		else
		{
			ans = 1ll;
			for(int i = 1;i <= n;i++)
			{
				ans *= i;
				ans %= mod;
			}
		}
	}
	else if(n <= 18)
	{
		dfs(1,0,0);
	}
	cout << ans << '\n';
	return 0;
}
