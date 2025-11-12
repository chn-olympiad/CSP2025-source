#include <bits/stdc++.h>
using namespace std;
int n, m, cnt = 1;
int num[105];
int hang, lie;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> num[i];
	}
	for (int i = 1; i <= n * m; i++) {
		if (num[i] > num[1])
			cnt++;
	}
	lie = (cnt - 1) / n + 1;
	cout << lie << " ";
	if (lie % 2 == 0) {
		if (cnt % n == 0) {
			cout << 1;
			return 0;
		}
		hang = n - cnt % n + 1;
		cout << hang;
		return 0;
	} else {
		if (cnt % n == 0) {
			cout << n;
			return 0;
		}
		cout << cnt % n;
	}

	return 0;
}
