#include <bits/stdc++.h>
using namespace std;
long long T, n, a[100001][4], m, ans, b[100001], flag;

struct wd {
	long long value;
	long long pos;
} c[101011];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T > 0) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			c[i].value = max(a[i][1], max(a[i][2], a[i][3]));
			c[i].pos = i;
			if (a[i][3] == 0 && a[i][2] == 0 ) { //开始特判A
				flag++;
			}
		}
		if (flag == n) {
			for (int i = 1; i <= n; i++) {
				b[i] = a[i][1];
			}
			sort(b + 1, b + n + 1);
			reverse(b + 1, b + n + 1);
			for (int z = 1; z <= n / 2; z++) {

				ans += b[z];
			}//特判A结束
		} else {
			for (int z = 1; z <= n; z++) {

				ans += c[z].value;
			}
		}
		cout << ans << endl;
		ans = 0;
		flag = 0;
		T--;
	}

	return 0;
}
//in:3 4 1 0 0 2 0 0 4 0 0 3 0 0  2 1 0 0 2 0 0 2 1 2 3 3 4 5out:7 2