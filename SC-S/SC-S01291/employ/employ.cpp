#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 505;
const long long Mod = 998244353;

int n, m, ans;
char a[N];
int c[N];
int pre[N];

bool pd[N];
int id[N];

void check()
{
	int g = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == '0' || g >= c[id[i]]) g++;
	}
	if(n - g >= m) ans++;
}

void dfs(int now)
{
	if(now == n + 1)
	{
		check();
		return ;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!pd[i])
		{
			pd[i] = 1;
			id[now] = i;
			dfs(now + 1);
			pd[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + (a[i] == '0');
	int g = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
		g = g + (c[i] == 0);
	} 
	if(n <= 10)
	{
		dfs(1);
		cout << ans << '\n';
		return 0;
	}
	if(m > n - max(pre[n], g))
	{
		cout << "0\n";
		return 0;
	}
	else
	{
		long long a = 1;
		for(int i = 1; i <= n; i++) a = (a * i) % Mod;
		cout << a << '\n';
	}
	
	return 0;
} 