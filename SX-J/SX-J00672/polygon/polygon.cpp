#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 2; j < n; j++) {
			int num = 0, sum = 0;
			for (int s = i; s <= j; s++) {
				if (a[s] > num) {
					num = a[s];
				}
				sum += a[s];
			}
			if (num * 2 < sum) {
				ans++;
			}
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}