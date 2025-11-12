#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000000], rjz[100000];

int bin(int a) {
	int s = a, y, r, ws = 1;
	for (int i = 0; s != 0; i++) {
		y = s % 2;
		s = s / 2;
		r = r + y * ws;
		ws = ws * 10;
	}
	return r;
}

int qxor(int a, int b) {
	int aw, bw, w, jg, ws = 1;
	while (a != 0 && b != 0) {
		aw = a % 10;
		bw = b % 10;
		if (aw + bw == 1) {
			w = 1;
		} else {
			w = 0;
		}
		jg = jg + w * ws;
		ws = ws * 10;
		a = a / 10;
		b = b / 10;
	}
	if (a != 0) {
		jg = a * ws + jg;
	} else {
		jg = b * ws + jg;
	}
	return jg;
}

int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
//	cin >> n >> k;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		rjz[i] = bin(a[i]);
//	}
	int z, x;
	cin >> z >> x;
	cout << qxor(z, x);
	return 0;
}
