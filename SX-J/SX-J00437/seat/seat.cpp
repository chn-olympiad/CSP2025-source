#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define debug(x) cerr << #x << " = " << x << endl
using namespace std;

const int N = 110;
int n, m, R, arr[N];
int tot, c, r;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m;
	tot = n * m;
	for (int i = 1; i <= tot; ++i) {
		cin >> arr[i];
	}
	R = arr[1];
	sort(arr + 1, arr + 1 + tot, greater<>());

	c = r = 0;
	for (int i = 1; i <= tot; ++i) {
		if (i % n == 1) {
			c++;
			if (c % 2 == 0)
				r = n;
			else
				r = 1;
		}

		if (arr[i] == R) {
			break;
		}

		if (c % 2 == 0)
			r--;
		else
			r++;
	}
	cout << c << " " << r << endl;

	return 0;
}