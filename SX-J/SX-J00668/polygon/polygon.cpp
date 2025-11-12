#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5005], ans, n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == 3) {
		cin >> a[1] >> a[2] >> a[3];
		ll x = max(a[1], a[2]);
		ll y = max(x, a[3]);
		ll k = a[1] + a[2] + a[3];
		if (k > y * 2) {
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
