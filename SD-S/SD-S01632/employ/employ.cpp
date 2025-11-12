#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN = 1e5+55, modb = 998244353;
long long n, m, c[MAXN], p[MAXN], vis[MAXN], ans;
char s[MAXN];

inline long long modmul(long long x, long long y) { return ((x % modb) * (y % modb)) % modb; }

long long fac(long long x)
{
	long long res = 1;
	for(int i = 1;i <= x;i++) res = modmul(res, i);
	return res % modb;
}

void dfs(int now)
{
	if(now > n)
	{
		int cnt = 0, f = 0;
		for(int i = 1;i <= n;i++)
		{
//			printf("%d ", p[i]);
			if(f >= c[p[i]]) f++;
			else if(s[i] == '0') f++;
			else cnt++;
//			printf("%d %d\n", f, cnt);
		}
//		printf("\n");
		if(cnt >= m) ans++;
	}
	for(int i = 1;i <= n;i++)
	{
		if(vis[i] == 1) continue;
		vis[i] = 1;
		p[now] = i;
		dfs(now+1);
		vis[i] = 0;
		p[now] = 0;
	}
}

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> s[i];
	for(int i = 1;i <= n;i++) cin >> c[i];
	if(m == n)
	{
		ans = fac(n);
		bool flag = true;
		for(int i = 1;i <= n;i++)
		{
			if(s[i] == '0') { flag = false; break; }
			if(c[i] == 0) { flag = false; break; }
		}
		if(flag == false) cout << 0 << endl;
		else cout << ans << endl;
	}
	else
	{
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
/*
3 2
101
1 1 2
*/
