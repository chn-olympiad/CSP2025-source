# include <bits/stdc++.h>
# include <cstdio>
# define ll long long
# define ull unsigned long long
# define endl '\n'
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

const int N = 1e5 + 5;

ll t;
ll n;
ll a[N][10];
ll b[N];
ll c[N];

inline bool cmp (int x, int y) {
	return (x > y);
}

inline void solve () {
	for (int i = 1; i <= n; i ++ ) {
		for (int j = 0; j < 10; j ++ ) {
			a[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		b[i] = 0;
		c[i] = 0;
	}
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
	}
	if (n == 2) {
		ll ans = 0;
		ll p1 = (a[1][1] + a[2][2]);
		ll p2 = (a[1][1] + a[2][3]);
		ll p3 = (a[1][2] + a[2][1]);
		ll p4 = (a[1][2] + a[2][3]);
		ll p5 = (a[1][3] + a[2][1]);
		ll p6 = (a[1][3] + a[2][2]);
		ans = max (p1, max (p2, max (p3, max (p4, max (p5, p6)))));
		cout << ans << endl;
		return ;
	}
	if (n == 4) {
		ll ans = 0;
		{
			{
				ans = max (ans, (a[1][1] + a[2][1] + a[3][2] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][1] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][1] + a[2][1] + a[3][3] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][1] + a[3][3] + a[4][3]));
			}
			{
				ans = max (ans, (a[1][1] + a[2][2] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][3] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][2] + a[3][3] + a[4][3]));
			}
			{
				ans = max (ans, (a[1][1] + a[2][3] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][2] + a[4][2]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][1] + a[2][3] + a[3][3] + a[4][2]));
			}
		}
		{
			{
				ans = max (ans, (a[1][2] + a[2][1] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][3] + a[4][2]));
				ans = max (ans, (a[1][2] + a[2][1] + a[3][3] + a[4][3]));
			}
			{
				ans = max (ans, (a[1][2] + a[2][2] + a[3][1] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][2] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][2] + a[2][2] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][2] + a[3][3] + a[4][3]));
			}
			{
				ans = max (ans, (a[1][2] + a[2][3] + a[3][1] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][2] + a[2][3] + a[3][3] + a[4][2]));
			}
		}
		{
			{
				ans = max (ans, (a[1][3] + a[2][1] + a[3][1] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][2] + a[4][2]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][1] + a[3][3] + a[4][2]));
			}
			{
				ans = max (ans, (a[1][3] + a[2][2] + a[3][1] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][1] + a[4][3]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][2] + a[4][3]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][3] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][2] + a[3][3] + a[4][2]));
			}
			{
				ans = max (ans, (a[1][3] + a[2][3] + a[3][1] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][3] + a[3][1] + a[4][2]));
				ans = max (ans, (a[1][3] + a[2][3] + a[3][2] + a[4][1]));
				ans = max (ans, (a[1][3] + a[2][3] + a[3][2] + a[4][2]));
			}
		}
		cout << ans << endl;
		return ;
	}
	{
		bool f = 0;
		for (int i = 1; i <= n; i ++ ) {
			if ((a[i][2]) || (a[i][3])) {
				f = 1;
				break;
			}
		}
		if (! f) {
			ll ans = 0;
			for (int i = 1; i <= n; i ++ ) {
				b[i] = a[i][1];
			}
			sort (b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= (n / 2); i ++ ) {
				ans += b[i];
			}
			cout << ans << endl;
			return ;
		}
	}
	{
		bool f = 0;
		for (int i = 1; i <= n; i ++ ) {
			if ((a[i][1]) || (a[i][3])) {
				f = 1;
				break;
			}
		}
		if (! f) {
			ll ans = 0;
			for (int i = 1; i <= n; i ++ ) {
				b[i] = a[i][2];
			}
			sort (b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= (n / 2); i ++ ) {
				ans += b[i];
			}
			cout << ans << endl;
			return ;
		}
	}
	{
		bool f = 0;
		for (int i = 1; i <= n; i ++ ) {
			if (a[i][3]) {
				f = 1;
				break;
			}
		}
		if (! f) {
			ll ans = 0;
			for (int i = 1; i <= n; i ++ ) {
				b[i] = a[i][1];
				c[i] = a[i][2];
			}
			sort (b + 1, b + 1 + n, cmp);
			sort (c + 1, c + 1 + n, cmp);
			for (int i = 1; i <= n; i ++ ) {
				ans += max (b[i], c[i]);
			}
			cout << ans << endl;
			return ;
		}
	}
	{
		ll ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			ans += max (a[i][1], max (a[i][2], a[i][3]));
		}
		cout << ans << endl;
		return ;
	}
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	for (cin >> t; t; t -- ) {
		solve ();
	}
	return 0;
}
// Can you give me more points,CCF?
