#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k, w[1000009], sum = 0, r;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		long long ans = w[i];
		for (int j = i; ans != k; j++) {
			ans += w[j];
			r = j;
		}
		i = r;
		sum++;
	}
	cout << sum;
	return 0;
}
