#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int a[N];

int main() {
	long long n, k, s = 0;
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i = i + 2) {
		if (a[i] == k) {
			i--;
			s++;
		} else if ((a[i]^a[i + 1]) == k) {
			s++;
		} else {
			i--;
		}
	}
	cout << s;
	return 0;
}
