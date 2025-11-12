#include <bits/stdc++.h>

using namespace std;

const int N = 5000010;
typedef unsigned long long ull;
const int p1 = 131, p2 = 13331;

int n, Q;
struct node
{
	string s, ss;
	int l, mid, r;
	ull lc, mc, rc;
	ull lc2, mc2, rc2;
} a[N];
ull u[N], v[N];
ull p[N], pp[N];

ull q(int l, int r)
{
	if (l == 0) return u[r];
	return u[r] - u[l - 1] * p[r - l + 1];
}

ull qy(int l, int r)
{
	if (l == 0) return v[r];
	return v[r] - v[l - 1] * pp[r - l + 1];
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	p[0] = 1, pp[0] = 1;
	for (int i = 1; i < N - 5; i ++)
		p[i] = p[i - 1] * p1,
		pp[i] = pp[i - 1] * p2;
	for (int i = 1; i <= n; i ++)
	{
		string x, y;
		cin >> x >> y;
		int sz = x.size();
		int l = 0, r = sz - 1;
		while (l < sz && x[l] == y[l]) l ++;
		while (r >= l && x[r] == y[r]) r --;
		a[i].l = l;
		a[i].r = sz - r - 1;
		a[i].mid = r - l + 1;
		ull c = 0, cc = 0;
		for (int i = 0; i < l; i ++)
			c = c * p1 + x[i] - 'a',
			cc = cc * p2 + y[i] - 'a';
		a[i].lc = c, a[i].lc2 = cc;
		c = 0, cc = 0;
		for (int i = l; i <= r; i ++)
			c = c * p1 + x[i] - 'a',
			cc = cc * p2 + y[i] - 'a';
		a[i].mc = c, a[i].mc2 = cc;
		c = 0, cc = 0;
		for (int i = r + 1; i < sz; i ++)
			c = c * p1 + x[i] - 'a',
			cc = cc * p2 + y[i] - 'a';
		a[i].rc = c, a[i].rc2 = cc;
	}
	while (Q --)
	{
		string x, y;
		cin >> x >> y;
		int sz = x.size(), sy = y.size();
		if (sz != sy)
		{
			puts("0");
			continue;
		}
		int l = 0, r = sz - 1;
		while (l < sz && x[l] == y[l]) l ++;
		while (r >= l && x[r] == y[r]) r --;
		u[0] = x[0] - 'a', v[0] = y[0] - 'a';
		for (int i = 1; i < sz; i ++)
			u[i] = u[i - 1] * p1 + x[i] - 'a',
			v[i] = v[i - 1] * p2 + y[i] - 'a';
		int res = 0;
		for (int i = 1; i <= n; i ++)
		{
			if (q(l, r) != a[i].mc || qy(l, r) != a[i].mc2) continue;
			if (l < a[i].l) continue;
			if (sz - r - 1 < a[i].r) continue;
			if (q(r + 1, r + a[i].r) != a[i].rc || qy(r + 1, r + a[i].r) != a[i].rc2) continue;
			if (q(l - a[i].l, l - 1) != a[i].lc || qy(l - a[i].l, l - 1) != a[i].lc2) continue;
			res ++;
		}
		printf("%d\n", res);
	}
	
	return 0;
}
