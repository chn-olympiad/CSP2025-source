#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 100 + 10;
ll n, m, a[N];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++)
		cin >> a[i];

	cout << n << " " << m;
	return 0;
}
