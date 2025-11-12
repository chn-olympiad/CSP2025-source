#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
long long n, k, s = 0;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (k == 1) {
			if (a[i] == 1) {
				s++;
			}
		} else if (k == 0) {
			if (a[i] == 0) {
				s++;
			}
		}
	}
	cout << s;

	return 0;
}
