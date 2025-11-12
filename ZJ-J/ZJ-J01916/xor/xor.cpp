#include<bits/stdc++.h>
using namespace std;

int ans, n, k, a[100005];

int qxor(int a, int b)
{
	int c = 0, xa[64], xb[64], xc[64], xat = 0, xbt = 0, xct = 0;
	memset(xa, 0, sizeof(xa));
	memset(xb, 0, sizeof(xb));
	memset(xc, 0, sizeof(xc));
	while(a)
	{
		xa[xat++] = a % 2;
		a >>= 1;
	}
	while(b)
	{
		xb[xbt++] = b % 2;
		b >>= 1;
	}
	for(int i = 0; i < max(xat, xbt); i++)
	{
		xc[xct++] = (xa[i] == xb[i] ? 0 : 1);
	}
	for(int i = 0; i < xct; i++)
	{
		c += xc[i] * pow(2, i);
	}
	return c;
}

void dfs(int cnt, int start, int end)
{
	int xorn = a[start];
	for(int i = start + 1; i <= end; i++)
	{
		xorn = qxor(xorn, a[i]);
	}
	if(xorn == k)
	{
		cnt++;
		ans = max(cnt, ans);
		for(int i = end + 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
			{
				dfs(cnt, i, j);
			}
		}
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i; j <= n; j++)
		{
			dfs(0, i, j);
		}
	}
	cout << ans << endl;
	return 0;
}