#include <bits/stdc++.h>
using namespace std;

int main() {
	int a[100][100];
	int x, y, n, r, num = 0;
	int s[100];
	cin >> x >> y;
	for (int i = 1; i <= x * y; i++) {
		cin >> s[i];
	}
	r = s[1];
	for (int i = 1; i <= x * y; i++) {
		for (int j = i + 1; j <= x * y; j++) {
			if (s[i] < s[j]) {
				n = s[i];
				s[i] = s[j];
				s[j] = n;
			}
		}
	}
	for (int i = 1; i <= x; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= y; j++) {
				num++;
				a[i][j] = s[num];
			}
		} else if (i % 2 == 0) {
			for (int j = y; j >= 1; j--) {
				num++;
				a[i][j] = s[num];
			}
		}
	}
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			if (a[i][j] == r) {
				cout << i << ' ' << j << endl;
			}
		}
	}
	return 0;
}
