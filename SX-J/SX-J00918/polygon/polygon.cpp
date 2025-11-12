#include <iostream>
#include <cstdio>
using namespace std;
int a[5001];

int jc(int n, int m) {
	int e = 0;
	for (int i = n; i <= m; i++) {
		e += a[i];
	}
	return e;
}

int bj(int m, int n) {
	int e = 0;
	for (int i = m; i <= n; i++) {
		if (a[i] > e)
			e = a[i];
	}
	return e;
}

//#Shang4Shan3Ruo6Shui4
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, o = 0;
	cin >> n;
//	int a[5001] = {0};
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			for (int k = i; k < j; k++) {
				if (jc(i, k) >= bj(i, j)) {
					o++;

				}
			}
		}

	}
	cout << o % 998244353 + 1;
	return 0;
}
