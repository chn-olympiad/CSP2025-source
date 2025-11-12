#include <bits/stdc++.h>
using namespace std;
int n, sum, mmax = -1;
int a[5005];

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		reutnr 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mmax = max(mmax, a[i]);
	}
	if (mmax * 2 < sum)
		cout << 1;

	return 0;
}