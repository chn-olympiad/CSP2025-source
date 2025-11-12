#include <bits/stdc++.h>
using namespace std;
int a[500005], ans = 0;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k) {
			ans++;
		}
	}
	cout << ans ;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
