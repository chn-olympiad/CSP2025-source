#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[5005];
long long cnt;

inline void f(long long s, long long sum, long long l) {
	if (l <= 0) {
		if (sum > a[s] * 2) {
			cnt++;
			cnt = cnt % 998244353;
		}
		return ;
	}
	for (long long i = s + 1; i <= n; i++) {
		f(i, sum + a[i], l - 1);
	}
}

int main() {

	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	for (long long i = 3; i <= n; i++) {
		f(0, 0, i);
	}
	cout << cnt;

	return 0;
}
