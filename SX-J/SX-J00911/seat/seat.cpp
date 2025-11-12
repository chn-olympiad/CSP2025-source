#include <bits\stdc++.h>
using namespace std;
int a[20][20], i = 1, n, m, j, a1[1000], s = -1, k;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (i = 0; i < n * m; i++)
		cin >> a1[i];
	k = a1[0];
	//cout << k;
	sort(a1, a1 + n *m, greater<int>());
	i = 0;
	for (j = 0; j < m; j++) {
		if (i == 0 || i == -1)
			for (i = 0; i < n; i++) {
				s++;
				a[i][j] = a1[s];

				if (a[i][j] == k) {
					cout << j + 1 << " " << i + 1;
					return 0;
				}

			} else {
			//s--;
			for (i = n - 1; i >= 0; i--) {
				s++;
				a[i][j] = a1[s];

				if (a[i][j] == k) {
					cout << j + 1 << " " << i + 1;
					return 0;
				}

			}

		}
	}
	//if (i != 0)
	//a[i][j] = a1[s];
	/*
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	*/

	return 0;
}
