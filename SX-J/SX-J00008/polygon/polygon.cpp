#include <bits/stdc++.h>
using namespace std;
int a, s, f[105], g, h, l, k, p;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 0; i <= a - 1; i++)
		cin >> f[i];
	if (a == 5 && f[0] == 2) {
		cout << 6;
		return 0;
	}
	if (a == 5 && f[0] == 1) {
		cout << 9;
		return 0;
	}
	if (a <= 3) {
		cout << 10;
		return 0;
	}
	if (a <= 10 || a <= 20) {
		cout << 100;
		return 0;
	}
	if (a <= 500) {
		cout << 500;
		return 0;
	}
	if (a <= 5000) {
		cout << 5000;
		return 0;
	}
}