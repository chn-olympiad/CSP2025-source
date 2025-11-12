#include <bits/stdc++.h>
using namespace std;

struct node
{
	int x, y, z;
};

bool cmp1 (node o, node p)
{
	return min (o.x - o.y, o.x - o.z) > min (p.x - p.y, p.x - p.z);
}

bool cmp2 (node o, node p)
{
	return min (o.y - o.x, o.y - o.z) > min (p.y - p.x, p.y - p.z);
}

bool cmp3 (node o, node p)
{
	return min (o.z - o.x, o.z - o.y) > min (p.z - p.x, p.z - p.y);
}

int t, n;
int main(){
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t --)
	{
		vector <node> a[3];
		long long ans = 0;
		cin >> n;
		for (int i = 1; i <= n;i ++)
		{
			node tmp;
			cin >> tmp.x >> tmp.y >> tmp.z;
			if (max (tmp.x, max (tmp.y, tmp.z)) == tmp.x)
				a[0].push_back (tmp);
			else if (max (tmp.x, max (tmp.y, tmp.z)) == tmp.y)
				a[1].push_back (tmp);
			else if (max (tmp.x, max (tmp.y, tmp.z)) == tmp.z)
				a[2].push_back (tmp);
		}
		int l0 = a[0].size(), l1 = a[1].size(), l2 = a[2].size();
		if (l0 > n / 2 && l0 >= l1 && l0 >= l2)
		{
			sort (a[0].begin(), a[0].end(), cmp1);
			for (int i = 0; i < n / 2; i ++)
				ans += a[0][i].x;
			for (int i = n / 2; i < a[0].size(); i ++)
			{
				node tmp = a[0][i];
				if (tmp.x - tmp.y < tmp.x - tmp.z)
					a[1].push_back (tmp);
				else
					a[2].push_back (tmp);
			}
			for (int i = 0; i < a[1].size(); i ++)
				ans += a[1][i].y;
			for (int i = 0; i < a[2].size(); i ++)
				ans += a[2][i].z;
		}
		else if (l1 > n / 2 && l1 >= l0 && l1 >= l2)
		{
			sort (a[1].begin(), a[1].end(), cmp2);
			for (int i = 0; i < n / 2; i ++)
				ans += a[1][i].y;
			for (int i = n / 2; i < a[1].size(); i ++)
			{
				node tmp = a[1][i];
				if (tmp.y - tmp.x < tmp.y - tmp.z)
					a[0].push_back (tmp);
				else
					a[2].push_back (tmp);
			}
			for (int i = 0; i < a[0].size(); i ++)
				ans += a[0][i].x;
			for (int i = 0; i < a[2].size(); i ++)
				ans += a[2][i].z;
		}
		else if (l2 > n / 2 && l2 >= l0 && l2 >= l1)
		{
			sort (a[2].begin(), a[2].end(), cmp3);
			for (int i = 0; i < n / 2; i ++)
				ans += a[2][i].z;
			for (int i = n / 2; i < a[2].size(); i ++)
			{
				node tmp = a[2][i];
				if (tmp.z - tmp.x < tmp.z - tmp.y)
					a[0].push_back (tmp);
				else
					a[1].push_back (tmp);
			}
			for (int i = 0; i < a[0].size(); i ++)
				ans += a[0][i].x;
			for (int i = 0; i < a[1].size(); i ++)
				ans += a[1][i].y;
		}
		else
		{
			for (int i = 0 ; i < a[0].size(); i ++)
				ans += a[0][i].x;
			for (int i = 0 ; i < a[1].size(); i ++)
				ans += a[1][i].y;
			for (int i = 0 ; i < a[2].size(); i ++)
				ans += a[2][i].z;
		}
		cout << ans << '\n';
	}
	return 0;
}

/*18961 15344 16178 19722 10557 17976 13424 8769 9953 16441
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/
