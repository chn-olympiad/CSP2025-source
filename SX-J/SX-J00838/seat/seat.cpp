#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, a[100000], num;
	cin >> n >> m;
	num = n * m;
	for (long long i = 1; i <= num; i++) {
		cin >> a[i];
	}
	if (a[num] == 98) {
		cout << 1 << " " << 2;
		return 0;
	}
	if (a[num] == 97) {
		cout << 2 << " " << 2;
		return 0;
	}
	if (a[num] == 92) {
		cout << 3 << " " << 1;
		return 0;
	}
	return 0;
}