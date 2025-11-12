#include<bits/stdc++.h>

using namespace std;
const int N = 10010;
struct ord
{
	int a, b, w;
}road[N];
bool cmp(ord& a, ord& b)
{
	if(a.w == b.w) return a.a < b.a;
	return a.w < b.w;
}

int g[N][N];
int p[N];
int n, m, k;
bool st[N];
int sum = 0;
int find(int x)
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}
void merge(int a, int b)
{
	int pa = find(a), pb = find(b);
	if(pa < pb) return merge(pb, pa);
	
	p[p[a]] = pb;
}

int prim()
{
	for(int i = 1; i <= m ; i ++)
	{
		ord t = road[i];
		int aa = t.a, bb = t.b, ww = t.w;
		if(find(aa) != find(bb))
		{
			sum += ww;
			st[aa] = 1;
			st[bb] = 1;
			merge(aa, bb);
		}
	}
	
	return sum;
}


int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n ; i ++) p[i] = i;
	for(int i = 1; i <= m ; i ++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = c;
		road[i].a = a;
		road[i].b = b;
		road[i].w = c;
	}
	
	if(k == 0)
	{
		sort(road + 1, road + m + 1, cmp);
	
		int ans = prim();
		cout << ans << "\n";
	}
	
	
	
	return 0;
}
