#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;
const int maxm = 18;
const int mod = 998244353;


long long n, m, ans, cnt;
int s[maxn + 5];
int c[maxn + 5];
int cs[maxn + 5];
bool vis[maxn + 5];
int f[maxm + 1][maxm + 1][(1 << maxm) + 1];
void dfs(int step)
{
	if(step == n + 1)
	{
		if(cnt >= m) ++ans;
		return;
	}
	int sta = 0;
	for(int i = 1; i <= n; ++i)
		if(vis[i])
			sta |= (1 << (i-1));
	if(~f[cnt][step][sta])
	{
		ans += f[cnt][step][sta];
		return;
	}
	int nowans = ans; 
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			cs[step] = i;
			int lstcnt = cnt;
			if(s[step] == 0 || (step - 1 - cnt) >= c[i]);
			else ++cnt;
			dfs(step + 1);
			vis[i] = 0;
			cnt = lstcnt;
		}
	}
	f[cnt][step][sta] = ans - nowans;
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	memset(f, 0xff, sizeof(f));
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
	{
		char v;
		cin >> v;
		if(v & 1) s[i] = 1;
		else s[i] = 0;
	}
	for(int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	if(n <= 18)
	{
		dfs(1);
		cout << ans % mod << endl;
	}
	return 0;
}