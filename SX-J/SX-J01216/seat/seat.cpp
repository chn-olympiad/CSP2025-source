#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[110];

bool cmp(int x, int y) {
	if (x > y)
		return true;
	else
		return false;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int ans;
	bool flag = 1;
	cin >> n >> m ;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i == 1)
			ans = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	int s = 1;
	for (int i = 1; i <= m; i++) {
		if (flag) {
			for (int j = 1; j <= n; j++) {
				//cout << j << " " << i;
				if (a[s++] == ans) {
					//cout << ans;
					//cout << a[s++] << " ";
					cout << i << " " << j;
					return 0;
				}
			}
			flag = 0;
		} else {
			for (int j = n; j >= 1; j--) {
				//cout << j << " " << i;
				if (a[s++] == ans) {
					//cout << ans;
					//cout << a[s++] << " ";
					cout << i << " " << j;
					return 0;
				}
			}
			flag = 1;
		}
	}
	return 0;
}