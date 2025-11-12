#include <bits/stdc++.h>
using namespace std;
int y11[100005], y21[100005], y31[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int p = 1; p <= t; p++) {
		int n, a = 0, b = 0, c = 0, x1, x2, x3, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x1 >> x2 >> x3;
			if (x1 >= x2 && x1 >= x3) {
				ans += x1;
				a++;
				y11[a] = x1 - max(x2, x3);
			} else if (x2 > x1 && x2 >= x3) {
				ans += x2;
				b++;
				y21[b] = x2 - max(x1, x3);
			} else if (x3 > x1 && x3 > x2) {
				ans += x3;
				c++;
				y31[c] = x3 - max(x2, x1);
			}
		}
		if (a > n / 2) {
			sort(y11 + 1, y11 + a + 1);
			for (int i = 1; i <= (a - (n / 2)); i++)
				ans -= y11[i];
		} else if (b > n / 2) {
			sort(y21 + 1, y21 + b + 1);
			for (int i = 1; i <= (b - (n / 2)); i++)
				ans -= y21[i];
		} else if (c > n / 2) {
			sort(y31 + 1, y31 + c + 1);
			for (int i = 1; i <= (c - (n / 2)); i++)
				ans -= y31[i];
		}
		cout << ans << endl;
	}
	return 0;
}
