#include <bits/stdc++.h>
using namespace std;
long long n, a[100005][5], t, ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

int main() {
	freopen('club.in', 'r', stdin);
	freopen('club.out', 'w', stdout);
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			cin >> a[i][j];
		}
		ans1 += max(a[1][1], a[2][2], a[3][3]);
		ans2 += max(a[1][4], a[2][5], a[3][6]);
		ans3 += max(a[1][7], a[2][8], a[3][9]);
		ans4 += max(a[1][10], a[2][11], a[3][12]);
	}
	cout << ans1 << endl << ans2 << endl << ans3;
	return 0;
}