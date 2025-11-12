#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], id;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int num = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == num) {
			id = i;
		}
	}
	if (id % n == 0) { //id在第一个或最后一个
		if ((id / n) % 2 == 0) { //id在偶数列
			cout << id / n << " " << 1;
		} else if ((id / n) % 2 != 0) {
			cout << id / n << " " << n;
		}
	} else { //3/4=0 0+1 3
		if ((id / n) % 2 == 0) {
			cout << id / n + 1 << " " << id % n;
		} else if ((id / n) % 2 != 0) {
			cout << id / n + 1 << " " << n + 1 - (id % n);
		}
	}

	return 0;
}
