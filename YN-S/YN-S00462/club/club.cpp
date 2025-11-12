#include <bits/stdc++.h>
using namespace std;

struct node {
	int z;
	int zu;
	int se;
	int th;
};

int fen(int x) {
	node o[100005];
	int f[5] = {0,};
	int fa[100005] = {0,};
	int sum;
	sum = 0;
	for (int i = 1; i <= x; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		int m = max(a, max(b, c));
		o[i].zu = m;
		if (a == m) {
			o[i].z = 1;
			o[i].se = max(b, c);
			if (o[i].se = b) {
				o[i].th = c;
			} else {
				o[i].th = b;
			}
		} else if (b == m) {
			o[i].z = 2;
			o[i].se = max(a, c);
			if (o[i].se = a) {
				o[i].th = c;
			} else {
				o[i].th = a;
			}
		} else {
			o[i].z = 3;
			o[i].se = max(b, a);
			if (o[i].se = b) {
				o[i].th = a;
			} else {
				o[i].th = b;
			}
		}
	}
	for (int i = x; i >= 1; i--) {
		if (f[o[i].z ] < x / 2) {
			sum += o[i].zu ;
			f[o[i].z ]++;
			fa[i] = 1;
		}
	}
	for (int i = 1; i <= x; i++) {
		if (fa[i] != 1 && f[2] < x / 2) {
			sum += o[i].se  ;
		} else if (fa[i] != 1) {
			sum += o[i].th;
		}
	}
	return sum;
}

int main(void) {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n;
		cin >> n;
		cout << fen(n);
	}
	return 0;
}