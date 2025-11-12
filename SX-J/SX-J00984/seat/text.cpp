#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("text.in", "r", stdin);
	freopen("text.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int q[101], o = n * m, w = 0;
	cin >> q[1];
	for (int i = 2; i <= o; i++) {
		cin >> q[i];
		if (q[1] < q[i]) {
			w++;
		}
	}//3 3
	for (int i = 1; i <= m; i++) {
		int qq = 0;
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (w == 0) {
					cout << i << " " << j;
					qq = 1;
					break;
				}
				w--;
			}
		} else {
			for (int j = 1; j <= n; j++) {
				if (w == 0) {
					cout << i << " " << j;
					qq = 1;
					break;
				}
				w--;
			}
		}

		if (qq == 1) {
			break;
		}
	}
	return 0;
}
