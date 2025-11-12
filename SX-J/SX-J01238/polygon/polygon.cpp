#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
long long n, m, a[150000];
bool flag;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			flag = 1;
		}
	}
	if (n == 3) {
		long long sum = 0, mymax = -1;
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			mymax = max(mymax, a[i]);
		}
		if (mymax * 2 < sum) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else if (flag == 0) {
		long long sum = (1 + (n - 1) * (n - 2)) % N;
		cout << sum;
	} else {
		cout << 0;
	}

	return 0;
}
