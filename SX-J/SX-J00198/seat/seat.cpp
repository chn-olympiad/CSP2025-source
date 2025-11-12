#include <bits/stdc++.h>
using namespace std;
int cj[200];
int x, y, mc, zb;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> y >> x;
	for (int i = 0; i < y * x; i++) {
		cin >> cj[i];
	}
	mc = cj[0];
	int p = y * x;
	for (int i = 0; i < y * x; i++) {
		for (int j = 1; j < p; j++) {
			if (cj[j] > cj[j - 1]) {
				int o = cj[j];
				cj[j] = cj[j - 1];
				cj[j - 1] = o;
			}
		}
		p--;
	}
	for (int i = 1; i <= y * x; i++) {
		if (cj[i - 1] == mc) {
			zb = i;
		}
	}
	int ls = zb % y, ll = zb / y;
	if (zb / y == 1 && ls == 0) {
		cout << 1 << " " << y;
	} else if (ll % 2 != 0) {
		cout <<  ll + 1 << " " << y + 1 - ls ;
	} else if (ll % 2 == 0) {
		cout <<  ll + 1 << " " << ls ;
	}
	return 0;
}
