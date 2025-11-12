#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long n, k, r = 0, sum = 0, a[maxn], s[maxn];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] ^ a[i];
		for (int j = r; j < i; j++)
			if ((s[i]^s[j]) == k) {
				sum++, r = i;
				break;
			}
	}
	cout << sum;
	return 0;
}
