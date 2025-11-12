#include <bits/stdc++.h>
using namespace std;

int h3(int a, int b, int c) {
	int sum = a + b + c;
	int maxx = max(a, max(b, c));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h4(int a, int b, int c, int d) {
	int sum = a + b + c + d;
	int maxx = max(a, max(b, max(c, d)));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h5(int a, int b, int c, int d, int e) {
	int sum = a + b + c + d + e;
	int maxx = max(a, max(b, max(c, max(d, e))));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h6(int a, int b, int c, int d, int e, int f) {
	int sum = a + b + c + d + e + f;
	int maxx = max(a, max(b, max(c, max(d, max(e, f)))));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h7(int a, int b, int c, int d, int e, int f, int g) {
	int sum = a + b + c + d + e + f + g;
	int max1 = max(a, max(b, max(c, max(d, e))));
	int maxx = max(max1, max(f, g));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h8(int a, int b, int c, int d, int e, int f, int g, int h) {
	int sum = a + b + c + d + e + f + g + h;
	int max1 = max(a, max(b, max(c, max(d, e))));
	int maxx = max(max1, max(f, max(g, h)));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h9(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
	int sum = a + b + c + d + e + f + g + h + i;
	int max1 = max(a, max(b, max(c, max(d, e))));
	int maxx = max(max1, max(f, max(g, max(h, i))));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int h10(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j) {
	int sum = a + b + c + d + e + f + g + h + i + j;
	int max1 = max(a, max(b, max(c, max(d, e))));
	int maxx = max(max1, max(f, max(g, max(h, max(i, j)))));
	if (sum > 2 * maxx)
		return 1;
	else
		return 0;
}

int main() {
//	freopen("xor.in", "r", stdin);
//	freopen("xor.out", "w", stdout);
	int n;
	cin >> n;
	int a[n + 2];
	int sum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 3; i <= n; i++) {
		if (h3(a[1], a[2], a[i]))
			sum += 1;
	}
	for (int i = 4; i <= n; i++) {
		if (h3(a[1], a[3], a[i]))
			sum += 1;
	}
	for (int i = 5; i <= n; i++) {
		if (h3(a[1], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h3(a[1], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h3(a[1], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h3(a[1], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[1], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[1], a[9], a[i]))
			sum += 1;

	}
	for (int i = 4; i <= n; i++) {
		if (h3(a[2], a[3], a[i]))
			sum += 1;
	}
	for (int i = 5; i <= n; i++) {
		if (h3(a[2], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h3(a[2], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h3(a[2], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h3(a[2], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[2], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[2], a[9], a[i]))
			sum += 1;
	}

	for (int i = 5; i <= n; i++) {
		if (h3(a[3], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h3(a[3], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h3(a[3], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h3(a[3], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[3], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[3], a[9], a[i]))
			sum += 1;
	}

	for (int i = 6; i <= n; i++) {
		if (h3(a[4], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h3(a[4], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h3(a[4], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[4], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[4], a[9], a[i]))
			sum += 1;
	}

	for (int i = 7; i <= n; i++) {
		if (h3(a[5], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h3(a[5], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[5], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[5], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h3(a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h3(a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h3(a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h3(a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h3(a[8], a[9], a[i]))
			sum += 1;
	}


	for (int i = 4; i <= n; i++) {
		if (h4(a[1], a[2], a[3], a[i]))
			sum += 1;
	}
	for (int i = 5; i <= n; i++) {
		if (h4(a[1], a[2], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h4(a[1], a[2], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[1], a[2], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[1], a[2], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[2], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[2], a[9], a[i]))
			sum += 1;
	}

	for (int i = 5; i <= n; i++) {
		if (h4(a[1], a[3], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h4(a[1], a[3], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[1], a[3], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[1], a[3], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[3], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[3], a[9], a[i]))
			sum += 1;
	}

	for (int i = 6; i <= n; i++) {
		if (h4(a[1], a[4], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[1], a[4], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[1], a[4], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[4], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[4], a[9], a[i]))
			sum += 1;
	}

	for (int i = 7; i <= n; i++) {
		if (h4(a[1], a[5], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[1], a[5], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[5], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[5], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h4(a[1], a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[1], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h4(a[1], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 5; i <= n; i++) {
		if (h4(a[2], a[3], a[4], a[i]))
			sum += 1;
	}
	for (int i = 6; i <= n; i++) {
		if (h4(a[2], a[3], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[2], a[3], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[2], a[3], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[2], a[3], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[3], a[9], a[i]))
			sum += 1;
	}

	for (int i = 6; i <= n; i++) {
		if (h4(a[2], a[4], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[2], a[4], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[2], a[4], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[2], a[4], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[4], a[9], a[i]))
			sum += 1;
	}

	for (int i = 7; i <= n; i++) {
		if (h4(a[2], a[5], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[2], a[5], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[2], a[5], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[5], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h4(a[2], a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[2], a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[2], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h4(a[2], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 6; i <= n; i++) {
		if (h4(a[3], a[4], a[5], a[i]))
			sum += 1;
	}
	for (int i = 7; i <= n; i++) {
		if (h4(a[3], a[4], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[3], a[4], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[3], a[4], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[3], a[4], a[9], a[i]))
			sum += 1;
	}

	for (int i = 7; i <= n; i++) {
		if (h4(a[3], a[5], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[3], a[5], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[3], a[5], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[3], a[5], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h4(a[3], a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[3], a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[3], a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[3], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[3], a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h4(a[3], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 7; i <= n; i++) {
		if (h4(a[4], a[5], a[6], a[i]))
			sum += 1;
	}
	for (int i = 8; i <= n; i++) {
		if (h4(a[4], a[5], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[4], a[5], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[4], a[5], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h4(a[4], a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[4], a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[4], a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[4], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[4], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 8; i <= n; i++) {
		if (h4(a[5], a[6], a[7], a[i]))
			sum += 1;
	}
	for (int i = 9; i <= n; i++) {
		if (h4(a[5], a[6], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[5], a[6], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[5], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[5], a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 9; i <= n; i++) {
		if (h4(a[6], a[7], a[8], a[i]))
			sum += 1;
	}
	for (int i = 10; i <= n; i++) {
		if (h4(a[6], a[7], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h4(a[6], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 10; i <= n; i++) {
		if (h4(a[7], a[8], a[9], a[i]))
			sum += 1;
	}

	for (int i = 5; i <= n; i++) {
		if (h5(a[1], a[2], a[3], a[4], a[i]))
			sum += 1;
	}

	cout << sum;
	return 0;
}
