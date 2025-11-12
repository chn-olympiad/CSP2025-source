#include <bits/stdc++.h>
using namespace std;

int n, pa, pb, pc;

struct md
{
	int t;
}xa[100005], xb[100005];

struct node
{
	int x, y, z;
}w[100005];

vector<int> a, b, c, other;

void solveA()
{
	vector<int> SA;
	for (int i = 1; i <= n; i++)
	{
		SA.push_back(w[i].x);
	}
	sort(SA.begin(), SA.end());
	int ans = 0;
	for (int i = n - 1; i >= (n >> 1); i--)
	{
		ans += SA[i];
	}
	printf("%d\n", ans);
	return ;
}

bool cmpa(md l, md r)
{
	return (w[l.t].x - w[l.t].y > w[r.t].x - w[r.t].y);
}

bool cmpb(md l, md r)
{
	return (w[l.t].y - w[l.t].x > w[r.t].y - w[r.t].x);
}

void solveB()
{
	int pa = 0, pb = 0;
	for (int i = 1; i <= n; i++)
	{
		if (w[i].x > w[i].y)
		{
			xa[++pa] = {i};
		}
		else
		{
			xb[++pb] = {i};
		}
	}
	sort(xa + 1, xa + pa + 1, cmpa);
	sort(xb + 1, xb + pb + 1, cmpb);
	if (pb > pa)
	{
		for (int i = pb; i > (n >> 1); i--)
		{
			xa[++pa] = xb[i];
			xb[i].t = 0;
			pb--;
		}
	}
	else if (pb < pa)
	{
		for (int i = pa; i > (n >> 1); i--)
		{
			xb[++pb] = xa[i];
			xa[i].t = 0;
			pa--;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += w[xa[i].t].x + w[xb[i].t].y;
	}
	printf("%d\n", ans);
	return ;
}

void solve()
{
	pa = 0;
	pb = 0;
	pc = 0;
	a.clear();
	b.clear();
	c.clear();
	other.clear();
	scanf("%d", &n);
	int b0 = 0, c0 = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &w[i].x, &w[i].y, &w[i].z);
		b0 += w[i].y == 0;
		c0 += w[i].z == 0;
	}
	if (b0 == n && c0 == n)
	{
		solveA();
		return ;
	}
	else if (c0 == n)
	{
		solveB();
		return ;
	}
	for (int i = 1; i <= n; i++)
	{
		if (w[i].x > w[i].y && w[i].x > w[i].z)
		{
			a.push_back(i);
			pa++;
		}
		else if (w[i].y > w[i].x && w[i].y > w[i].z)
		{
			b.push_back(i);
			pb++;
		}
		else if (w[i].z > w[i].x && w[i].z > w[i].y)
		{
			c.push_back(i);
			pc++;
		}
		else
		{
			other.push_back(i);
		}
	}
	if (pa > (n >> 1))
	{
		for (; pa - (n >> 1) > 0; )
		{
			int Max = -40005, p = 0;
			for (int j = 0; j < a.size(); j++)
			{
				if (a[j] == 0) continue;
				if (max(w[a[j]].y - w[a[j]].x, w[a[j]].z - w[a[j]].x) > Max)
				{
					Max = max(w[a[j]].y - w[a[j]].x, w[a[j]].z - w[a[j]].x);
					p = j;
				}
			}
			if (w[a[p]].y - w[a[p]].x > w[a[p]].z - w[a[p]].x)
			{
				b.push_back(a[p]);
				pb++;
				a[p] = 0;
				pa--;
			}
			else
			{
				c.push_back(a[p]);
				pc++;
				a[p] = 0;
				pa--;
			}
		}
	}
	else if (pb > (n >> 1))
	{
		for (; pb - (n >> 1) > 0; )
		{
			int Max = -40005, p = 0;
			for (int j = 0; j < b.size(); j++)
			{
				if (b[j] == 0) continue;
				if (max(w[b[j]].x - w[b[j]].y, w[b[j]].z - w[b[j]].y) > Max)
				{
					Max = max(w[b[j]].x - w[b[j]].y, w[b[j]].z - w[b[j]].y);
					p = j;
				}
			}
			if (w[b[p]].x - w[b[p]].y > w[b[p]].z - w[b[p]].y)
			{
				a.push_back(b[p]);
				pa++;
				b[p] = 0;
				pb--;
			}
			else
			{
				c.push_back(b[p]);
				pc++;
				b[p] = 0;
				pb--;
			}
		}
	}
	else if (pc > (n >> 1))
	{
		for (; pc - (n >> 1) > 0; )
		{
			int Max = -40005, p = 0;
			for (int j = 0; j < c.size(); j++)
			{
				if (c[j] == 0) continue;
				if (max(w[c[j]].x - w[c[j]].z, w[c[j]].y - w[c[j]].z) > Max)
				{
					Max = max(w[c[j]].x - w[c[j]].z, w[c[j]].y - w[c[j]].z);
					p = j;
				}
			}
			if (w[c[p]].x - w[c[p]].z > w[c[p]].y - w[c[p]].z)
			{
				a.push_back(c[p]);
				pa++;
				c[p] = 0;
				pc--;
			}
			else
			{
				b.push_back(c[p]);
				pb++;
				c[p] = 0;
				pc--;
			}
		}
	}
	for (int i = 0; i < other.size(); i++)
	{
		if (w[other[i]].x == w[other[i]].y && w[other[i]].y == w[other[i]].z)
		{
			if (pa <= pb && pa <= pc)
			{
				a.push_back(other[i]);
				pa++;
			}
			else if (pb <= pa && pb <= pc)
			{
				b.push_back(other[i]);
				pb++;
			}
			else
			{
				c.push_back(other[i]);
				pc++;
			}
		}
		else if (w[other[i]].x == w[other[i]].y)
		{
			if (pa < pb)
			{
				a.push_back(other[i]);
				pa++;
			}
			else
			{
				b.push_back(other[i]);
				pb++;
			}
		}
		else if (w[other[i]].x == w[other[i]].z)
		{
			if (pa < pc)
			{
				a.push_back(other[i]);
				pa++;
			}
			else
			{
				c.push_back(other[i]);
				pc++;
			}
		}
		else
		{
			if (pb < pc)
			{
				b.push_back(other[i]);
				pb++;
			}
			else
			{
				c.push_back(other[i]);
				pc++;
			}
		}
	}
	int suma = 0, sumb = 0, sumc = 0;
	for (int i = 0; i < a.size(); i++)
	{
		suma += w[a[i]].x;
	}
	for (int i = 0; i < b.size(); i++)
	{
		sumb += w[b[i]].y;
	}
	for (int i = 0; i < c.size(); i++)
	{
		sumc += w[c[i]].z;
	}
	printf("%d\n", suma + sumb + sumc);
	return ;
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
