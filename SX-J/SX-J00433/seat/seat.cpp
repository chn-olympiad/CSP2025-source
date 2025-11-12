#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

int a[120];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	int x;
	cin >> x;
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];
	}

	sort(a + 1, a + n *m);
	reverse(a + 1, a + n *m );
	for (int i = 1; i < n * m; i++) {
		if (a[i] < x) {
			cout << (i - 1) / n + 1 << " ";
			if (((i - 1) / n + 1) % 2 == 0) {//Å¼Êý
				if (i % n == 0) {
					cout << 1;
				} else
					cout << n - i % n + 1;
			} else { //ÆæÊý
				if (i % n == 0)
					cout << n;
				else
					cout << i % n;
			}
			return 0;
		}
	}
	cout << m << " ";
	if (m % 2 == 0)
		cout << 1;
	else
		cout << n;

	return 0;
}
