#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5+10;
long long n, k, a[N], l, r, mid;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = 1, r = n, mid;
		if (a[i] == mid) {
			break;
		}
		if (a[i] > mid) {
			l++;
		} else {
			r--;
		}
		if (a[i] != -1) {
			cout << r - l;
		}
	}
	return 0;
}
