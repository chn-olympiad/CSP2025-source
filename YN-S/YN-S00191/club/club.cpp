#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int t, n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	for (int i = 1; i <= t; i++) {

		cin >> n;
		int a, b, c, sum = 0;

		for (int j = 1; j <= n; j++) {

			cin >> a >> b >> c;
			sum += max(a, max(b, c));

		}

		cout << sum << endl;
	}

	return 0;
}
