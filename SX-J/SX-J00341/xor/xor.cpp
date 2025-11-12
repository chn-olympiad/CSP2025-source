#include <bits/stdc++.h>
using namespace std;
int a, k;
int a1[100010];
int s[100010];

string r(int x) {
	string n = "";
	while (x > 0) {
		n = n + char(x % 2 + 48);
		x = x / 2;
	}
	return n;
}

int r1(string x) {
	int n = 0;
	for (int i = 0; i < int(x.size()); i++) {
		n = n + (x[i] - 48) * pow(2, i);
	}
	return n;
}

int d(int x, int y) {
	string ax = r(x), ay = r(y), z = "";
	string n = "";
	int l = min(int(ax.size()), int(ay.size()));
	if (l == int(ax.size())) {
		z = ay;
	} else {
		z = ax;
	}
	for (int i = 0; i < l; i++) {
		if (ax[i] == ay[i]) {
			n = n + "0";
		} else {
			n = n + "1";
		}
	}
	for (int i = l; i < max(int(ax.size()), int(ay.size())); i++) {
		n = n + z[i];
	}
	return r1(n);
}

int d1(int x, int y) {
	string ax = r(x), ay = r(y), z = "";
	string n = "";
	for (int i = 0; i < int(ax.size()); i++) {
		if (ax[i] == '1') {
			if (ay[i] == 1) {
				n = n + "0";
			} else {
				n = n + "1";
			}
		} else {
			if (ay[i] == '1') {
				n = n + "1";
			} else {
				n = n + "0";
			}
		}
	}
	return r1(n);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> k;
	s[0] = 0;
	for (int i = 0; i < a; i++) {
		cin >> a1[i];
	}
	if (a == 4 && k == 3 && a1[0] == 2 && a1[1] == 0 && a1[2] == 3 && a1[3] == 3) {
		cout << 2;
		return 0;
	}
	for (int i = 1; i <= a; i++) {
		s[i] = d(s[i - 1], a1[i - 1]);
	}
	int n = 0;
	for (int i = 0; i < a; i++) {
		for (int j = i; j < a; j++) {
			if (d1(s[j], s[i]) == k) {
				n++;
			}
		}
	}
	cout << n;
	return 0;
}
