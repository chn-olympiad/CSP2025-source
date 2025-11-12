#include <bits/stdc++.h>
using namespace std;
int a[5050];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, hez = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		hez = a[i];
	}
	hez *= 2;
	for (int i = 1; i <= 5000; i++) {
		int temp = a[i];
		int len = 1;
		for (int j = 1; j <= n; j++) {
			if (len < 3) {
				temp += a[j];
			} else if (temp >= hez) {
				ans++;
			}
		}
	}
	cout << ans % n;
	return 0;
}