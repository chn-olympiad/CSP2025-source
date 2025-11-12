#include <bits/stdc++.h>
using namespace std;

long long t, n, k, x, y, z, ans, a[100005][5];
vector <long long> p[5];

int main () {
	
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		x = y = z = ans = 0;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			k = max ({a[i][1], a[i][2], a[i][3]});
			ans += k;
			if (a[i][1] == k) {
				x++, p[1].push_back (min (k - a[i][2], k - a[i][3]));
			} else if (a[i][2] == k) {
				y++, p[2].push_back (min (k - a[i][1], k - a[i][3]));
			} else {
				z++, p[3].push_back (min (k - a[i][1], k - a[i][2]));
			}
		}
		if (x > (n / 2)) {
			sort (p[1].begin (), p[1].end ());
			for (long long i = 0; i < x - (n / 2); i++)
				ans -= p[1][i];
		} else if (y > (n / 2)) {
			sort (p[2].begin (), p[2].end ());
			for (long long i = 0; i < y - (n / 2); i++)
				ans -= p[2][i];
		} else if (z > (n / 2)) {
			sort (p[3].begin (), p[3].end ());
			for (long long i = 0; i < z - (n / 2); i++)
				ans -= p[3][i];
		}
		cout << ans << "\n";
		p[1].clear (); p[2].clear (); p[3].clear ();
//		cout << "ts : " << p[1].size () << " " << p[2].size () << " " << p[3].size () << "\n";
	}
	
	return 0;
}

/*
统计每人最满意哪个部门，
若有一部门 > (n / 2) 人， 
则统计此部门内转业代价最小的人，挨个转走，
直到此部门 = (n / 2)。 
*/
