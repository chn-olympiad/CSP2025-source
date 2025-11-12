#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[500005][5], cnt[3];
struct node{
	ll dmx, dmn, dmxi, dmni;
}d[500005];

bool cmp(node d1, node d2) {
	if (d1.dmx == d2.dmx) return d1.dmn > d2.dmn;
	return d1.dmx > d2.dmx;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll sum = 0;
		cnt[0] = n;
		for (ll i = 1; i <= 2; i++) cnt[i] = 0;
		for (ll i = 1; i <= n; i++) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			d[i].dmx = max(a[i][1], a[i][2]) - a[i][0];
			d[i].dmn = min(a[i][1], a[i][2]) - a[i][0];
			if (a[i][1] > a[i][2]) d[i].dmxi = 1, d[i].dmni = 2;
			else d[i].dmxi = 2, d[i].dmni = 1;
			sum += a[i][0];
		}
		
		sort(d+1, d+n+1, cmp);
		
		for (ll i = 1; i <= n; i++) {
			if (d[i].dmx < 0) {
				if (cnt[0] <= n/2) break;
				else {
					sum += d[i].dmx;
					cnt[d[i].dmxi]++;
					cnt[0]--;
				}
			}
			else {
				if (cnt[d[i].dmxi] == n/2) {
					if (d[i].dmn > 0) {
						sum += d[i].dmn;
						cnt[d[i].dmni]++;
						cnt[0]--;
					}
				}
				else {
					sum += d[i].dmx;
					cnt[d[i].dmxi]++;
					cnt[0]--;
				}
			}
		}
		cout << sum << endl;
	}
}