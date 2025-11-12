#include <bits/stdc++.h>
using namespace std;
int a[500005];

int main() {
	//freopen("xor.in", "r", stdin);
	//freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	int  cnt = 0, p = a[1];
	for (int i = 1; i <= n; i++) {
		if (p == k) {
			cnt++, p = a[i + 1];
		}
		if (p > k) {
			p = a[i + 1];
		}
		cout << p;
		p ^a[i + 1];
	}
	cout << cnt;
	return 0;
}