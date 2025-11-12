#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[102000];
long long b[102000];

int ejz(int x) {
	int ys;
	vector<int> y;
	while (x > 1) {
		ys = x % 2;
		x /= 2;
		y.push_back(ys);
	}
	y.push_back(x);
	int jg = 0;
	for (int i = y.size() - 1; i >= 0; i--) {
		jg *= 10;
		jg += y[i];
	}
	return jg;
}

int qqz(int x, int y) {
	int i = max(sizeof(b[x]), sizeof(b[y]));
	int cans[i + 10];
	int bx = b[x], by = b[y];
	int l = i;
	while (i > 0) {
		if (bx % 10 == by % 10)
			cans[i] = 0;
		else
			cans[i] = 1;
		bx /= 10;
		by /= 10;
		i--;
	}
	int zans = 0;
	int k1 = 0;
	for (int j = 1; j <= l; j++) {
		zans += cans[i] * pow(2, k1);
		k1++;
	}
	return zans;
}

int qz(int x, int y) {
	int q = x;
	for (int i = x + 1; i <= y; i++) {
		q = qqz(q, i);
	}
	return q;
}



int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = ejz(a[i]);
	}
	int ans = 0;
	sort(b, b + n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (i == k && j == k)
				ans++;
			else if (qz(i, j) == k) {
				ans++;
			}
		}
	}

	cout << ans + 1 << endl;
	return 0;
}
