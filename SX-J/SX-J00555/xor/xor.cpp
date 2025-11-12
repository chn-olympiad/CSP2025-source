#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m, k[100] = {};
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		if (k[i] == m || i == 4) {
			if (k[2] == 0) {
				if (k[1] + k[2] == k[4] && k[1] - k[2] == k[4] && k[2] - k[1] == k[4]) {
					cout << "2";
				}
			}
			if (k[1] == 0) {
				if (k[3] + k[2] == k[4] && k[3] - k[2] == k[4] && k[2] - k[3] == k[4]) {
					cout << "2";
				}
			}
			if (k[2] == 0) {
				if (k[1] + k[3] == k[4] && k[1] - k[3] == k[4] && k[3] - k[1] == k[4]) {
					cout << "2";
				}
			}

		}
		if (k[i] == m || i == 1) {
			if (k[3] == 0) {
				if (k[2] + k [4] == k[1] && k[4] - k[2] == k[1] && k[2] - k[4] == k[1]) {
					cout << "2";
				}
				if (k[2] == 0) {
					if (k[3] + k [4] == k[1] && k[1] - k[2] == k[1] && k[2] - k[1] == k[1]) {
						cout << "2";
					}
					if (k[4] == 0) {
						if (k[2] + k [3] == k[1] && k[2] - k[3] == k[1] && k[3] - k[2] == k[1]) {
							cout << "2";
						}
					} else {
						cout << "2";
					}
				}
			}
		}
	}
	return 0;
}
