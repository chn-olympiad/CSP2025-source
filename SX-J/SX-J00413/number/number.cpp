#include <bits/stdc++.h>
using namespace std;
string a;

int n[100005] = {};

bool cmd(int z, int x) {
	return z > x;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int w1 = 0;
	for (int q = 0; q < a.length(); q++) {
		if (a[q] <= '9') {
			n[w1] = a[q] - '0';
			w1++;
		}
	}
	sort(n, w1 + n, cmd);
	for (int e = 0; e < w1; e++)
		cout << n[e];
	return 0;
}