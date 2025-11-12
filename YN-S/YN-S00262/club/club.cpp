#include <bits/stdc++.h>
using namespace std;
int n, b, ant, sum = 1, cnt, a;
int arr[1000][10000];
int ar[10000];
int a1, a2, a3;

int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	cin >> n;
	a = n;
	while (n >= 1) {
		cin >> b;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= b; j++) {
				cin >> arr[i][j];
			}
		}
		a1 = 0;
		a2 = 0;
		a3 = 0;
		sum = 1;
		cnt = 0;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= b; j++) {
				ar[sum] = arr[i][j];
				sum++;
			}
		}
		for (int i = 1; i <= sum - 1; i++) {

			if (i % 3 == 0) {
				if (ar[i] > ar[i - 1] && ar[i] > ar[i - 2]) {
					cnt += ar[i];
					a1++;
					if (a1 > b / 2) {
						cnt = cnt - ar[i];
						if ( ar[i - 1] > ar[i - 2]) {
							cnt += ar[i - 1];
						} else {
							cnt += ar[i - 2];
						}
					}
				} else if (ar[i - 1] > ar[i] && ar[i - 1] > ar[i - 2]) {
					cnt += ar[i - 1];
					a2++;
					if (a2 > b / 2) {
						cnt = cnt - ar[i - 1];
						if (ar[i] > ar[i - 2]) {
							cnt += ar[i];
						} else {
							cnt += ar[i - 3];
						}
					}
				} else {
					cnt += ar[i - 2];
					a3++;
					if (a3 > b / 2) {
						cnt = cnt - ar[i - 2];
						if (ar[i] > ar[i - 1] ) {
							cnt += ar[i];
						} else  {
							cnt += ar[i - 1];
						}
					}



				}
			}
		}

		cout << cnt << endl;
		n--;
	}
	return 0;
}