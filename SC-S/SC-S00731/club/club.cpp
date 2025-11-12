#include <bits/stdc++.h>
#define int long long
using namespace std;

int t = 1;

const int N = 1e5 + 10;
int n, A_0, A_1, A_2, chs[N], chg[N];
int H[3], ans, MX, I;
set <pair <int, pair <int, int> > > S;

void solve() {
	ans = 0, H[0] = H[1] = H[2] = 0;
	MX = 0, I = -1;
	S.clear();
	
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		chg[i] = 0;
		cin >> A_0 >> A_1 >> A_2;
		
		int mx = max({A_0, A_1, A_2});
		if(A_0 == mx) {
			chs[i] = 0, H[0] ++;
			if(MX < H[0]) MX = H[0], I = 0;
			S.insert({A_0 - A_1, {i, 1}});
			S.insert({A_0 - A_2, {i, 2}});
		} else if(A_1 == mx) {
			chs[i] = 1, H[1] ++;
			if(MX < H[1]) MX = H[1], I = 1;
			S.insert({A_1 - A_0, {i, 0}});
			S.insert({A_1 - A_2, {i, 2}});
		} else if(A_2 == mx) {
			chs[i] = 2, H[2] ++;
			if(MX < H[2]) MX = H[2], I = 2;
			S.insert({A_2 - A_0, {i, 0}});
			S.insert({A_2 - A_1, {i, 1}});
		}
		
		ans += mx;
	}
	
	if(MX <= (n >> 1)) {cout << ans << "\n"; return;}
	
	while(S.size()) {
		auto i = S.begin(); S.erase(i);
		int num = (*i).first, J = (*i).second.first, K = (*i).second.second;
		if(1 == chg[J]) continue;
		if(I != chs[J]) continue;
		if(H[K] + 1 > (n >> 1)) continue;
		
		ans -= num, MX --, H[K] ++;
		chg[J] = 1;
		
		if(MX <= (n >> 1)) break;
	}
	cout << ans << "\n";
}

signed main() {
//	freopen("club5.in", "r", stdin);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}
