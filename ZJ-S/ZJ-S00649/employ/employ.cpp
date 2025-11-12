#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int n, m, a[505], used[505], res, ansss[505];
char c[505];
int A(int x, int y)
{
	int ans = 1;
	for(int i = x; i >= x - y + 1; i--)
		ans = (ans * i) % mod;
	return ans;
}
void dfs(int x, int y)
{
	if(x == n + 1)
	{
		if(y >= m) res = (res + 1) % mod;
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(used[i] == 1) continue;
		if((x - y - 1) >= a[i] && a[i] != 0) continue;
		used[i] = 1;
		dfs(x + 1, y + c[x] - '0');
		used[i] = 0;
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int t = 0;
	for(int i = 1; i <= n; i++)
		if(c[i] != '1') t = 1;
	if(t == 0)
	{
		cout << A(n, n) % mod << endl;
		return 0;
	}
	dfs(1, 0);
	cout << res << endl;
    return 0;
}
