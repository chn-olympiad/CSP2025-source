#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, r;
int a[10][10], e[100];

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int k = n * m - 1;
	for (i = 0; i < n * m; i++) {
		cin >> e[i];
	}
	r = e[0];
	sort(e, e + n *m);
	for (i = 0; i < n * m; i++) {
		cout << e[i] << " ";
	}
	cout << endl;
	for (i = 0 ; i < n; i++) {
		if ((i + 1) % 2 == 0) {
			for (j = m - 1; j >= 0; j--) {
				a[j][i] = e[k];
				if (a[j][i] == r) {
					cout << i + 1 << " " << j + 1 << endl;
				}
				k--;
			}
			continue;
		}
		for (j = 0; j < m; j++) {
			a[j][i] = e[k];
			if (a[j][i] == r) {
				cout << i + 1 << " " << j + 1 << endl;
			}
			k--;
		}
	}
	return 0;
}
