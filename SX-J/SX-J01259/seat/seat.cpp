#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, m, n;
	cin >> a >> m >> n;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			scanf("%d%d", &i, &j);
		}
	}
	int a[n][m];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			int b;
			if (a[b][j] > a[i][b]) {
				printf("%d", a);
			} else if (a[i][b] > a[b][j]) {
				printf("%d", a);
			} else(a[b][j] = a[i][b]) {
				pfintf("%d", a);
			}
		}
	}
	cout << a[n][m] << endl;
	return 0;
}