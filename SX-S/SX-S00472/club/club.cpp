#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t, n, f[N], m, a[N][4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		cin >> n;
		m = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= 1; j--)
				f[j] = max(f[j], f[j - 1] + a[i][1]);
		}
		cout << f[m];
	}





	fclose(stdin);
	fclose(stdout);
	return 0;
}
