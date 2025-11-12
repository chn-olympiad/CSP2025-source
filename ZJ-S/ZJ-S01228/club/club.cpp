#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAXN 100010
using namespace std;
int n, ans = 0, n_2;
int arr[MAXN][4];
void f(int index, int c1, int c2, int c3, int sum) {
	if (index >= n) {
		ans = max(ans, sum);
		return;
	}
	if (c1 + 1 <= n_2) {
		f(index + 1, c1 + 1, c2, c3, sum + arr[index][1]);
	}
	if (c2 + 1 <= n_2) {
		f(index + 1, c1, c2 + 1, c3, sum + arr[index][2]);
	}
	if (c3 + 1 <= n_2) {
		f(index + 1, c1, c2, c3 + 1, sum + arr[index][3]);
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0, a0, a1, a2; i < n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
		}
		if (n <= 14) {
			n_2 = n / 2;
			ans = 0;
			f(0, 0, 0, 0, 0);
			cout << ans << "\n";
		} else {
			ans = 0;
			for (int i = 0; i < n; i++) {
				ans += max(arr[i][1], max(arr[i][2], arr[i][3]));
			}
			cout << ans << "\n";
		}
	} 
	return 0;
}

