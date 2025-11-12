#include <bits/stdc++.h>
using namespace std;
string a;
char m[1000005];
int b[1000005];
int i = 0;

inline cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int j = 0; j <= a.size(); j++) {
		if (a[j] == '9') {
			b[j] = 9;
			i++;
		}
		if (a[j] == '8') {
			b[j] = 8;
			i++;
		}
		if (a[j] == '7') {
			b[j] = 7;
			i++;
		}
		if (a[j] == '6') {
			b[j] = 6;
			i++;
		}
		if (a[j] == '5') {
			b[j] = 5;
			i++;
		}
		if (a[j] == '4') {
			b[j] = 4;
			i++;
		}
		if (a[j] == '3') {
			b[j] = 3;
			i++;
		}
		if (a[j] == '2') {
			b[j] = 2;
			i++;
		}
		if (a[j] == '1') {
			b[j] = 1;
			i++;
		}
		if (a[j] == '0') {
			b[j] = 0;
			i++;
		}
	}
	int m = a.size();
	sort(b, b + m, cmp);
	for (int j = 0; j < i; j++) {
		cout << b[j];
	}
	return 0;
}
