#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int maxn = 510;
int s[maxn],c[maxn];
bool vis[11];
int a[11];
int ans = 0;
const int mod = 998244353;
void check()
{
	int cnt = 0;
	int res = 0;
	for(int i = 1;i <= n;i++)
	{
		if(cnt >= c[a[i]] || !s[i]) cnt++;
		else res++;
	}
	if(res >= m) ans++;
	if(ans >= mod) ans -= mod;
	return;
}
void dfs(int pos)
{
	if(pos == n + 1) 
	{
		check();
		return;
	}
	for(int i = 1;i <= n;i++)
		if(!vis[i]) 
		{
			vis[i] = 1;
			a[pos] = i;
			dfs(pos + 1);
			vis[i] = 0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	string st;cin >> st;
	for(int i = 1;i <= n;i++) s[i] = st[i - 1] - '0';
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(n <= 10)
	{
		dfs(1);
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
