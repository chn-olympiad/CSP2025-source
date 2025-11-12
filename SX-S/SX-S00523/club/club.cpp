#include <bits\stdc++.h>
using namespace std;

long long t, n, a[100010][10];
//long long tong[10];
long long ans;

int maxx(int i) {
	if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
		return 1;
	if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
		return 2;
	if (a[i][3] >= a[i][2] && a[i][3] >= a[i][1])
		return 3;
	return 0;
}

int mid(int i) {
	if ((a[i][1] >= a[i][2] && a[i][1] <= a[i][3]) || (a[i][1] <= a[i][2] && a[i][1] >= a[i][3]))
		return 1;
	if ((a[i][2] >= a[i][1] && a[i][2] <= a[i][3]) || (a[i][2] <= a[i][1] && a[i][2] >= a[i][3]))
		return 2;
	if ((a[i][3] >= a[i][2] && a[i][3] <= a[i][1]) || (a[i][3] <= a[i][2] && a[i][3] >= a[i][1]))
		return 3;
	return 0;
}

int minn(int i) {
	if (a[i][1] <= a[i][2] && a[i][1] <= a[i][3])
		return 1;
	if (a[i][2] <= a[i][1] && a[i][2] <= a[i][3])
		return 2;
	if (a[i][3] <= a[i][2] && a[i][3] <= a[i][1])
		return 3;
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	cin >> t;
	while (t--) {
//		int a[100010][10];
		a[100010][10] = {0};
		long long tong[10] = {0};
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				cin >> a[i][j];
		}
		for (int i = 1; i <= n; i++) {
			int m;
			m = maxx(i);
			if (tong[maxx(i)] == n / 2) {
				m = mid(i);
				if (tong[mid(i)] == n / 2)
					m = minn(i);
			}

			ans += a[i][m];
			tong[m]++;
		}
		cout << ans << "\n";
	}

	return 0;
}
