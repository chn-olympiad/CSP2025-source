#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N = 510, MOD = 998244353;
int n, m, g[N], s[N], c[N];
LL ans = 1, cnt;
bool st[N];
void read(int &s)
{
	s = 0; int f = 1; char c = getchar();
	for(; c < 48 || c > 57; c = getchar()) (c == '-') && (f = -1);
	for(; c >= 48 && c <= 57; c = getchar()) s = (s << 1) + (s << 3) + (c ^ 48);
	s *= f;
	return;
}
void dfs(int step, int sum)
{
	if(step == n + 1)
	{
		if(sum >= m) ans ++;
		return;
	}
	//if(sum + n - step + 1 < m) return;
	for(int i = 1; i <= n; i ++)
	{
		if(st[i]) continue;
		g[step] = i;
		st[i] = 1;
		dfs(step + 1, (sum - step >= m || s[step] == 0) ? sum : sum + 1);
		st[i] = 0;
	}
}
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	read(n), read(m);
	string a;
	cin >> a;
	for(int i = 0; i < n; i ++) s[i + 1] = a[i] - '0';
	for(int i = 1; i <= n; i ++)
	{
		read(c[i]);
		if(c[i] == 0) cnt ++;
	}
	if(n - cnt >= m)
		for(int i = 1; i <= n; i ++) ans = (ans * i) % MOD;
	else if(n - cnt + 1 < m) ans = 0;
	else{
		for(int i = 1; i < n; i ++) ans = (ans * i) % MOD;
		ans = (ans * cnt) % MOD;
	}
	cout << ans << endl;
	return 0;
}
