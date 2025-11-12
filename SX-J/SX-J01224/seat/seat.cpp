#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen ("seat.in", "r", stdin);
	freopen ("seat.out", "w", stdout);
	int a, b;
	int ma;
	cin >> a  >> b;
	string ai;
	cin >> ai;
	if (ai[0] > ai[1]) {
		ma = ai[0];
	} else {
		ma = ai[1];
	}
	for (int i = 2; i < a * b; i ++) {
		if (ai[i] > ma) {
			ma = ai[i];
		} else {
			ma = ma;
		}
	}
	cout << ma;
	return 0;
}
