#include <bits/stdc++.h>

using namespace std;

const int N = 11010;
const int K = 1500010;
#define pii pair<int, pair<int, int>>
#define x first
#define y second

int n, m, k;
pii w[K], q[K];
int p[N];
long long res = 0;
int cw[15];
int bw[15][N];

int fd(int x)
{
	if (p[x] != x) p[x] = fd(p[x]);
	return p[x];
}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
		scanf("%d%d%d", &w[i].y.x, &w[i].y.y, &w[i].x);
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d", &cw[i]);
		for (int j = 1; j <= n; j ++)
			scanf("%d", &bw[i][j]);
	}
	sort(w + 1, w + m + 1);
	for (int i = 1; i <= n; i ++)
		p[i] = i;
		
	int cnt = 0;
	for (int i = 1; i <= m; i ++)
	{
		int a = w[i].y.x, b = w[i].y.y;
		int c = w[i].x;
		a = fd(a), b = fd(b);
		if (a == b) continue;
		q[++ cnt] = {c, {a, b}};
		p[a] = b;
		res += c;
		if (cnt == n - 1) break;
		//q[++ cnt] = w[i];
	}
	//printf("%lld\n", res);
	
	for (int e = 1; e < (1 << k); e ++)
	{
		int cntk = 0;
		int cntq = cnt;
		long long sum = 0;
		for (int i = 0; i < k; i ++)
		{
			if ((e >> i) & 1)
			{
				cntk ++;
				for (int j = 1; j <= n; j ++)
					q[++ cntq] = {bw[i + 1][j], {i + 1 + n, j}};
				sum += cw[i + 1];
			}
		}
		sort(q + 1, q + 1 + cntq);
		int nn = n + cntk - 1;
		for (int i = 1; i <= n + k + 5; i ++) p[i] = i;
		int cc = 0;
		for (int i = 1; i <= cntq; i ++)
		{
			int a = q[i].y.x, b = q[i].y.y;
			int c = q[i].x;
			a = fd(a), b = fd(b);
			if (a == b) continue;
			p[a] = b;
			sum += c;
			cc ++;
			if (cc == nn) break;
		}
		res = min(res, sum);
	}
	printf("%lld\n", res);
	
	return 0;
}
