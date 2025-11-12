#include <bits/stdc++.h>
using namespace std;
long long a[10];
int ww = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	long long q;
	cin >> q;
	if (q < 0) {
		q = q * -1;
		ww = 1;
	}
	int t[100000], i = 0;
	while (q != 0) {
		t[i] = q % 10;
		q /= 10;
		if (t[i] == 0) {
			a[0]++;
		} else if (t[i] == 1) {
			a[1]++;
		} else if (t[i] == 2) {
			a[2]++;
		} else if (t[i] == 3) {
			a[3]++;
		} else if (t[i] == 4) {
			a[4]++;
		} else if (t[i] == 5) {
			a[5]++;
		} else if (t[i] == 6) {
			a[6]++;
		} else if (t[i] == 7) {
			a[7]++;
		} else if (t[i] == 8) {
			a[8]++;
		} else if (t[i] == 9) {
			a[9]++;
		}
		i++;
	}
	if (ww == 0) {
		for (int j = 9; j > 0; j--) {
			for (int o = 1; o <= a[j]; o++) {
				cout << j;
			}
		}
	} else {
		cout << "-";
		for (int j = 0; j < 9; j++) {
			for (int o = 1; o <= a[j]; o++) {
				cout << j;
			}
		}
	}
	return 0;
}
