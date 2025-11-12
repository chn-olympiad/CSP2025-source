#include <bits/stdc++.h>
using namespace std;
int a[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * (max(a[1], max(a[2], a[3])))) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	if (n == 4) {
		if ((a[1] + a[2] + a[3] > 2 * (max(a[1], max(a[2], a[3]))))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] > 2 * max(max(a[1], a[2]), a[4])) {
			sum++;
		}
		if (a[1] + a[3] + a[4] > max(max(a[1], a[3]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] > 2 * (max(max(a[1], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[3] + a[2] + a[4] > 2 * max(max(a[3], a[2]), a[4])) {
			sum++;
		}
		cout << sum - 1;
		return 0;
	}
	if (n == 5) {
		if ((a[1] + a[2] + a[3] > 2 * (max(a[1], max(a[2], a[3]))))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] > 2 * max(max(a[1], a[2]), a[4])) {
			sum++;
		}
		if (a[1] + a[3] + a[4] > max(max(a[1], a[3]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] > 2 * (max(max(a[1], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[5] > 2 * max(max(a[1], a[2]), a[5])) {
			sum++;
		}
		if (a[1] + a[3] + a[5] > 2 * max(max(a[1], a[3]), a[5])) {
			sum++;
		}
		if (a[1] + a[4] + a[5] > 2 * max(max(a[1], a[5]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[4] > 2 * max(max(a[3], a[2]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[5] > 2 * max(max(a[3], a[2]), a[5])) {
			sum++;
		}
		if (a[5] + a[2] + a[4] > 2 * max(max(a[5], a[2]), a[4])) {
			sum++;
		}
		if (a[3] + a[4] + a[5] > 2 * max(max(a[3], a[5]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[5] > 2 * (max(max(a[1], a[2]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[5] > 2 * (max(max(a[1], a[2]), max(a[5], a[4])))) {
			sum++;
		}
		if (a[1] + a[3] + a[4] + a[5] > 2 * (max(max(a[1], a[5]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[5] + a[2] + a[3] + a[4] > 2 * (max(max(a[5], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		cout << sum - 1;
		return 0;
	}
	if (n == 6) {
		if ((a[1] + a[2] + a[3] > 2 * (max(a[1], max(a[2], a[3]))))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] > 2 * max(max(a[1], a[2]), a[4])) {
			sum++;
		}
		if (a[1] + a[3] + a[4] > max(max(a[1], a[3]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] > 2 * (max(max(a[1], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[5] > 2 * max(max(a[1], a[2]), a[5])) {
			sum++;
		}
		if (a[1] + a[3] + a[5] > 2 * max(max(a[1], a[3]), a[5])) {
			sum++;
		}
		if (a[1] + a[4] + a[5] > 2 * max(max(a[1], a[5]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[4] > 2 * max(max(a[3], a[2]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[5] > 2 * max(max(a[3], a[2]), a[5])) {
			sum++;
		}
		if (a[5] + a[2] + a[4] > 2 * max(max(a[5], a[2]), a[4])) {
			sum++;
		}
		if (a[3] + a[4] + a[5] > 2 * max(max(a[3], a[5]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[5] > 2 * (max(max(a[1], a[2]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[5] > 2 * (max(max(a[1], a[2]), max(a[5], a[4])))) {
			sum++;
		}
		if (a[1] + a[3] + a[4] + a[5] > 2 * (max(max(a[1], a[5]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[5] + a[2] + a[3] + a[4] > 2 * (max(max(a[5], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[6] > 2 * max(max(a[1], a[2]), a[6])) {
			sum++;
		}
		if (a[1] + a[3] + a[6] > 2 * max(max(a[1], a[3]), a[6])) {
			sum++;
		}
		if (a[1] + a[6] + a[4] > 2 * max(max(a[1], a[6]), a[4])) {
			sum++;
		}
		if (a[1] + a[5] + a[6] > 2 * max(max(a[5], a[6]), a[1])) {
			sum++;
		}
		if (a[3] + a[2] + a[6] > 2 * max(max(a[3], a[2]), a[6])) {
			sum++;
		}
		if (a[6] + a[2] + a[4] > 2 * max(max(a[6], a[2]), a[4])) {
			sum++;
		}
		if (a[6] + a[2] + a[5] > 2 * max(max(a[5], a[2]), a[6])) {
			sum++;
		}
		if (a[3] + a[6] + a[4] > 2 * max(max(a[3], a[6]), a[4])) {
			sum++;
		}
		if (a[3] + a[5] + a[6] > 2 * max(max(a[3], a[5]), a[6])) {
			sum++;
		}
		if (a[5] + a[6] + a[4] > 2 * max(max(a[6], a[5]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[6] > 2 * (max(max(a[1], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[6] > 2 * (max(max(a[1], a[2]), max(a[4], a[6])))) {
			sum++;
		}
		if (a[1] + a[2] + a[6] + a[5] > 2 * (max(max(a[1], a[2]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[1] + a[4] + a[3] + a[6] > 2 * (max(max(a[1], a[4]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[6] + a[3] + a[5] > 2 * (max(max(a[1], a[2]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[1] + a[4] + a[6] + a[5] > 2 * (max(max(a[1], a[4]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[3] + a[2] + a[4] + a[6] > 2 * (max(max(a[4], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[3] + a[2] + a[6] + a[5] > 2 * (max(max(a[6], a[2]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[3] + a[4] + a[6] + a[5] > 2 * (max(max(a[6], a[4]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[6] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[6] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[6])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[6] + a[4] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[6], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[6] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[6] + a[2] + a[3] + a[4] + a[5] > 2 * max(max(max(a[6], a[2]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] > 2 * max(max(max(max(a[1], a[2]), max(a[3], a[4])), a[5]), a[6])) {
			sum++;
		}
		cout << sum - 1;
		return 0;
	}
	if (n == 7) {
		if ((a[1] + a[2] + a[3] > 2 * (max(a[1], max(a[2], a[3]))))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] > 2 * max(max(a[1], a[2]), a[4])) {
			sum++;
		}
		if (a[1] + a[3] + a[4] > max(max(a[1], a[3]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] > 2 * (max(max(a[1], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[5] > 2 * max(max(a[1], a[2]), a[5])) {
			sum++;
		}
		if (a[1] + a[3] + a[5] > 2 * max(max(a[1], a[3]), a[5])) {
			sum++;
		}
		if (a[1] + a[4] + a[5] > 2 * max(max(a[1], a[5]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[4] > 2 * max(max(a[3], a[2]), a[4])) {
			sum++;
		}
		if (a[2] + a[3] + a[5] > 2 * max(max(a[3], a[2]), a[5])) {
			sum++;
		}
		if (a[5] + a[2] + a[4] > 2 * max(max(a[5], a[2]), a[4])) {
			sum++;
		}
		if (a[3] + a[4] + a[5] > 2 * max(max(a[3], a[5]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[5] > 2 * (max(max(a[1], a[2]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[5] > 2 * (max(max(a[1], a[2]), max(a[5], a[4])))) {
			sum++;
		}
		if (a[1] + a[3] + a[4] + a[5] > 2 * (max(max(a[1], a[5]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[5] + a[2] + a[3] + a[4] > 2 * (max(max(a[5], a[2]), max(a[3], a[4])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[6] > 2 * max(max(a[1], a[2]), a[6])) {
			sum++;
		}
		if (a[1] + a[3] + a[6] > 2 * max(max(a[1], a[3]), a[6])) {
			sum++;
		}
		if (a[1] + a[6] + a[4] > 2 * max(max(a[1], a[6]), a[4])) {
			sum++;
		}
		if (a[1] + a[5] + a[6] > 2 * max(max(a[5], a[6]), a[1])) {
			sum++;
		}
		if (a[3] + a[2] + a[6] > 2 * max(max(a[3], a[2]), a[6])) {
			sum++;
		}
		if (a[6] + a[2] + a[4] > 2 * max(max(a[6], a[2]), a[4])) {
			sum++;
		}
		if (a[6] + a[2] + a[5] > 2 * max(max(a[5], a[2]), a[6])) {
			sum++;
		}
		if (a[3] + a[6] + a[4] > 2 * max(max(a[3], a[6]), a[4])) {
			sum++;
		}
		if (a[3] + a[5] + a[6] > 2 * max(max(a[3], a[5]), a[6])) {
			sum++;
		}
		if (a[5] + a[6] + a[4] > 2 * max(max(a[6], a[5]), a[4])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[6] > 2 * (max(max(a[1], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[6] > 2 * (max(max(a[1], a[2]), max(a[4], a[6])))) {
			sum++;
		}
		if (a[1] + a[2] + a[6] + a[5] > 2 * (max(max(a[1], a[2]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[1] + a[4] + a[3] + a[6] > 2 * (max(max(a[1], a[4]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[6] + a[3] + a[5] > 2 * (max(max(a[1], a[2]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[1] + a[4] + a[6] + a[5] > 2 * (max(max(a[1], a[4]), max(a[6], a[5])))) {
			sum++;
		}
		if (a[3] + a[2] + a[4] + a[6] > 2 * (max(max(a[4], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[3] + a[2] + a[6] + a[5] > 2 * (max(max(a[6], a[2]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[3] + a[4] + a[6] + a[5] > 2 * (max(max(a[6], a[4]), max(a[3], a[5])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[6] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[6] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[6])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[6] + a[4] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[6], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[6] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[6] + a[2] + a[3] + a[4] + a[5] > 2 * max(max(max(a[6], a[2]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] > 2 * max(max(max(max(a[1], a[2]), max(a[3], a[4])), a[5]), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[7] > 2 * max(max(a[1], a[2]), a[7])) {
			sum++;
		}
		if (a[1] + a[3] + a[7] > 2 * max(max(a[1], a[3]), a[7])) {
			sum++;
		}
		if (a[1] + a[7] + a[4] > 2 * max(max(a[1], a[7]), a[4])) {
			sum++;
		}
		if (a[1] + a[5] + a[7] > 2 * max(max(a[1], a[5]), a[7])) {
			sum++;
		}
		if (a[1] + a[6] + a[7] > 2 * max(max(a[1], a[6]), a[7])) {
			sum++;
		}
		if (a[3] + a[2] + a[7] > 2 * max(max(a[3], a[2]), a[7])) {
			sum++;
		}
		if (a[7] + a[2] + a[4] > 2 * max(max(a[7], a[2]), a[4])) {
			sum++;
		}
		if (a[7] + a[2] + a[5] > 2 * max(max(a[7], a[2]), a[5])) {
			sum++;
		}
		if (a[7] + a[2] + a[6] > 2 * max(max(a[6], a[2]), a[7])) {
			sum++;
		}
		if (a[3] + a[7] + a[4] > 2 * max(max(a[3], a[7]), a[4])) {
			sum++;
		}
		if (a[3] + a[5] + a[7] > 2 * max(max(a[3], a[5]), a[7])) {
			sum++;
		}
		if (a[3] + a[6] + a[7] > 2 * max(max(a[3], a[6]), a[7])) {
			sum++;
		}
		if (a[5] + a[7] + a[4] > 2 * max(max(a[5], a[7]), a[4])) {
			sum++;
		}
		if (a[6] + a[7] + a[4] > 2 * max(max(a[6], a[7]), a[4])) {
			sum++;
		}
		if (a[5] + a[6] + a[7] > 2 * max(max(a[5], a[6]), a[7])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[7] > 2 * (max(max(a[1], a[2]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[1] + a[2] + a[4] + a[7] > 2 * (max(max(a[4], a[7]), max(a[4], a[7])))) {
			sum++;
		}
		if (a[1] + a[2] + a[5] + a[7] > 2 * (max(max(a[1], a[2]), max(a[5], a[7])))) {
			sum++;
		}
		if (a[1] + a[2] + a[7] + a[6] > 2 * (max(max(a[1], a[2]), max(a[7], a[6])))) {
			sum++;
		}
		if (a[1] + a[4] + a[3] + a[7] > 2 * (max(max(a[1], a[4]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[1] + a[5] + a[3] + a[7] > 2 * (max(max(a[1], a[5]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[1] + a[7] + a[3] + a[6] > 2 * (max(max(a[1], a[7]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[4] + a[5] + a[7] > 2 * (max(max(a[1], a[4]), max(a[5], a[7])))) {
			sum++;
		}
		if (a[1] + a[4] + a[7] + a[6] > 2 * (max(max(a[1], a[4]), max(a[7], a[6])))) {
			sum++;
		}
		if (a[1] + a[5] + a[7] + a[6] > 2 * (max(max(a[1], a[5]), max(a[7], a[6])))) {
			sum++;
		}
		if (a[4] + a[2] + a[3] + a[7] > 2 * (max(max(a[4], a[2]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[5] + a[2] + a[3] + a[7] > 2 * (max(max(a[5], a[2]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[7] + a[2] + a[3] + a[6] > 2 * (max(max(a[7], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[5] + a[2] + a[4] + a[7] > 2 * (max(max(a[5], a[2]), max(a[4], a[7])))) {
			sum++;
		}
		if (a[6] + a[2] + a[4] + a[7] > 2 * (max(max(a[4], a[2]), max(a[6], a[7])))) {
			sum++;
		}
		if (a[7] + a[2] + a[5] + a[6] > 2 * (max(max(a[5], a[2]), max(a[7], a[6])))) {
			sum++;
		}
		if (a[5] + a[4] + a[3] + a[7] > 2 * (max(max(a[4], a[5]), max(a[3], a[7])))) {
			sum++;
		}
		if (a[7] + a[4] + a[3] + a[6] > 2 * (max(max(a[7], a[4]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[7] + a[5] + a[3] + a[6] > 2 * (max(max(a[1], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[7] + a[4] + a[5] + a[6] > 2 * (max(max(a[1], a[2]), max(a[3], a[6])))) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[7] > 2 * max(max(max(a[1], a[2]), max(a[3], a[4])), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[7] + a[5] > 2 * max(max(max(a[1], a[2]), max(a[3], a[6])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[6] + a[3] + a[7] > 2 * max(max(max(a[1], a[2]), max(a[6], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[2] + a[4] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[2] + a[4] + a[6] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[2] + a[6] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[3] + a[4] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[3] + a[4] + a[6] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[7] + a[6] + a[4] + a[5] > 2 * max(max(max(a[1], a[6]), max(a[3], a[4])), a[5])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[7] > 2 * max(max(max(max(a[1], a[2]), max(a[3], a[4])), a[5]), a[7])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[7] + a[6] > 2 * max(max(max(max(a[1], a[2]), max(a[3], a[4])), a[7]), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[7] + a[5] + a[6] > 2 * max(max(max(max(a[1], a[2]), max(a[3], a[7])), a[5]), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[7] + a[4] + a[5] + a[6] > 2 * max(max(max(max(a[1], a[2]), max(a[7], a[4])), a[5]), a[6])) {
			sum++;
		}
		if (a[7] + a[2] + a[3] + a[4] + a[5] + a[6] > 2 * max(max(max(max(a[7], a[2]), max(a[3], a[4])), a[5]), a[6])) {
			sum++;
		}
		if (a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] > 2 * max(max(max(max(max(a[1], a[2]), max(a[3], a[4])),
		        a[5]), a[6]), a[7])) {
			sum++;
		}
		cout << sum - 1;
		return 0;
	}
	cout << n * 2 - 1;
	return 0;
}