#include <bits/stdc++.h>
using namespace std;

struct node {
	int cnt, l;
} num[100005];

bool cmp(node x, node y) {
	return x.cnt > y.cnt;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> num[i].cnt;
		num[i].l = i;
	}
	sort(num + 1, num + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (num[i].l == 1) {
			if ((int)ceil(i * 1.0 / n) % 2 == 1) {
				cout << ceil(i * 1.0 / n) << " ";
				if (i % n == 0)
					cout << n;
				else
					cout << i % n;
			} else {
				cout << ceil(i * 1.0 / n) << " ";
				if (i % n == 0)
					cout << 1;
				else
					cout << n - (i % n) + 1;
			}
			return 0;
		}
	}
	return 0;
}
