#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int c[10][10];
	for (int i = 1; i <= a * b; i++) {
		cin >> c[i][i];
	}
	for (int i = 1; i <= a * b; i++) {
		if (c[i][i] > c[i + 1][i]) {
			swap(c[i][i], c[i + 1][i]);
		}
	}
	return 0;
}