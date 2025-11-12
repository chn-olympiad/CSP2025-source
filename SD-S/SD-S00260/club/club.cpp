# include <bits/stdc++.h>
using namespace std;
# define int long long 
typedef long long ll;
typedef unsigned long long ull;
# define lc (u << 1)
# define rc (u << 1 | 1)
# define fi first
# define se second
const int N = 100005;

int n;
struct node
{
	int x, y, z;
	int mx, smx, chs;
} a[N];
signed main ()
{
	freopen ("club.in", "r", stdin); freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);
	int T; cin >> T;
	while (T -- )
	{
		cin >> n;
		for (int i = 1; i <= n; i ++ )
		{
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].mx = a[i].smx = 0;
		}
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i ++ )
		{
			vector <int> vec;
			vec.push_back (a[i].x);
			vec.push_back (a[i].y);
			vec.push_back (a[i].z);
			sort (vec.begin (), vec.end (), greater <int> ());
			a[i].mx = vec[0], a[i].smx = vec[1];
			if (a[i].mx == a[i].x)
				a[i].chs = 1, cnt1 ++ ;
			else if (a[i].mx == a[i].y)
				a[i].chs = 2, cnt2 ++ ;
			else if (a[i].mx == a[i].z)
				a[i].chs = 3, cnt3 ++ ;
		}
		int lim = n / 2;
		if (cnt1 <= lim && cnt2 <= lim && cnt3 <= lim)
		{
			int ans = 0;
			for (int i = 1; i <= n; i ++ )
				ans += a[i].mx;
			cout << ans << "\n";
			continue;
		}
		else
		{
			int chsmx = 0;
			if (cnt1 > lim)
				chsmx = 1;
			else if (cnt2 > lim)
				chsmx = 2;
			else if (cnt3 > lim)
				chsmx = 3;
			vector <pair <int, int>> vec;
			for (int i = 1; i <= n; i ++ )
			{
				if (a[i].chs != chsmx)
					continue;
				vec.push_back ({a[i].mx - a[i].smx, i});
			}
			sort (vec.begin (), vec.end (), greater <pair <int, int>> ());
			int ans = 0;
			for (int i = 0; i < (int)vec.size (); i ++ )
			{
				if (i < lim)
					ans += a[vec[i].se].mx;
				else
					ans += a[vec[i].se].smx;
			}
			for (int i = 1; i <= n; i ++ )
			{
				if (a[i].chs != chsmx)
					ans += a[i].mx;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
