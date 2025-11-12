#include<bits/stdc++.h>
using namespace std;
const int M = 200;
int n, m;
int a[M];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cin.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i];
	int sum = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	int l = 1, r = n * m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (a[mid] == sum) {
			l = mid;
			break;
		}
		else if (a[mid] > sum) l = mid + 1;
		else r = mid - 1;
	}
	if ((l / n) % 2 == 0 || l % n == 0) {
		cout << ((l % n == 0) ? (l / n) : (l / n) + 1) << ' ' << ((l % n == 0) ? n : (l % n));
	}
	else {
		cout << ((l % n == 0) ? (l / n) : (l / n) + 1) << ' ' << ((l % n == 0) ? 1 : (n - (l % n) + 1));
	}
	return 0;
}
