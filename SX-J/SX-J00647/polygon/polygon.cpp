#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y) {
	return x > y;
}
int n, sum, ans;
int arr[4];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr + 1, arr + 1 + n, cmp);
	if (sum > 2 * arr[1])
		ans++;
	cout << ans % 998244353;
	return 0;
}

