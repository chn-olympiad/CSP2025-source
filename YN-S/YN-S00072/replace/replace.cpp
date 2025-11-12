#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, ans = 1;
	cin >> n;
	long long k = 1, day = 0;
	for (int l = 1; l <= 114514; l++) {
		for (int i = 1; i <= n * n; i++) {
			ans += k + l;
			day++;
			if (day == k) {
				k++;
				day = 0;
			}
		}
	}
	for (int l = 1; l <= 114514; l++) {
		for (int i = 1; i <= n * n; i++) {
			ans += k + l;
			day++;
			if (day == k) {
				k++;
				day = 0;
			}
		}
	}
	cout << ans;
	return 0;
}