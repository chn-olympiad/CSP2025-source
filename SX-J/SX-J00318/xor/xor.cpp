#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, k;
int a[N];
int n1, n0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			n1++;
		}
		if (a[i] == 0) {
			n0++;
		}
	}
	if (n1 == n) {
		cout << n / 2;
		return 0;
	}
	if (n1 + n0 == n) {
		int co = 0, cnt = 0;
		if (k == 0) {
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) {
					co++;
				} else {
					cnt += co / 2;
					co = 0;
				}
			}
			cout << n0 + cnt;
			return 0;
		} else {
			cout << n1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
