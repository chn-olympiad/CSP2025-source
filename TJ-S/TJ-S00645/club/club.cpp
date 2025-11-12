#include <bits/stdc++.h>
using namespace std;
const int N = 220000;
int t,n,cnt,cnt1,cnt2,cnt3,b[N],c1,c2,c3,k;
struct Point
{
	int v;
	int a;
};
bool cmp(Point &p,Point &q)
{
	return p.a < q.a;
}
Point a1[N],a2[N],a3[N],aa1[N],aa2[N],aa3[N],a[3][N];
long long ans;
int main()
{
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int m = 1;m <= t;m++)
	{
		for (int i = 1;i <= n;i++)
		{
			a1[i].v = 0;
			a1[i].a = 0;
			a2[i].v = 0;
			a2[i].a = 0;
			a3[i].v = 0;
			a3[i].a = 0;
			aa1[i].v = 0;
			aa1[i].a = 0;
			aa2[i].v = 0;
			aa2[i].a = 0;
			aa3[i].v = 0;
			aa3[i].a = 0;
			a[1][i].v = 0;
			a[1][i].a = 0;
			a[2][i].v = 0;
			a[2][i].a = 0;
			a[3][i].v = 0;
			a[3][i].a = 0;
			b[i] = 0;
		}
		ans = 0;
		cnt1 = 0;
		cnt2 = 0;
		cnt3 = 0;
		cnt = 0;
		c1 = 0;
		c2 = 0;
		c3 = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			a[1][i] = (Point){i,x};
			a[2][i] = (Point){i,y};
			a[3][i] = (Point){i,z};
			a1[i] = (Point){i,x};
			a2[i] = (Point){i,y};
			a3[i] = (Point){i,z};
			aa1[i] = (Point){i,x};
			aa2[i] = (Point){i,y};
			aa3[i] = (Point){i,z};
		}
		sort(a1 + 1,a1 + n + 1,cmp);
		sort(aa1 + 1,aa1 + n + 1,cmp);
		k = 0;
		int f;
		for (int i = n;i >= 1;i--)
		{
			if (c1 >= n / 2)
			{
				k = 1;
				break;
			}
			int w = aa1[i].a;
			int u = aa1[i].v;
			if (w >= aa2[u].a && w >= aa3[u].a)
			{
				c1++;
				f = i;
			} 
		}
		if (k) f--;
		for (int i = n;i >= 1;i--)
		{
			if (cnt1 >= n / 2) break;
			int w = a1[i].a;
			int u = a1[i].v;
			if (w >= a2[u].a && w >= a3[u].a)
			{
				if (k)
				{
					if (a1[f].a > max(a2[a1[f].v].a,a3[a1[f].v].a) && (w - max(a2[u].a,a3[u].a)) <= a1[f].a)
					{
						
						cnt1++;
						cnt++;
						b[a1[f].v] = 1;
						ans += a1[f].a;
						continue;
					}
				}
				cnt1++;
				cnt++;
				b[u] = 1;
				ans += w;
			} 
		}
		sort(a2 + 1,a2 + n + 1,cmp);
		sort(aa2 + 1,aa2 + n + 1,cmp);
		k = 0;
		f = 0;
		for (int i = n;i >= 1;i--)
		{
			if (c2 >= n / 2)
			{
				k = 1;
				break;
			}
			int w = aa2[i].a;
			int u = aa2[i].v;
			if (w >= aa3[u].a)
			{
				c2++;
				f = i;
			} 
		}
		if (k) f--;
		for (int i = n;i >= 1;i--)
		{
			if (cnt2 >= n / 2 || cnt >= n) break;
			int w = a2[i].a;
			int u = a2[i].v;
			if (b[u]) continue;
			if (w >= a3[u].a)
			{
				if (k)
				{
					if (a2[f].a > a3[a1[f].v].a && w - a3[u].a <= a1[f].a)
					{
						cnt2++;
						cnt++;
						b[a1[f].v] = 1;
						ans += a1[f].a;
						continue;
					}
				}
				cnt2++;
				cnt++;
				b[u] = 2;
				ans += w;
			} 
		}
		sort(a3 + 1,a3 + n + 1,cmp);
		k = 0;
		f = 0;
		for (int i = n;i >= 1;i--)
		{
			if (c3 >= n / 2)
			{
				k = 1;
				break;
			}
			int w = a3[i].a;
			int u = a3[i].v;
			c3++;
			f = i;
		}
		if (k) f--;
		for (int i = n;i >= 1;i--)
		{
			if (cnt3 >= n / 2 || cnt >= n) break;
			int w = a3[i].a;
			int u = a3[i].v;
			if (b[u]) continue;
			cnt3++;
			cnt++;
			b[u] = 3;
			ans += w;
		}
		if (cnt < n)
		{
			for (int i = 1;i <= n;i++)
			{
				if (!b[i])
				{
					if (a[1][i].a >= a[2][i].a)
					{
						cnt++;
						cnt1++;
						ans += a[1][i].a;
					}
					else
					{
						cnt++;
						cnt2++;
						ans += a[2][i].a;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
