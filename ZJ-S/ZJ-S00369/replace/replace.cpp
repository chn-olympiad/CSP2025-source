#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
//pair <int, int >a[N];
struct Node{
	int x, y, l, r;
	bool operator < (const Node k1) {return x < k1.x;}
}a[N];

signed main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie (0), cout.tie (0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
	{
		int x = 0, y = 0, l, r;
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < s1.size (); j ++)
		{
			if (s1[j] == 'b') l = x = j, r = y = s1.size () - j - 1;
		}
		for (int j = 0; j < s2.size (); j ++)
		{
			if (s2[j] == 'b') x -= j, y -= s2.size () - j - 1;
		}
		a[i] = {x, y, l, r};
	}
	sort (a + 1, a + n + 1);
//	for (int i = 1; i <= n; i ++) cout << a[i].x << " " << a[i].y << " " << a[i].l << " " << a[i].r << "\n";
	while (q --)
	{
		int x = 0, y = 0, l, r, res = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < s1.size (); j ++)
		{
			if (s1[j] == 'b') l = x = j, r = y = s1.size () - j - 1;
		}
		for (int j = 0; j < s2.size (); j ++)
		{
			if (s2[j] == 'b') x -= j, y -= s2.size () - j - 1;
		}
		for (int i = 1; i <= n; i ++)
		{
			if (x == a[i].x && y == a[i].y && l >= a[i].l && r >= a[i].r) res ++;
		}
		cout << res << "\n";
	}
}
