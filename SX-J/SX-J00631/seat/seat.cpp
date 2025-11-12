#include <bits/stdc++.h>

using namespace std;
int seat[15][15];
int mark[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	long long pm = 0;

	for (int i = 1; i <= n * m; i++) {
		cin >> mark[i];
	}

	int num = mark[1];
	for (int i = 1; i <= n * m; i++) {
		for (int j = i; j <= n * m; j++) {
			if (mark[i] < mark[j]) {
				swap(mark[i], mark[j]);
			}
		}
	}

	for (int i = 1; i <= n * m; i++) {
		if (mark[i] == num) {
			pm = i;
		}
	}

	long long r = pm / n + 1;
	if (pm % n == 0) {
		r--;
	}
	if (pm <= n) {
		cout << 1 << " " << pm;
		return 0;
	}
	if (r % 2 == 1) {
		cout << r << " " << pm - n*(r - 1);
	} else {
		cout << r << " " << 1 + r*n - pm;
	}

	return 0;

}