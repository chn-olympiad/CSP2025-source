#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
const int MAXN = 1e4 + 7;

inline int read()
{
	int x = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		{
			w = -1;
		}
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	
	return w * x;
}

int n, m, k;

int ans;

vector<PII> e[MAXN];

struct vill{
	int c;
	int a[MAXN];
}vi[15];

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	
	for(int i = 1;  i <= m;  i++)
	{
		int u = read(), v = read(), w = read();
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
		ans += w;
	}
	
	for(int i = 1;  i <= k;  i++)
	{
		vi[i].c = read();
		for(int j = 1;  j <= n;  j++)
		{
			vi[i].a[j] = read();
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
