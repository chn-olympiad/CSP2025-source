#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int,int> a[110];
bool cmp(pair<int,int> a, pair<int,int> b)
{
	return a.first > b.first;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= m*n; i++)
		cin >> a[i].first, a[i].second = i;
	sort(a+1, a+n*m+1, cmp);
	int k;
	for (int i = 1; i <= n*m; i++)
		if (a[i].second == 1)
		{
			k = i; break;
		}
	int ans1, ans2;
	int t = k % n;
	if (t == 0)
		ans1 = k/n;
	else
		ans1 = k/n + 1;
	if (t == 0)
	{
		if (ans1 & 1)
			ans2 = m;
		else
			ans2 = 1;
	}
	else if (ans1 & 1)
		ans2 = t;
	else
		ans2 = m-t+1;
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
