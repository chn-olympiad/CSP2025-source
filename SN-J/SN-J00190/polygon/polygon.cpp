#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 5010;
const int Modd = 998244353;
ll n, a[N], ans, f[N], g[N];
bool st[N];
bool check()
{
	ll maxx = 0, sum = 0, cnt = 0;
	for(ll i = 1; i <= n; i ++)
	{
		if(!st[i]) continue;
		st[i] = true;
		maxx = max(maxx, a[i]);
		sum += a[i];
		cnt ++;
	}
	if(cnt < 3) return false;
	if(sum > maxx * 2) return true;
	else return false;
}
void dfs(ll x)
{
	if(x == n + 1)
	{
		if(check()) ans = (ans + 1) % Modd;
		return;
	}
	st[x] = true;
	dfs(x + 1);
	st[x] = false;
	dfs(x + 1);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	cin >> n;
	for(ll i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	dfs(1);
	cout << ans << endl;
	return 0;
}
