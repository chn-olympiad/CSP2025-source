//Luogu 743373-Vitamin_B:)
//ZJ-S01668
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int t, n, a[100005][5], s1, s2, s3, id, sum, k;

priority_queue <int> q;

int main () {
//	freopen ("club5.in", "r", stdin);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> t;

	while (t --) {

		cin >> n;

		s1 = s2 = s3 = 0, sum = 0;

		for (int i = 1; i <= n; ++ i) {

			cin >> a[i][1] >> a[i][2] >> a[i][3];

			if (a[i][1] > a[i][2])
				if (a[i][1] > a[i][3])
					++ s1, sum += a[i][1];
				else
					++ s3, sum += a[i][3];
			else if (a[i][2] > a[i][3])
				++ s2, sum += a[i][2];
			else
				++ s3, sum += a[i][3];

		}
//		cerr << s1 << ' ' << s2 << ' ' << s3 << ':' << sum << '\n';
		if (s1 > n / 2)
			id = 1, k = s1 - n / 2;
		else if (s2 > n / 2)
			id = 2, k = s2 - n / 2;
		else if (s3 > n / 2)
			id = 3, k = s3 - n / 2;
		else
			id = 0;

		if (id) {

			for (int i = 1; i <= n; ++ i) 
				if (a[i][id] == max ({a[i][1], a[i][2], a[i][3]})){

				const int x = a[i][id] - a[i][1], y = a[i][id] - a[i][2], z = a[i][id] - a[i][3];

				q.push (x + y + z - max ({x, y, z}) - min ({x, y, z}));

				if (q.size () > k)
					q.pop ();

			}

			while (! q.empty ())
				sum -= q.top (), q.pop ();

		}

		cout << sum << '\n';

	}

	return 0;
}
