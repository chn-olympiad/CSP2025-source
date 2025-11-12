#include <bits/stdc++.h>
using namespace std;
int a[1000 + 5];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int max = INT_MIN;
	int n, s = 0, num = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (max  <= a[i] )
			max = a[i];
		int num = num + a[i];

		if (num > 2 * max) {
			s++;
		}
		if (i <= n - 1 && n - 1 >= 3) {
			if (max < a[i])
				max = a[i];
			int num = num + a[i];
			if (num > 2 * max) {
				s++;
			}
		}
	}
	cout << s;
	return 0;
}
