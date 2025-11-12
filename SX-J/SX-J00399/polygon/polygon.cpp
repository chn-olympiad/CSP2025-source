#include <bits/stdc++.h>
using namespace std;
int a[10000];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	if (n == 3) {
		cin >> a[0] >> a[1] >> a[2];
		if (a[0] + a[1] > a[2])
			cnt++;
		if (a[1] + a[2] > a[0])
			cnt++;
		if (a[2] + a[0] > a[1])
			cnt++;
		cout << cnt;
	}
	if (n < 3)
		cout << 0;
	return 0;
}
