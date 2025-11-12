#include <bits/stdc++.h>
using namespace std;
int  a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			int t = a[i];
			for (int z = i + 1; z <= j; z++) {
				t = t ^a[z];
			}
			if (t == k) {
				i = j + 1;
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}
