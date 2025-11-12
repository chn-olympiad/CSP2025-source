#include <bits/stdc++.h>
using namespace std;

int h[10000010];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, sum = 0;
	long long a = 3;
	cin >> n;
	for (long long i = 3; i < n; i++) {

		sum += a;
		a += 3;
	}
	cout << sum + 1;
}
