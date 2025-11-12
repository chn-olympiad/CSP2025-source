#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("xor.in", "r", stdin);
	///freopen(".out", "w", stdout);
	int k, q = 0;
	long long n;
	cin >> n >> k;
	int a[100] = {k};
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[0] == a[i]) {
			if (a[0] + a[1] > 1) {
				q = a[0] + a[1];
			} else {
				q = 1;
			}
		}
		cout << q;
	}
}