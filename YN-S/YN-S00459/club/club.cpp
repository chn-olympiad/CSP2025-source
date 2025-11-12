#include <bits/stdc++.h>
using namespace std;
long long b[100005][10], z;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int  i = 1; i <= n; i++) {
			cin >> b[i][1] >> b[i][2] >> b[i][3];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				b[i][j] = max(b[i][j] + b[i - 1][1], max(b[i][j] + b[i - 1][2], b[i][j] + b[i - 1][3]));
			}
		}
		z = max(b[n][1], max(b[n][2], b[n][3]));
		cout << z << endl;
	}
	return 0;
}