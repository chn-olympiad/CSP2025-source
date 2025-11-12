#include<bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 20;
int n, m, ans, a[N], p[N], vis[N];
char s[N];
void dfs(int dep, int sum)
{
	if(dep > n)
	{
		if(n - sum >= m) 
		{
			ans++;
		}
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			p[dep] = i;
			if(sum >= a[i]) dfs(dep + 1, sum + 1);
			else 
			{
				if(s[dep] == '0') dfs(dep + 1, sum + 1);
				else dfs(dep + 1, sum);
			}
			vis[i] = 0;
		}
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = re(), m = re();
	for(int i = 1; i <= n; i++) cin >> s[i];
	for(int i = 1; i <= n; i++) a[i] = re();
	dfs(1, 0);
	cout << ans;
	return 0;
}
