#include <bits/stdc++.h>
using namespace std;
int a[1145140], tp, k;
char b[1145140];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin.getline(b + 1, 114514);
	for (int i = 1; i <= 114514; i++) {
		if (b[i] == '1') {
			tp++;
			a[tp] = 1;
		}
		if (b[i] == '2') {
			tp++;
			a[tp] = 2;
		}
		if (b[i] == '3') {
			tp++;
			a[tp] = 3;
		}
		if (b[i] == '4') {
			tp++;
			a[tp] = 4;
		}
		if (b[i] == '5') {
			tp++;
			a[tp] = 5;
		}
		if (b[i] == '6') {
			tp++;
			a[tp] = 6;
		}
		if (b[i] == '7') {
			tp++;
			a[tp] = 7;
		}
		if (b[i] == '8') {
			tp++;
			a[tp] = 8;
		}
		if (b[i] == '9') {
			tp++;
			a[tp] = 9;
		}
		if (b[i] == '0') {
			tp++;
			a[tp] = 0;
		}
		if (b[i] == 0) {
			break;
		}
	}
	sort(a + 1, a + tp + 1);
	for (int i = tp; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
