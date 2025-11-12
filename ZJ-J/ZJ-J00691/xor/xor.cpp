#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
int a[500005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	a[0] = 0;
	FOR(i, 1, n, ++i) {
		cin >> a[i];
		a[i] = (a[i] ^ a[i - 1]);
	}
	int l = 1, r = 1, ans = 0;
	while (r <= n) {
		FOR(i, l, r, ++i) {
			if ( (a[r] ^ a[i - 1]) == k) {
				l = r + 1;
				ans++;
				break;
			}
		}
		r++;
	}
	cout << ans << endl;
	return 0;
}