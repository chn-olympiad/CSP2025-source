#include <bits/stdc++.h>
using namespace std;
int a, b, c[50005], ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= a; i++)
		for (int j = i + 1; j <= a; j++) {
			for (int k = i; k < j; k++) {
				if (c[k] ^ c[k + 1] == b) {
					ans++;
				}
			}
		}
	cout << ans;
	return 0;
}
