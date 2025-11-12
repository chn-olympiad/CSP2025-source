#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, k;
int a[N];
int ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i ; j <= n; j++) {
			int tmp = a[i];
			for (int c = i + 1; c <= j; c++) {
				tmp ^= a[c];
			}
			if (tmp == k) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
