#include <bits/stdc++.h>
using namespace std;
int a[100], s[100];
int x[100][100];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int t = n * m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		s[i] = a[i];
	}
	sort(s + 1, s + 1 + t);
	for (int i = 1; i <= t; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				x[i][j] = s[t];
				t--;
			}
		} else {

			for (int l = 1; l <= n; l++) {
				x[i][l] = s[t];
				t--;
			}
		}
		/*for(int j=;j>=1;j--){

		if (a[1] == s[i]) {
			if (i > n) {

				if (i % n == 0) {
					cout << n << " " ;
					cout<< i / n << " ";
					return 0;
				} else {
					cout << i % n << " " ;
					cout<< i / n << " ";
				}
			} else
				cout << i << " " << 1;
		}
		if()
		}*/
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[1] == x[i][j])
				cout << i << " " << j << " ";
		}
	}
	return 0;
}
