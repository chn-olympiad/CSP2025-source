#include <bits/stdc++.h>
using namespace std;
string a;
int b, c[15], d;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, a);
	b = a.size();
	for (int i = 0; i < b; i++) {
		if (a[i] == '0') {
			c[0]++;
		} else if (a[i] == '1') {
			c[1]++;
		} else if (a[i] == '2') {
			c[2]++;
		} else if (a[i] == '3') {
			c[3]++;
		} else if (a[i] == '4') {
			c[4]++;
		} else if (a[i] == '5') {
			c[5]++;
		} else if (a[i] == '6') {
			c[6]++;
		} else if (a[i] == '7') {
			c[7]++;
		} else if (a[i] == '8') {
			c[8]++;
		} else if (a[i] == '9') {
			c[9]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (c[i] > 0) {
			for (int j = 0; j < c[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}
