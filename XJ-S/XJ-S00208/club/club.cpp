#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 1e5 + 5;
ll T, n;
ll cnt, cnt1, cnt2, cnt3, ans;
int c1[MAXN], c2[MAXN], c3[MAXN], c[MAXN];
void memit(){
	cnt = cnt1 = cnt2 = cnt3 = ans = 0;
	memset(c1, 0, sizeof(c1));
	memset(c2, 0, sizeof(c2));
	memset(c3, 0, sizeof(c3));
	memset(c, 0, sizeof(c));
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--){
		memit();
		cin >> n;
		for (ll i = 1; i <= n; i++){
			ll x, y, z;
			cin >> x >> y >> z;
			if (max(max(x, y), z) == x)	c1[++cnt1] = x - max(y, z);
			if (max(max(x, y), z) == y)	c2[++cnt2] = y - max(x, z);
			if (max(max(x, y), z) == z)	c3[++cnt3] = z - max(x, y);
			ans += max(max(x, y), z);
		}
		if (cnt1 > (n / 2))	for (int i = 1; i <= cnt1; i++) c[i] = c1[i];
		if (cnt2 > (n / 2))	for (int i = 1; i <= cnt2; i++) c[i] = c2[i];
		if (cnt3 > (n / 2))	for (int i = 1; i <= cnt3; i++) c[i] = c3[i];
		if (max(max(cnt1, cnt2), cnt3) <= n / 2){
			cout << ans << endl;
			continue;
	    }
	    cnt = max(max(cnt1, cnt2), cnt3);
	    sort(c + 1, c + cnt + 1);
	    for (int i = 1; i <= cnt - n / 2; i++){
	    	ans -= c[i];
		}
		cout << ans << endl;
	}
	return 0;
}
