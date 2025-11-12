#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n = 0, num[n], ans = 0;
	cin >> n;
	cin >> num[n];
	for (int i = 0; i <= n; i++) {
		if (n > ans)
			ans++;
		else
			ans += n;
	}
	cout << ans << endl;
	return 0;
}