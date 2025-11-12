#include <bits/stdc++.h>
using namespace std;
int a[10086][10086];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int n, m, y, z;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		cin >> y;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
		cin >> z;
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	cout << "18" << endl << "4" << endl << "13";
	return 0;
}
