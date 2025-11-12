#include <bits/stdc++.h>
using namespace std;

long long read()
{
	long long ac = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ac = (ac << 1) + (ac << 3) + c - 48, c = getchar();
	return ac;
}

long long n, m, k, f[10005], c[15], c2[15][10005], cnt;
struct node
{
	long long u, v, w;
}heap[1000005];

void pop()
{
	long long idx = 1, t = 2; heap[1] = heap[cnt --];
	
	while (t <= cnt)
	{
		if (t + 1 <= cnt && heap[t + 1].w < heap[t].w) t ++;
		if (heap[t].w < heap[idx].w) swap(heap[t].w, heap[idx].w);
		idx = t, t *= 2;
	}
}
void insert()
{
	int cnt1 = cnt;
	while (cnt1 / 2 && heap[cnt1 / 2].w > heap[cnt1].w) swap(heap[cnt1].w, heap[cnt1 / 2].w), cnt1 /= 2;
}

bool cmp(node x, node y)
{
	return x.w < y.w;
}
long long find(int x)
{
	if (f[x] == x) return x;
	f[x] = find(f[x]);
	return f[x];
}
bool xc[15];

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; ++ i) f[i] = i;
	for (int i = 1; i <= m; ++ i) heap[++ cnt].u = read(), heap[cnt].v = read(), heap[cnt].w = read(), insert();

	for (int i = 1; i <= k; ++ i)
	{
		c[i] = read();
		for (int j = 1; j <= n; ++ j) c2[i][j] = read();
	}
	
//	if (k == 0)
	{
		long long ans = 0;
		for (int i = 1, cnt2 = 0; i <= m && cnt2 < n - 1; ++ i)
		{
			int fx = find(heap[1].u), fy = find(heap[1].v);
			if (fx == fy) continue;
			f[heap[1].u] = fy;
			ans += heap[1].w;
			pop();
			++ cnt2;
		}
		cout << ans << "\n";
	}
	

	fclose(stdin);
	fclose(stdout);

	return 0;
}
