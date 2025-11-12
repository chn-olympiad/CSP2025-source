#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+5;
ll n, m, a[N], t, mmax = 1e9, h;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t ^= a[i];
		h++;
		if (t == m) {
			t = 0;
			mmax = max(mmax, h);
			h = 0;
		}
	}
	if (m == 0)
		cout << 1;
	else
		cout << mmax;
	return 0;
}