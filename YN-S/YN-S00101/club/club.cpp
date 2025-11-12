#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int a[N][N];
int a1[N], a2[N], a3[N], a4[N];
int ans;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int k = n / 2;
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 1)
					a1[i] = a[i][j];
				else if (j == 2)
					a2[i] = a[i][j];
				else if (j == 3)
					a3[i] = a[i][j];
			}
		}
		sort(a1 + 1, a1 + n + 1, cmp);
		sort(a2 + 1, a2 + n + 1, cmp);
		sort(a3 + 1, a3 + n + 1, cmp);
		for (int i = 1; i <= k * 3; i++) {
			if (i >= 1 && i <= k)
				a4[i] = a1[i];
			else if (i > k && i <= 2 * k)
				a4[i] = a2[i - k];
			else if (i > k * 2 && i <= 3 * k)
				a4[i] = a3[i - 2 * k];
		}
		sort(a4 + 1, a4 + 3 * k + 1, cmp);
		for (int i = 1; i <= n; i++) {
			ans += a4[i];
		}
		cout << ans << endl;
	}
	return 0;
}

