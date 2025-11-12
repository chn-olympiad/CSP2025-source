#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int n, g;
long long ans;

int a[N + 5][5];
int b[N + 5];


void dfs(int i, int A, int B, long long sum)
{
	if(A > g || B > g || i - 1 - A - B > g) return ;
	if(i == n + 1)
	{
		ans = max(ans, sum);
		return ;
	}
	dfs(i + 1, A + 1, B, sum + a[i][1]);
	dfs(i + 1, A, B + 1, sum + a[i][2]);
	dfs(i + 1, A, B, sum + a[i][3]);
}

struct nd {
	int c1, c2, id;
}c[N + 5];

int cs[N + 5];

bool cmp1(nd a1, nd oth)
{
	return a1.c1 - a1.c2 > oth.c1 - oth.c2; 
}

void solve()
{
	cin >> n;
	ans = 0;
	g = n / 2;
	bool pd = 1, pd2 = 1;
	long long res = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if(!(a[i][2] == 0 && a[i][3] == 0)) pd = 0;
		if(!(a[i][3] == 0)) pd2 = 0;
		res += max(a[i][1], max(a[i][2], a[i][3]));
	}
	if(pd)
	{
		for(int i = 1; i <= n; i++) b[i] = a[i][1];
		sort(b + 1, b + n + 1, greater<int>());
		for(int i = 1; i <= n / 2; i++) ans += b[i];
	}
	else if(n <= 10)dfs(1, 0, 0, 0);
	else if(pd2)
	{
		for(int i = 1; i <= n; i++)
		{
			c[i].c1 = a[i][1]; c[i].c2 = a[i][2];
		} 
		sort(c + 1, c + n + 1, cmp1);
		for(int i = 1; i <= n / 2; i++) ans += c[i].c1;
		for(int i = n / 2 + 1; i <= n; i++) ans += c[i].c2;
	}
	else 
	{
		for(int i = 1; i <= n; i++)
		{
			c[i].c1 = a[i][1]; c[i].c2 = a[i][2]; c[i].id = i;
		} 
		sort(c + 1, c + n + 1, cmp1);
		for(int i = 1; i <= n / 2; i++) ans += c[i].c1;
		for(int i = n / 2 + 1; i <= n; i++) ans += c[i].c2;
		for(int i = 1; i <= n / 2; i++)
		{
			cs[i] = a[c[i].id][3] - c[i].c1;
		}
		for(int i = n / 2 + 1; i <= n; i++)
		{
			cs[i] = a[c[i].id][3] - c[i].c2;
		}
		sort(cs + 1, cs + n + 1, greater<int>());
		for(int i = 1; i <= n / 2; i++)
		{
			if(cs[i] > 0) ans += cs[i];
		}
	}
	cout << ans  << '\n';
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;
} 