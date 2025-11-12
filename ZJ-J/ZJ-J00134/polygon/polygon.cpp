#include <bits/stdc++.h>
using namespace std;
int n, a[5005], sum[5005], q, num;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	if(n == 3) {
		if(sum[3] > 2 * max(a[1], max(a[2], a[3]))) {
			cout << 1;
		} else {
			cout << 0;
		}
		return 0;
	}
	if(n == 4) {
		if(sum[3] > 2 * max(a[1], max(a[2], a[3]))) {
			num++;
		}
		if(sum[2] + a[4] > 2 * max(a[1], max(a[2], a[4]))) {
			num++;
		}
		if(sum[4] - sum[1] > 2 * max(a[4], max(a[2], a[3]))) {
			num++;
		}
		if(sum[4] > 2 * max(a[4], max(a[1], max(a[2], a[3])))) {
			num++;
		}
		cout << num;
		return 0;
	}
	if(n == 5) {
		if(sum[3] > 2 * max(a[1], max(a[2], a[3]))) {
			num++;
		}
		if(sum[2] + a[4] > 2 * max(a[1], max(a[2], a[4]))) {
			num++;
		}
		if(sum[2] + a[5] > 2 * max(a[5], max(a[2], a[1]))) {
			num++;
		}
		if(sum[4] - a[2] > 2 * max(a[4], max(a[1], a[3]))) {
			num++;
		}
		if(sum[5] - a[2] - a[4] > 2 * max(a[1], max(a[5], a[3]))) {
			num++;
		}
		if(sum[5] - a[2] - a[3] > 2 * max(a[1], max(a[5], a[4]))) {
			num++;
		}
		if(sum[4] - a[1] > 2 * max(a[4], max(a[2], a[3]))) {
			num++;
		}
		if(sum[5] - a[1] - a[4] > 2 * max(a[5], max(a[2], a[3]))) {
			num++;
		}
		if(sum[5] - a[1] - a[3] > 2 * max(a[4], max(a[2], a[5]))) {
			num++;
		}
		if(sum[5] - sum[2] > 2 * max(a[5], max(a[3], a[4]))) {
			num++;
		}
		if(sum[5] - a[4] > 2 * max(a[1], max(a[5], max(a[2], a[3])))) {
			num++;
		}
		if(sum[4] > 2 * max(a[4], max(a[1], max(a[2], a[3])))) {
			num++;
		}
		if(sum[5] - a[1] > 2 * max(a[4], max(a[5], max(a[2], a[3])))) {
			num++;
		}
		if(sum[5] - a[2] > 2 * max(a[4], max(a[1], max(a[5], a[3])))) {
			num++;
		}
		if(sum[5] - a[3] > 2 * max(a[4], max(a[1], max(a[2], a[5])))) {
			num++;
		}
		if(sum[5] > 2 * max(a[5], max(a[4], max(a[1], max(a[2], a[3]))))) {
			num++;
		}
		cout << num;
		return 0;
	}
	return 0;
}