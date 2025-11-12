#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, t = 0, tt = 0, ttt = 0;
	long long k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			t++;
		if (a[i] == 0)
			ttt++;
	}
	if (t + ttt == n) {
		if (k == 0) {
			if (t == n) {
				cout << t / 2;
				return 0;
			}
			t = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1 && a[i - 1] == 1) {
					tt++;
					if (tt % 2 == 0)
						t++;
					continue;
				}
				tt = 0;
				if (a[i] == 0)
					t++;
			}
			cout << t;
			return 0;
		}
		if (k == 1) {
			cout << t;
			return 0;
		}
		if (k > 1)
			cout << 0;
	}

	return 0;
}