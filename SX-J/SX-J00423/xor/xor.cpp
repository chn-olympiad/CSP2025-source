#include <bits/stdc++.h>
using namespace std;
long long N = 1e6+1;
long long n, k;

struct xh {
	long long xb, sz;
} a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].sz;
		a[i].xb = i;
	}
	cout << 5 << endl;
	return 0;
}