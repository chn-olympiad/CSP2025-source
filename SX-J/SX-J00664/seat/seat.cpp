#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
int x, y;
int a[N];

bool cmp(int ac, int win) {
	return ac > win;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
//	ios::sync_with_stdin(false);
//	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int f = 0, f1 = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == f1 && f == 0) {
			f = i;
		}
	}
	//cout << f << endl;
	// f ÐòºÅ
	if (f % n != 0) {
		x = f / n + 1;
	} else if (f % n == 0) {
		x = f / n;
	}
	//cout << x;
	if ((f + n - 1) / n % 2 == 1) {
		if (f % n == 0) {
			y = n;
		} else {
			y = f - (f / n) * n;
		}
	} else if ((f + n - 1) / n % 2 == 0) {
		if (f % n == 0) {
			y = 1;
		} else {
			y = n - (f - (f / n) * n) + 1;
		}
	}
	//cout << y;
	cout << x << " " << y;
	return 0;
}