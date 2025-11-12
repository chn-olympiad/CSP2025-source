#include <bits/stdc++.h>
using namespace std;
int n[1005][1005], m[10005], m1, l = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a * b; i++) {
		cin >> m[i];
	}
	m1 = m[0];
	sort(m, m + (a *b), cmp);
	for (int i = 0; i < b; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < a; j++) {
				n[i][j] = m[l];
				l++;
			}
		} else {
			for (int k = a - 1; k >= 0; k--) {
				n[i][k] = m[l];
				l++;
			}
		}
	}
	for (int i = 0; i < b; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < a; j++) {
				if (n[i][j] == m1) {
					cout << i + 1 << " " << j + 1;
					return 0;
				}
			}
		} else {
			for (int j = a - 1; j >= 0; j--) {
				if (n[i][j] == m1) {
					cout << i + 1 << " " << j + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}
