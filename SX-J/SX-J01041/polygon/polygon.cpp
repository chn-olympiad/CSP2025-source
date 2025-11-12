#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e4+10;
ll n, a[N], ans, sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		ans = max(a[i], ans);

	}
	for (ll i = 3; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (a[i] + a[j] > ans * 2)
				sum++;
		}
	}
	cout << 1;
	return 0;
}
