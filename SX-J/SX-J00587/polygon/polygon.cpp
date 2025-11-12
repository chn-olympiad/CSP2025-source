#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, cnt = 0;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}