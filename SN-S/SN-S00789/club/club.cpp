#include <bits/stdc++.h>
using namespace std;
long long t, n, num, s;
struct club
{
	long long fi, se, th, sum;
} a[100005];
bool cmp(club x, club y)
{
	return x.sum > y.sum;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	for (int q = 1; q <= t; q++)
	{
		cin >> n;
		num = n / 2;
		s = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].fi >> a[i].se >> a[i].th;
			a[i].sum = a[i].fi + a[i].se + a[i].th;
		}
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n; i++)
		{
			s += a[i].fi;
			if (i >= num) break;
//			maxx = max(max(a[i][1], a[i][2]), a[i][3]);
//			sum += maxx;
//			if (a[i][1] >= a[i][2]) && (a[i][2] >= a[i][3])
//			{
//				if (first < num) first++;
//				else if (third < num) second++;
//				else third++;
//			}
//			else if (a[i][1] >= a[i][3]) && (a[i][3] >= a[i][2])
//			{
//				if (first < num) first++;
//				else if (third < num) third++;
//				else second++;
//			}
//			else if (a[i][2] >= a[i][1]) && (a[i][1] >= a[i][3])
//			{
//				if (second < num) second++;
//				else if (third < num) first++;
//			}
//			else if (a[i][2] >= a[i][3]) && (a[i][3] >= a[i][1])
//			{
//				if (first < num) first++;
//				else if (third < num) third++;
//			}
//			else if (a[i][1] >= a[i][3]) && (a[i][3] >= a[i][2])
//			{
//				if (first < num) first++;
//				else third++;
//			}
//			else if (a[i][1] >= a[i][3]) && (a[i][3] >= a[i][2])
//			{
//				if (first < num) first++;
//				else third++;
//			}
		}
		cout << s << "\n";
	}
	return 0;
}
