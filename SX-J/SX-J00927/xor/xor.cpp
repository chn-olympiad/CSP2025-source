#include <bits/stdc++.h>
using namespace std;
long long n, a[500005], s[500005], k, m;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			m++;
	}
	cout << m;
}
