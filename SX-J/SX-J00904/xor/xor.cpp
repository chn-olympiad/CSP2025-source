#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int k, a[500000];
	long long n;
	cin >> n >> k;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
	}
	int e = 0, h = 0;
	for (int i = 0; i < n; i++) {
		e = e ^a[i];
		if (e == k) {
			++h;
			e = 0;
		}
	}
	cout << h;
	return 0;
}
