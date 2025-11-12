#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 510;
ll n, m, c[N], ans, now[N];
string s;
bool st[N];
bool check()
{
	ll cnt = 0, res = 0;
	for(ll i = 0; i < n; i ++)
	{
		if(s[i] == '0') cnt ++;
		else if(cnt >= c[now[i + 1]]) cnt ++;
		else res ++;
	}
	if(res >= m) return true;
	else return false;
}
void dfs(ll x)
{
	if(x == n + 1)
	{
		if(check()) ans ++;
		return;
	}
	for(ll i = 1; i <= n; i ++)
	{
		if(st[i]) continue;
		st[i] = true;
		now[x] = i;
		dfs(x + 1);
		st[i] = false;
		now[x] = false;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for(ll i = 1; i <= n; i ++) cin >> c[i];
	dfs(1);
	cout << ans << endl;
	return 0;
}
