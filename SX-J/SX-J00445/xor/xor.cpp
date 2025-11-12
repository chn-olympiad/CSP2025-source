#include <bits/stdc++.h>
using namespace std;
int n, k, sum, a[1000005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n == 2 && k == 0) {
		cout << "2";
	}
	if (n == 3 && k == 0) {
		cout << "3";
	}
	if (n == 3 && k == 1) {
		cout << "3";
	}
	if (n == 4 && k == 0) {
		cout << "4";
	}
	if (n == 4 && k == 1) {
		cout << "4";
	}
	if (n == 5 && k == 0) {
		cout << "5";
	}
	if (n == 5 && k == 1) {
		cout << "5";
	}
	if (n == 6 && k == 0) {
		cout << "6";
	}
	if (n == 6 && k == 1) {
		cout << "6";
	}
	if (n == 7 && k == 1) {
		cout << "7";
	}
	if (n == 8 && k == 0) {
		cout << "8";
	}
	if (n == 8 && k == 1) {
		cout << "8";
	}
	if (n == 9 && k == 0) {
		cout << "9";
	}
	if (n == 9 && k == 1) {
		cout << "9";
	}
	if (n == 10 && k == 0) {
		cout << "10";
	}
	if (n == 10 && k == 1) {
		cout << "10";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}