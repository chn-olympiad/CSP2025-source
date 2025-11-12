#include <bits/stdc++.h>
using namespace std;
int a1[1000000];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 1; i <= a; i++)
		cin >> a1[i];
	int c = 0;
	for (int i = 1; i <= a; i++) {
		c = (c ^a1[i]);
		if (c == b) {
			c = 0;
			ans++;
		}
	}
	cout << ans;

	return 0;
}
