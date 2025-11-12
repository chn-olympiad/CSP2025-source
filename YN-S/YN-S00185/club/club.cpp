#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	int m[t + 3];
	int q = 1;

	while (t--) {
		int a[100009][5];//总数组
		int j1mub = 0, j2mub = 0, j3mub = 0;
		int sum = 0;
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {

			for (int j = 1; j <= 3; j++) {

				cin >> a[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {

			int b[3] = {a[i][1], a[i][2], a[i][2]};
			int g = 0;
			sort(b, b + 3);
			int bh[3];

			for (int k = 0; k <= 2; k++) { //从大到小满意度+部门

				for (int j = 1; j <= 3; j++) {

					if (b[k] == a[i][j]) {
						bh[g++] = j;
						break;
					}
				}
			}

			if (bh[0] == 1) { //1
				if (j1mub < n / 2) {
					j1mub++;
					sum += b[0];
				} else if (bh[1] == 2) {
					if (j2mub < n / 2) {
						j2mub++;
						sum += b[1];
					} else {
						j3mub++;
						sum += b[2];
					}
				} else {
					if (j3mub < n / 2) {
						j3mub++;
						sum += b[1];
					} else {
						j2mub++;
						sum += b[2];
					}
				}
			} else if (bh[0] == 2) { //2
				if (j2mub < n) {
					j2mub++;
					sum += b[0];
				} else if (bh[1] == 1) {
					if (j1mub < n / 2) {
						j1mub++;
						sum += b[1];
					} else {
						j3mub++;
						sum += b[2];
					}
				} else {
					if (j3mub < n / 2) {
						j3mub++;
						sum += b[1];
					} else {
						j1mub++;
						sum += b[2];
					}
				}
			} else { //3
				if (j3mub < n) {
					j3mub++;
					sum += b[0];
				} else if (bh[1] == 2) {
					if (j2mub < n / 2) {
						j2mub++;
						sum += b[1];
					} else {
						j1mub++;
						sum += b[2];
					}
				} else {
					if (j1mub < n / 2) {
						j3mub++;
						sum += b[1];
					} else {
						j2mub++;
						sum += b[2];
					}
				}
			}
		}

		m[q++] = sum;
	}

	for (int i = 1; i <= t; i++) {

		cout << m[i] << endl;
	}

	return 0;
}
