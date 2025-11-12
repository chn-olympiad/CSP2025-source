#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	long long b[10005];
	long long i = 0, z = 0;
	cin >> a;
	long long f = a.size();
	while (f >= 0) {
		if (a[z] == '0') {
			b[i] = 0;
			i++;
		}
		if (a[z] == '1') {
			b[i] = 1;
			i++;
		}
		if (a[z] == '2') {
			b[i] = 2;
			i++;
		}
		if (a[z] == '3') {
			b[i] = 3;
			i++;
		}
		if (a[z] == '4') {
			b[i] = 4;
			i++;
		}
		if (a[z] == '5') {
			b[i] = 5;
			i++;
		}
		if (a[z] == '6') {
			b[i] = 6;
			i++;
		}
		if (a[z] == '7') {
			b[i] = 7;
			i++;
		}
		if (a[z] == '8') {
			b[i] = 8;
			i++;
		}
		if (a[z] == '9') {
			b[i] = 9;
			i++;
		}
		f--;
		z++;
	}
	sort(b, b + i);
	for (int j = i - 1; j >= 0; j--) {
		cout << b[j];
	}
	return 0;
}
