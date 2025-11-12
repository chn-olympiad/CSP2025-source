#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[110];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ll n, m, num = 0;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	num = a[1];
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (num == a[i]) {
			num = i;
			break;
		}
	}
	ll j;
	if ((num % n) == 0) {
		j = (num / n);
	} else
		j = (num / n) + 1;
	cout << j << " ";
	ll k = (num + n - 1) % n + 1;
	if (j % 2 == 1) {
		cout << k;
	} else {
		cout << n - k + 1;
	}
	return 0;
}