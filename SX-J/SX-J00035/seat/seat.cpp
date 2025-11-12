#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int h[110];

bool cmp(int a, int b) {
	return a > b;
}

signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int lenn = n * m;
	int xr = 0;
	for (int i = 1; i <= lenn; i++) {
		cin >> h[i];
		if (i == 1)
			xr = h[i];
	}
	sort(h + 1, h + lenn + 1, cmp);
	int left = 1, right = lenn;
	int k = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (h[mid] == xr) {
			k = mid;
			break;
		}
		if (h[mid] < xr)
			right = mid - 1;
		if (h[mid] > xr)
			left = mid + 1;
	}
	int sum = 1;
	int j = 1;
	int i = 1;
	while (sum != k) {
		if ((j == n && i % 2 != 0) || (j == 1 && i % 2 == 0)) {
			sum++;
			i++;
			continue;
		}
		if (i % 2 != 0 && j < n) {
			j++;
			sum++;
		} else if (i % 2 == 0 && j > 1) {
			j--;
			sum++;
		}
	}
	if (sum == k) {
		cout << i << " " << j;
		return 0;
	}
	return 0;
}
