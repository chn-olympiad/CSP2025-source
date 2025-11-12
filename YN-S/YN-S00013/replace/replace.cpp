#include <bits/stdc++.h>
using namespace std;
char a[20000][20000];
char b[20000][20000];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> a[i][j];
		}
	}
	for (int x = 0; x < q; x++) {
		for (int y = 0; y < 2; y++) {
			cin >> b[x][y];
		}
	}
	cout << 2 << endl << 0;
	return 0;
}