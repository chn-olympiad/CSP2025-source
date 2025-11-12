#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N = 1e2+10;
int a[N];

int cmp(int aa, int b) {
	return aa > b;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int q = a[1];
	int w;
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == q) {
			w = i;
		}
	}
	double mm = m, ww = w;
	double xx = ceil(ww / mm * 1.0);
	int x = xx;
	int y = w % m;
	if (x % 2 == 1) {
		if (y == 0) {
			y = m;
		}


	} else {
		if (y == 0) {
			y = 1;
		}
		if (y == 1) {
			y = m;
		}

	}
	cout << x << " " << y;
	return 0;
}
