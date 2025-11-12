#include <bits/stdc++.h>
using namespace std;
long long n, k, a[10000005], k1, qwe, A1, A2, cnt;
bool q, z;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			q = 1;
		}
	}
	if (q == 0) {
		cout << n - 1;
	} else {
		if (k == 0) {
			for (long long i = 1; i <= n; i++) {

				if (a[i] == 1 && z == 0) {
					cnt++;
					z = 1;
				} else if (a[i] == 1 && z == 1) {
					cnt++;
				} else if (a[i] == 0 && z == 1) {
					z = 0;

					A1 += cnt / 2;
				}

				if (a[i] == 0) {
					A2++;
				}
			}
			cout << max(A1, A2);
		} else {
			for (long long i = 1; i <= n; i++) {
				if (a[i] == 1) {
					A1++;
				}
			}
			cout << A1;
		}
	}

	return 0;
}