#include <bits/stdc++.h>
using namespace std;
int n, a[5003], sum[5003], t, cnt;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = a[i];
		for (int j = i + 1; j <= n; j++) {
			sum[j] = sum[j - 1 - t] + a[j ];
			for (int j = i + 1; j <= n; j++) {
			}
		}

		for (int j = 3; j <= n; j++) {
			if (sum[j - 1] > a[j]) {
				cnt++;
				cout << sum[j - 1] << endl;
			}
		}
		t++;
		for (int j = 1; j <= n; j++) {
			sum[j] == 0;
		}

	}
	cout << cnt;
}
