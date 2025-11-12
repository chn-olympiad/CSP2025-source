#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t, n;
	cin >> t;
	int a[t][100][100];
	int b[t];

	for (int i = 0; i < t; i++) {

		cin >> n;
		b[i] = n;

		for (int j = 0; j < n; j++) {

			for (int m = 0; m < 3; m++)

				cin >> a[i][j][m];
		}
	}

	for (int i = 0; i < t; i++) {

		cout << i + 1 << endl;

		for (int j = 0; j < b[i]; j++) {

			for (int m = 0; m < 3; m++) {

				cout << a[i][j][m] << " ";
			}

			cout << endl;
		}
	}

	return 0;
}
