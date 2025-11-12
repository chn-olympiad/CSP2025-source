#include <bits/stdc++.h>
using namespace std;
int n;
int m;
char s[501];
int c[501];

int z[501] = {1};
int x = 1;
int y = 1;

int main() {
	freopen(employ.in, "r", stdin);
	freopen(employ.out, "w", stdout);
	cin >> n;
	cin >> m;
	for (int q = 0; q < n; q++) {
		cin >> s[q];
	}
	for (int q = 0; q < n; q++) {
		cin >> c[q];
	}
	for (int a = 1; a < n; a++) {
		z[a] = z[a - 1] + 1;
	}
	for (int w = n - 2; w < n; w++) {//1234
		x = x * z[w];

	}
	for (int e = 0; e < m  ; e++) {
		y = y * z[e];
	}
	cout << x / y;
}
