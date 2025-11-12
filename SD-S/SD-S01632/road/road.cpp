#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 1e4+55, MAXM = 2e6+55, MAXK = 15;
long long n, m, k, fa[MAXN];
long long c[MAXK], a[MAXK][MAXN];
struct Edge { int u, v, w; } edges[MAXM];

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void init()
{
	for(int i = 1;i <= n;i++) fa[i] = i;
	return;
}

int find(int x)
{
	if(x == fa[x]) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void Kruskal()
{
//	cout << m << endl;
	long long ans = 0;
	init();
	sort(edges+1, edges+m+1, cmp);
	for(int i = 1, cnt = 0;cnt < n-1;i++)
	{
		int nowu = edges[i].u, nowv = edges[i].v, noww = edges[i].w;
		int fau = find(nowu), fav = find(nowv);
		if(fau == fav) continue;
		fa[fau] = fav;
		ans += noww;
		cnt++;
//		cerr << cnt << endl;
	}
	cout << ans << endl;
	return;
}

void solveA()
{
	long long st;
	for(int i = 1;i <= k;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[i][j] != 0) continue;
			st = j; break;
		}
		for(int j = 1;j <= n;j++)
		{
			if(j == st) continue;
			edges[++m].u = st, edges[m].v = j, edges[m].w = a[i][j];
		}
	}
	Kruskal();
	return;
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
	bool flag1, flag = true;
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		if(c[i] != 0) flag = false;
		flag1 = false;
		for(int j = 1;j <= n;j++)
		{
//			printf("%d ", j);
			cin >> a[i][j];
//			if(a[i][j] == 0) printf("Yes");
			if(a[i][j] == 0) flag1 = true;
		}
//		if(flag1 == false) printf("%d\n", i);
		if(flag1 == false) flag = false;
	}
	if(k == 0) Kruskal();
	else if(flag == true) solveA();
	return 0;
}
/*
4 4 0
1 4 6
2 4 5
2 3 7
3 4 4
*/
