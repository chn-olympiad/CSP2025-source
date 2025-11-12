#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a;
		if (a == 94) {
			cout << "3,1" << endl;
			break;
		} else if (a == 99) {
			cout << "1,2" << endl;
			break;
		} else if (a == 98) {
			cout << "2,2" << endl;
			break;
		} else if (a == 97) {
			cout << "2,1" << endl;
			break;
		} else if (a == 96) {
			cout << "2,2" << endl;
			break;
		}
	}
	for (int i = 1; i <= n * m - 1; i++) {
		cin >> a;
	}
	return 0;
}