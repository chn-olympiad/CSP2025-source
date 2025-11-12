#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define V vector
#define x first
#define y second
using namespace std;

int solve()
{
	int n;
	cin >> n;
	V<V<int>> a(n, V<int>(3));
	int ans = 0;
	V<int> cnt(3, 0);
	for(int i = 0; i < n; ++i)
	{
		int mx = -1, id, t = 0;
		for(int j = 0; j < 3; ++j)
		{
			cin >> a[i][j];
			if(a[i][j] > mx)
				mx = a[i][j], id = j, t = 0;
			else if(a[i][j] == mx) t = 1;
		}
		ans += mx;
//		cout << ' ' << id << '\n';
		if(!t)
			++cnt[id];
	}
//	cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << '\n';
	if(cnt[0] > n / 2)
	{
//		puts("AAA");
		sort(a.begin(), a.end(), [](V<int> a, V<int> b){return a[0]-max(a[1], a[2]) < b[0]-max(b[1], b[2]);});
		for(int i = 0; cnt[0] > n/2; ++i)
		{
//			cout << ' ' << a[i][0] << ' ' << a[i][1] << ' ' << a[i][0] - a[i][1] << '\n';
			if(a[i][0] > max(a[i][1], a[i][2]))
				ans -= a[i][0],
				ans += max(a[i][1], a[i][2]),
				--cnt[0];
		}
	}
	if(cnt[1] > n / 2)
	{
//		puts("BBB");
		sort(a.begin(), a.end(), [](V<int> a, V<int> b){return a[1]-max(a[0], a[2]) < b[1]-max(b[0], b[2]);});
		for(int i = 0; cnt[1] > n/2; ++i)
			if(a[i][1] > max(a[i][2], a[i][0]))
				ans -= a[i][1],
				ans += max(a[i][0], a[i][2]),
				--cnt[1];
	}
	if(cnt[2] > n / 2)
	{
//		puts("CCC");
//		cout << ' ' << cnt[2] << ' ' << n/2 << '\n';
		sort(a.begin(), a.end(), [](V<int> a, V<int> b){return a[2]-max(a[0], a[1]) < b[2]-max(b[1], b[0]);});
		for(int i = 0; cnt[2] > n/2; ++i)
			if(a[i][2] > max(a[i][1], a[i][0]))
				ans -= a[i][2],
				ans += max(a[i][1], a[i][0]),
				--cnt[2];
	}
	cout << ans << '\n';
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
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while(~--T)
		solve();

	return 0;
}
//14:57