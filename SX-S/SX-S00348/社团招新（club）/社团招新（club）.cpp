#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int max = INT_MIN;
	int t, n, x1 = 0, x2 = 0, x3 = 0;
	cin >> t;
	for (int i = 1; i <= t; i++) { //while(t>0);
		cin >> n;
		int num1 = 0, num2 = 0, num3 = 0 ;
		for (int i = 1; i <= n; i++) {
			int a1, a2, a3 ;
			cin >> a1 >> a2 >> a3;

			if (a1 > a2 && a1 > a3 ) {
				num1 +=  a1;
				x1++;
			} else if (x1 >= n / 2) {
				int num1 = 0;
				if (a2 >= a3) {
					num1 = num1 + a2;
				} else if (a3 >= a2) {
					num1 = num1 + a3;
				}
			}

			if (a2 > a1 && a2 > a3)  {
				num2 += a2;
				x2++;
			}

			if (x2 >= n / 2) {
				int num2 = 0;
				if (a1 >= a3) {
					num2 = num2 + a1;
				}
			}

			if (a3 >= a1 && a3 >= a2 ) {
				num3 +=  a3;
				x3++;
			}

			if (x3 >= n / 2) {
				int num3 = 0;
				if (a1 >= a2) {
					num3 = num3 + a1;
				}
			}
		}
		cout << num1 << ' ' << x1 << " " << num2 << ' ' << x2 << " " << num3 << " " << x3 << ' ' << ' ' << num1 + num2 + num3;
	}

	return 0;
}
