//想了一下，只会80pts
//暴力状压，把边加到最小生成树上面跑
#include<bits/stdc++.h>

using namespace std;

#define N 10005
#define M 1000005
#define int long long

bool bg; 

int n, m, K, c[15], a[15][N], CNT;
struct edge{int u, v, w;}e[M], ee[M];
bool cmp(edge x, edge y){return x.w < y.w;}
int fa[N];
void init(int nn){for(int i = 1; i <= nn; i++)fa[i] = i;}
int find(int u){return (fa[u] == u ? u : fa[u] = find(fa[u]));}
void merge(int u, int v){u = find(u), v = find(v); if(u != v)fa[u] = v;}



int kruskal(int nn, int mm, int flag)
{
	init(nn);
//	CNT += mm;
	for(int i = 1; i <= mm; i++)ee[i] = e[i];
	sort(ee + 1, ee + mm + 1, cmp);
	int sum = 0, cnt = 0, num = 0;
	for(int i = 1; i <= mm; i++)
	{
		int u = ee[i].u, v = ee[i].v, w = ee[i].w;
		if(find(u) != find(v))
		{
			sum += w, merge(u, v); num++;
			if(flag)e[++cnt] = ee[i];
		}
		if(num == nn - 1)break;
	}
	return sum;
}

void read(int &x)
{
	char ch = getchar();
	while(!('0' <= ch && ch <= '9'))ch = getchar();
	while('0' <= ch && ch <= '9')x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	read(n), read(m), read(K);
	for(int i = 1; i <= m; i++)
		read(e[i].u), read(e[i].v), read(e[i].w);
	for(int i = 1; i <= K; i++)
	{
		read(c[i]);
		for(int j = 1; j <= n; j++)read(a[i][j]);
	}
	int ans = kruskal(n, m, 1);//0/1代表存不存边 
	
	for(int sta = 1; sta < (1 << K); sta++)
	{
		int x, cnt = n - 1, cntt = 0, sum = 0;
		for(int i = 1; i <= K; i++)
			if(sta >> i - 1 & 1)
			{
				sum += c[i]; ++cntt;
				for(int j = 1; j <= n; j++)
					e[++cnt] = {n + cntt, j, a[i][j]};
			}
		x = kruskal(n + cntt, cnt, 0);
		ans = min(ans, x + sum);
	}
	
	cout << ans;
	return 0;
} 
