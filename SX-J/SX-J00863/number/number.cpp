#include <bits/stdc++.h>
using namespace std;
int d[1000001];

int cmp(int p, int b) {
	return p > b;
}

int main() {
	foropen("number.in", "r", stdin);
	foropen("number.out", "w", stdout);
	string a;
	int i, g, s = 0;
	cin >> a;
	g = a.size();
	for (i = 0; i < g; i++) {
		if (a[i] >= 48 && a[i] <= 57) {
			d[s] = a[i] - 48;
			s++;
		}
	}
	sort(d, d + s, cmp);
	for (i = 0; i < s; i++) {
		cout << d[i];
	}
	return 0;
}