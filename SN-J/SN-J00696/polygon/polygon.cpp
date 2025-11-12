#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long n, m[10000], sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int w = 1; w <= n; w++) {
				long long ans = m[i] + m[j] + m[w], mm = max(m[i], m[j]);
				long long mmm = max(mm, m[w]);
				if (ans > (2 * mmm)) {
					sum++;
					sum %= 998244353;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
