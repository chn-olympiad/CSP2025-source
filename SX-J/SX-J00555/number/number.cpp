#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n;
	int m[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, k[100] = {}, o = 0, j[10] = {};
	cin >> n;
	for (int i = 0; i < 10; i++) {
		j[i] = n % 10;
		n = n / 10;
		for (int l = 0; l < 10; l++) {
			if (j[i] == m[l]) {
				k[o] = j[l];
				o = o + 1;
			}
		}
	}
	sort(k, k + o - 1);
	for (int p = 0; p <= o; p++) {
		cout << k[p];
	}

	return 0;
}
