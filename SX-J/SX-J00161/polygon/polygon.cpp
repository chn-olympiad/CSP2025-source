#include <bits/stdc++.h>
using namespace std;
int a[100005], n, maxx = INT_MIN, cnt, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n < 3) {
		cout << 0;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		cnt += a[i];
	}
	if (n == 3 && cnt == 2 * maxx) {
		cout << 1;
		return 0;
	}
	return 0;
}