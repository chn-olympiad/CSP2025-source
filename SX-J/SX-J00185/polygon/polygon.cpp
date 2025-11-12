#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0;
int x = 1, y = 1;
int a[1005];

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int l = a[1];
	for (int i = 1; i <= n * m; i++) {
		if (a[i] > l) {
			sum++;
		}
	}
	if (sum == 0) {
		cout << "1" << " " << "1";
		return 0;
	}
	if (sum == n) {
		cout << "2" << " " << n;
		return 0;
	}
	if (sum < n) {
		y += sum;
		cout << "1" << " " << y;
		return 0;
	} else if (sum > n) {
		int d = sum / n;
		int c = sum % n;
		x += d;
		if (d % 2 != 0) {
			y = n - c;
		} else {
			y = c;
		}
	}
	cout << x << " " << y;
	return 0;
}
