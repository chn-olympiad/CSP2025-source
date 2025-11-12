#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
struct Node
{
	int x,y,z;
} a [N];
int dp [N] [3],s [N] [3];
bool cmp1 (Node x,Node y)
{
	if (x.x != y.x) return x.x > y.x;
	if (x.y != y.y) return x.y > y.y;
	if (x.z != y.z) return x.z > y.z;
}
bool cmp2 (Node x,Node y)
{
	if (x.y != y.y) return x.y > y.y;
	if (x.x != y.x) return x.x > y.x;
	if (x.z != y.z) return x.z > y.z;
}
bool cmp3 (Node x,Node y)
{
	if (x.z != y.z) return x.z > y.z;
	if (x.x != y.x) return x.x > y.x;
	if (x.y != y.y) return x.y > y.y;
}
int n,ans;
void dfs (int h,int f1,int f2,int f3,int s)
{
	if (h == n + 1)
	{
		ans = max (ans,s);
		return ;
	}
	if (f1 < n / 2) dfs (h + 1,f1 + 1,f2,f3,s + a [h].x);
	if (f2 < n / 2) dfs (h + 1,f1,f2 + 1,f3,s + a [h].y);
	if (f3 < n / 2) dfs (h + 1,f1,f2,f3 + 1,s + a [h].z);
}
void solve ()
{
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a [i].x >> a [i].y >> a [i].z,dp [i] [0] = dp [i] [1] = dp [i] [2] = 0;
	if (n <= 10)
	{
		dfs (1,0,0,0,0);
		cout << ans << endl;
		return ;
	}
	ans = 0;
	sort (a + 1,a + n + 1,cmp1);
	int s = 0,f1 = 0,f2 = 0,f3 = 0;
	for (int k = 1;k <= n;k ++)
	{
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].x,f1 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
		ans = max (ans,s);
	//	cout << s  << ' ' << f1 << ' ' << f2 << ' ' << f3<< endl;
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].y,f2 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
	//	cout << s << endl;
		ans = max (ans,s);
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].z,f3 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
	//	cout << s << endl;
		ans = max (ans,s);
	}
	sort (a + 1,a + n + 1,cmp2);
	s = 0,f1 = 0,f2 = 0,f3 = 0;
	for (int k = 1;k <= n;k ++)
	{
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].x,f1 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
		ans = max (ans,s);
	//	cout << s << endl;
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].y,f2 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
	//	cout << s << endl;
		ans = max (ans,s);
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].z,f3 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
		ans = max (ans,s);
	//	cout << s << endl;
	}
	sort (a + 1,a + n + 1,cmp3);
	s = 0,f1 = 0,f2 = 0,f3 = 0;
	for (int k = 1;k <= n;k ++)
	{
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].x,f1 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
		ans = max (ans,s);
	//	cout << s << endl;
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].y,f2 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
	//	cout << s << endl;
		ans = max (ans,s);
		s = 0,f1 = 0,f2 = 0,f3 = 0;
		s = a [k].z,f3 = 1;
		for (int i = 1;i <= n;i ++)
		{
			if (i == k) continue;
			if (f1 < n / 2)
			{
				if (f2 < n / 2 && f3 == n / 2)
				{
					if (a [i].x > a [i].y) s += a [i].x,f1 ++;
					else s += a [i].y,f2 ++;
				}
				else if (f2 == n / 2 && f3 < n / 2)
				{
					if (a [i].x > a [i].z) s += a [i].x,f1 ++;
					else s += a [i].z,f3 ++;
				}
				else
				{
					if (a [i].x > a [i].y && a [i].x > a [i].z) s += a [i].x,f1 ++;
					else if (a [i].y > a [i].x && a [i].y > a [i].z) s += a [i].y,f2 ++;
					else s += a [i].z,f3 ++;
				}
			}
			else
			{
				if (a [i].z > a [i].y) s += a [i].z,f3 ++;
				else s += a [i].y,f2 ++;
			}
		}
		ans = max (ans,s);
//		cout << s << endl;
	}
	ans = max (ans,s);
	cout << ans << endl;
}
signed main ()
{
	freopen("club4.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while (T --) solve ();
	return 0;
}