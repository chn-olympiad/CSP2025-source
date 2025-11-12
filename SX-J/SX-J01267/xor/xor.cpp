#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n = 0, k = 0, num[n], ans = 0;
	cin >> n >> k ;
	cin >> num[n] ;
	for (int i = 0; i <= n; i++) {
		if (n >= k)
			ans++;
		else
			ans += i;
	}
	cout << ans << endl;
	return 0;
}
