#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int a[100005][10];
int t;
int n;
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		int zmyd;
		for (int i = 1; i <= n; i++)
		{
			int maxn = 0;
			for (int j = 1; j <= 3; j++)
			{
				cin >> a[i][j];
				maxn = max(maxn, a[i][j]);
			}
			if (maxn == a[i][1] && !(a[i][4] > n / 2))
			{
				a[i][4]++;
				zmyd += maxn;
			}
			if (maxn == a[i][2] && !(a[i][5] > n / 2))
			{
				a[i][5]++;
				zmyd += maxn;
			}
			if (maxn == a[i][3] && !(a[i][6] > n / 2))
			{
				a[i][4]++;
				zmyd += maxn;
			}
		}
		cout << zmyd << "\n";
	}
	return 0;
}
