#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
int n, m, k;
int p[N];
int a[11][N], c[N];

long long ans;
struct e{
	int a, b, w;
	operator<()
	{
		return w < W.w;
	}
}e[N];
int find (int x)
{
	if (x != p[x]) p[x] = find (p[x]);
	return p[x];
}

void kul()
{
	sort(e + 1, e + n + 1);
	int cnt = 0;
		for (int i = 1; i < n; i ++)
		{
		int pa = find(i), pb = find(i + 1);
		if (pa != pb)
		{
			p[pa] = pb;
			ans += e[i].w;
			cnt ++;
		}
	}
	}

int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n ; i ++ )
	p[i] = i;
	for (int i = 1;i <= m; i ++ )
	{
	int a, b, c;
	 cin >> a >> b >> c;
	 e[i] = {a, b, c};
	}
	for (int i = 1; i <= k; i ++ )
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++ )
		{
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= k; i ++ )
	{
		for (int j = 1; j <= n; j ++ )
		for (int k = 1; k <= n; k ++)
		{
			if(j != k && e[i].w > c[i] + a[i][j] + a[i][k])
			e[i].w = c[i] + a[i][j] + a[i][k];
		}
	}
	kul();
	cout << ans;
	return 0;
}
