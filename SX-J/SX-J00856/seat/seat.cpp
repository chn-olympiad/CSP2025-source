#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, s;



bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);

	cin >> n >> m;
	for (ll i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	sort(s + 1, s + n *m + 1, cmp);
	for (ll i = 1; i <= n; i++) {

	}


	return 0;

}