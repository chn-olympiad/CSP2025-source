#include <bits/stdc++.h>
using namespace std;
int t, n, jf, r;
int sum;
int a[3], b[3];

int asl(int t, int n) {
	sum = 0;

	for (int i = 1; i <= 3; i++) {

		for (int j = 1; j <= n; j++) {

			b[i] = 1;
			cin >> a[i];
			jf = a[1];
		}

		for (int k = 2; k <= 2; k++) {

			if (a[k + 1] > jf && r <= n / 2 && b[k + 1] == 1) {
				jf = a[k + 1];
			}
		}

		sum += jf;
	}

	for (int i = 1; i <= t; i++) {

		return sum;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	cin >> t >> n;

	for (int i = 1; i <= n; i++) {

		cout << asl(t, n);
	}

	return 0;
}