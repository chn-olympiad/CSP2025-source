#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 3;

int n;
struct Data
{
	int a, b;
	bool operator < (const Data& W) const
	{
		return b > W.b;
	}
} q[N << 1];
int a[N], b[N], c[N];
bool st[N];
struct Data1
{
	int a, b, c;
	bool operator < (const Data1& W) const
	{
		return c > W.c;
	}
} q1[M];
int cnt1[3];

int solve(int aa[], int bb[], int cc[])
{
	int res = 0;
	for (int i = 1, idx = 0; i <= n; i ++ ) 
		res += aa[i], q[ ++ idx] = {i, bb[i] - aa[i]}, q[ ++ idx] = {i, cc[i] - aa[i]};
	sort(q + 1, q + n * 2 + 1);
	for (int i = 1; i <= n; i ++ ) st[i] = 0;
	int cnt = 0;
	for (int i = 1; i <= n * 2; i ++ )
	{
		if (!st[q[i].a]) res += q[i].b, st[q[i].a] = 1, cnt ++ ;
		if (cnt == n / 2) break;
	}
	return res;
}

int read()
{
	int s = 0, w = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-') w = -w;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T -- )
	{
		n = read();
		for (int i = 1; i <= n; i ++ ) a[i] = read(), b[i] = read(), c[i] = read();
		for (int i = 1, idx = 0; i <= n; i ++ )
		{
			q1[ ++ idx] = {i, 0, a[i]};
			q1[ ++ idx] = {i, 1, b[i]};
			q1[ ++ idx] = {i, 2, c[i]};
		}
		
		for (int i = 1; i <= n; i ++ ) st[i] = 0;
		sort(q1 + 1, q1 + 1 + n * 3);
		int res = 0;
		cnt1[0] = cnt1[1] = cnt1[2] = 0;
		for (int i = 1; i <= n * 3; i ++ )
		{
			if (st[q1[i].a]) continue;
			if (cnt1[q1[i].b] >= n / 2) continue;
			res += q1[i].c;
			st[q1[i].a] = 1, cnt1[q1[i].b] ++ ;
		}
		
		res = max(res, solve(a, b, c));
		res = max(res, solve(b, a, c));
		res = max(res, solve(c, a, b));
		
		cout << res << '\n';
	}
	
	return 0;
}
