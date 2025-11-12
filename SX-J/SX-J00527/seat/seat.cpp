#include <bits/stdc++.h>
using namespace std;
int a[20];
int n, m;
int d[20][20];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int n1 = n * m;
	for (int i = 1; i <= n1; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1) {
		cout << n << " " << m;
		return 0;
	}
	m = a[1];
	cout << m << endl;
	sort(a + 1, a + n1 + 1, cmp);
	int s1 = 0, s2 = 0, k = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[j][i] = a[k];
			if (j == n) {
				i++;
				for (int l = n; l >= 1; l--) {
					k++;
					d[l][i] = a[k];
				}
				j++;
				k++;
			} else
				k++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << " " ;
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == m)
				cout << j << " " << i;
		}
	}
	return 0;
}