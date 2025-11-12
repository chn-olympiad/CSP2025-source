#include <iostream>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int st = 0;
	int n, m, wen, tp2 = 1, ls2tp = 1, temp;
	cin >> n >> m;
	int list[n][m];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> list[i][j];
		}
	}
	wen = list[1][1];
	int list2[m * n], ls2i = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			list2[ls2i] = list[i][j];
			ls2i++;
		}
	}
	for (int i = 1; i <= m * n; i++) {
		for (int j = 1; j <= m * n; j++) {
			if (list2[j] < list2[j + 1]) {
				if (j == m * n) {
					break;
				}
				temp = list2[j];
				list2[j] = list2[j + 1];
				list2[j + 1] = temp;
			}
		}
	}
	int ls3[n][m];
	for (int i = 1; i <= m; i++) {
		if (tp2 == 1) {
			for (int j = 1; j <= n; j++) {
				if (ls2tp == m * n + 1) {
					st = 1;
					break;
				}
				ls3[i][j] = list2[ls2tp];
				ls2tp ++;
				tp2 ++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				if (ls2tp == m * n + 1) {
					st = 1;
					break;
				}
				ls3[i][j] = list2[ls2tp];
				ls2tp++;
				tp2--;
			}
		}//

		if (st == 1) {
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ls3[i][j] == wen) {
				cout << i << " " << j;
			}
		}
	}
	return 0;
}
