#include<bits/stdc++.h>
#define int long long
using namespace std;
int re()
{
	int sum = 0, p = 1;
	char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')p = -1; ch = getchar();}
	while(isdigit(ch)){sum = sum * 10 + (ch - '0'); ch = getchar();}
	return sum * p;
}
const int N = 2e4 + 10, M = 1e6 + 10;
int n, m, k, mm, res, f[N], val[15];
struct info{int u, v, w;}a[M], w[15][N], e[N * 20];
int find(int k){return f[k] == k ? k : f[k] = find(f[k]);}
bool cmp(info x, info y){return x.w < y.w;}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = re(), m = re(), k = re();
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++) a[i].u = re(), a[i].v = re(), a[i].w = re();
	sort(a + 1, a + 1 + m, cmp);
	for(int i = 1; i <= m; i++)
	{
		int fx = find(a[i].u), fy = find(a[i].v);
		if(fx == fy) continue;
		f[fx] = f[fy], a[++mm] = a[i], res += a[i].w;
		if(mm == n - 1) break;
	}
	
	for(int i = 1; i <= k; i++)
	{
		val[i] = re();
		for(int j = 1; j <= n; j++) w[i][j] = {i + n, j, re()};
	}
	
	for(int S = 0; S < (1 << k); S++)
	{
		int ans = 0, tot = 0, tott = n;
		for(int i = 1; i <= k; i++)
		{
			if((S >> i - 1) & 1) 
			{
				tott++, ans += val[i];
				for(int j = 1; j <= n; j++) e[++tot] = w[i][j];
			}
		}
		if(ans > res) continue;
		for(int i = 1; i <= mm; i++) e[++tot] = a[i];
		sort(e + 1, e + 1 + tot, cmp);
		for(int i = 1; i <= n + k; i++) f[i] = i;
		for(int i = 1; i <= tot; i++)
		{
			if(ans > res) break;
			int fx = find(e[i].u), fy = find(e[i].v);
			if(fx == fy) continue;
			f[fx] = f[fy], ans += e[i].w, tott--;
			if(!tott) break;
		}
		res = min(res, ans);
	}
	cout << res;
	return 0;
}