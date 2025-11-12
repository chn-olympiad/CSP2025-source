#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[230];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	feropen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int s = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == s) {
			if (i <= n)
				cout << 1 << " " << i << endl;
			if (i > n)
				cout << i / n + 1 << " " << (n + 1) - (i - n) << endl;
		}
	}
}
