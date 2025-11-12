#include <bits/stdc++.h>
using namespace std;
const int N = 3e7-4e6+7;
long long ns;
long long a[5007], v[N];
long long ans;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> ns;
	for (int i = 1; i <= ns; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + ns + 1);
	if (ns == 3) {
		if (a[1] + a[2] > a[3]) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	return 0;
}