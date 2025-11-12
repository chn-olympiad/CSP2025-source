#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int l = 0;
		for (int j = i; j < n; j++) {
			if (l != a[j]) {
				l = 1;
				if (l == k) {
					cnt++;
					break;
				}
			} else {
				l = 0;
				if (l == k) {
					cnt++;
					break;
				}

			}
		}
	}
	cout << cnt;
}
