#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 3e5 + 10;
int T, n, cnt[5];
LL ans;
vector<int> v[4];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		cnt[1] = cnt[2] = cnt[3] = ans = 0;
		for(int i = 1;i <= 3;++ i)v[i].clear();
		for(int i = 1;i <= n;++ i){
			int ma1 = -1, ma2 = -1, p = 0;
			for(int j = 1;j <= 3;++ j){
				int x;
				cin >> x;
				if(x > ma1) p = j, ma2 = ma1, ma1 = x;
				else if(x > ma2) ma2 = x;
			}
			cnt[p]++;
			ans += ma1;
			v[p].push_back(ma1 - ma2);
			//cout << "i: " << i << " " << p << " " << ma1 << " " << ma2 << " " << '\n';
		}
		for(int i = 1;i <= 3;++ i){
			if(v[i].size() <= n / 2) continue;
			sort(v[i].begin(), v[i].end());
			for(int x : v[i]) {
				if(cnt[i] <= n / 2) break;
				cnt[i]--, ans -= x;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}