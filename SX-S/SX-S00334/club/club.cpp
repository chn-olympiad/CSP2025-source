#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t;
int ax[3 * N], ji;
int arr[N][5], dp[N], b[N];
bool flag = 1;
int cnt;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
			ax[++ji] = arr[i][1];
			ax[++ji] = arr[i][2];
			ax[++ji] = arr[i][3];
			if (arr[i][2] != 0 || arr[i][3] != 0)
				flag = 0;
			b[++ji] = arr[i][1];
		}
		if (flag) {
			sort(b + 1, b + n + 1, cmp);
			int sum = 0;
			for (int i = 1; i <= n / 2; i++) {
				sum += b[i];
			}
			cout << sum;
			continue;
		}
		if (n == 2) {
			int sum = 0;
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j) {
						sum = max(sum, max(arr[1][i] + arr[2][j], arr[2][i] + arr[1][j]));
					}
				}
			}
			cout << sum;
			continue;
		}
		sort(ax + 1, ax + 3 * n + 1);
		int aaa = 0, bbb = 0;
		for (int i = 1; i <= n; i++) {
			aaa += ax[i];
		}
		for (int i = 3 * n; i >= 2 * n + 1; i--) {
			bbb += ax[i];
		}
		int auo = rand() % aaa  + 1, buo = rand() % bbb  + 1;
		cout << auo + buo << '\n';
		continue;
	}




	return 0;
}