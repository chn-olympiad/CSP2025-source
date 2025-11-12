#include <bits/stdc++.h>
using namespace std;
int w[100005];


int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string a, b;
	cin >> a;
	int q = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '0') {
			w[q] = 0;
			q++;
		}
		if (a[i] == '1') {
			w[q] = 1;
			q++;
		}
		if (a[i] == '2') {
			w[q] = 2;
			q++;
		}
		if (a[i] == '3') {
			w[q] = 3;
			q++;
		}
		if (a[i] == '4') {
			w[q] = 4;
			q++;
		}
		if (a[i] == '5') {
			w[q] = 5;
			q++;
		}
		if (a[i] == '6') {
			w[q] = 6;
			q++;
		}
		if (a[i] == '7') {
			w[q] = 7;
			q++;
		}
		if (a[i] == '8') {
			w[q] = 8;
			q++;
		}
		if (a[i] == '9') {
			w[q] = 9;
			q++;
		}
	}
	sort(w, w + q + 1);
	for (int i = q; i >= 1; i--) {
		cout << w[i];
	}

	cout << b;
}
