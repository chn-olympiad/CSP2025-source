#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 10005, M = 1;
ll n, m, arr[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> arr[i];
	ll a = arr[1];
	sort(arr + 1, arr + n *m + 1);
	ll x = lower_bound(arr + 1, arr + n *m + 1, a) - arr;
	x = n * m - x + 1;
	ll c = (x + n - 1) / n;
	if (c % 2 == 1) {
		cout << c << " " << (x - 1) % n + 1;
	} else
		cout << c << " " << n - (x + 1) % n;
	return 0;
}
