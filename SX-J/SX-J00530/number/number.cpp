#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
char e[1000005];
long long z[1000005], m = 0;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	for (int i = 0; i <= 100005; i++) {
		cin >> e[i];
	}
	for (int i = 0; e[i]; i++) {
		if (e[i] - '0' <= 9) {
			z[i] = e[i];
			m++;
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 9) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 8) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 7) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 6) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 5) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 4) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 3) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 2) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 1) {
			cout << z[i];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (z[i] == 0) {
			cout << z[i];
		}
	}
	return 0;
}
