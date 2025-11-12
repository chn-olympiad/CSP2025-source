#include <bits/stdc++.h>
using namespace std;
int aa[1000001];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, ll;
	cin >> n >> m;
	ll = n * m;
	for (int i = 1; i <= ll; i++) {
		cin >> aa[i];
	}
	int first = aa[1];
	int y = 0;
	for (int i = 1; i <= ll; i++) {
		for (int j = 1; j <= ll; j++) {
			if (aa[j] > aa[j + 1]) {
				y = aa[j];
				aa[j] = aa[j + 1];
				aa[j + 1] = y;
			}
		}
	}
	int iii;
	for (int i = 1; i <= ll; i++) {
		if (aa[i] = first) {
			cout << i;
			iii = i;
		}
	}
	c = c / m
	if (c % 1 > 0) {
		cout << c + 1;
	} else {
		cout << c;
	}
	int r = r % m;



	return 0;
}