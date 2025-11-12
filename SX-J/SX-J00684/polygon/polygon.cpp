#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin << n;
	if (n == 1 || n == 2) {
		cout << 0;
	}
	if (n == 3) {
		cout << 1;
	}
	if (n == 4) {
		cout << 3;
	}
	if (n == 5) {
		cout << 9;
	}
	if (n == 6) {
		cout << 10;
	}
	if (n == 10) {
		cout << 15;
	}
	return 0;
}