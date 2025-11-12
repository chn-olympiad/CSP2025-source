#include <bits/stdc++.h>
using namespace std;
int s[105];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int c, r, sh = 0;
	cin >> c >> r;
	for (int i = 0; i < c * r; i++) {
		cin >> s[i];
	}
	int cj = s[0];
	sort(s, s + r *c, cmp);
	for (int i = 0; i < c * r; i++) {
		if (s[i] == cj) {
			sh = i + 1;
		}
	}
	int cc = sh / r  ;
	int rr = sh - cc * r;
	if (cc % 2 != 0)
		rr = r;
	if (cc * r != sh)
		cc++;
	cout << cc << " " << rr;
	return 0;
}
