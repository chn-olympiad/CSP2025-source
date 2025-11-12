#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
const int K = 11;
int n, m, k, cnt, ans;
struct node
{
	int u, v, w;
}a[N];
int b[K][N], c[K], d[N][N], v[N], t[N];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			d[i][j] = INT_MAX - 1;
		}
	}
	for(int i = 1; i <= n; i++) d[i][i] = 0;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
		d[a[i].u][a[i].v] = a[i].w;
		d[a[i].v][a[i].u] = a[i].w; 
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> c[i];
		for(int j = 1; j <= n; j++)
		{
			cin >> b[i][j];
		}
	}
	for(int l = 1; l <= k; l++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], b[l][i] + b[l][j] + c[l]);
			}
		}
	}
	v[1] = 1;
	for(int i = 1; i < n; i++)
	{
		int minn = INT_MAX, minj;
		for(int j = 1; j <= n; j++)
		{
			if(!v[j])
			{
				for(int l = 1; l <= n; l++)
				{
					if(d[j][l] < minn && v[l])
					{
						minn = d[j][l];
						minj = j;
					}
				}
			}
		}
		ans += minn;
		v[minj] = 1;
	}
	cout << ans << "\n";
	return 0;
}
