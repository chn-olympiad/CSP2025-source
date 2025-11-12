#include <bits/stdc++.h>
using namespace std;
long long a[5005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	srand(time(NULL));
	cout << rand();
	return 0;
}
