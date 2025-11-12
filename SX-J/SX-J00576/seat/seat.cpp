#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6+10;
const ll M = 1e3+10;
const ll inf = 0x3f3f3f3f3f3f;

ll n, m;
ll arr[N], tot;
ll a;
ll mymap[M][M];
ll now;

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			cin >> arr[++tot];
		}
	}
	a = arr[1];
	sort(arr + 1, arr + tot + 1, cmp);
	//cout << tot << endl;
	for (ll i = 1; i <= m; i += 2) {
		for (ll j = 1 ; j <= n; j++) {
			mymap[j][i] = arr[++now];
//			cout << j << " " << i << endl;
//			cout << arr[now] << endl;
		}
		for (ll j = n; j >= 1; j--) {
			mymap[j][i + 1] = arr[++now];
//			cout << j << " " << i + 1 << endl;
//			cout << arr[now] << endl;
		}
	}
	//cout << a << endl;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			//cout << mymap[i][j] << ' ';
			if (mymap[i][j] == a) {
				cout << j << " " << i;
			}
		}
		//cout << endl;
	}
	return 0;
}
