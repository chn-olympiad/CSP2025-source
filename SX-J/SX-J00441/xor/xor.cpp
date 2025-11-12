#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, p = 0, maxx = LLONG_MIN, f = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (k == 0) {
		for (int i = 2; i <= n; i++) {
			if (a[i] == a[i - 1]) {
				p++;
				f = 1;
			} else {
				if (f)
					p++;
				maxx = max(maxx, p);
				p = 0;
				f = 0;
			}
		}
		if (f)
			p++;
		maxx = max(maxx, p);
		cout << maxx;
	}
	if (k == 1) {
		for (int i = 2; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				p++;
				f = 1;
			} else {
				if (f)
					p++;
				maxx = max(maxx, p);
				p = 0;
				f = 0;
			}
		}
		if (f)
			p++;
		maxx = max(maxx, p);
		cout << maxx;
	}
	return 0;
}
