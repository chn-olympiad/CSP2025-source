#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long b = 1;
	long long sum = 0;
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		if (b > n) {
			break;
		}
		int t = a[b];
		if (t == k) {
			b++;
			sum++;
			continue;
		}
		while (t != k) {
			if (b > n) {
				flag = false;
				break;
			}
			t ^= a[b + 1];
			b++;
		}
		if (flag == true) {
			sum++;
		}
	}
	cout << sum;
	return 0;
}
