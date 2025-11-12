#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 100;
int T, n, a[N][3];
struct segyid {
	int x, y;
} ;

bool cmp2(segyid x, segyid y) {return x.y > y.y;}
signed main() {
//	system("fc club.out club4.ans");
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	while(T --) {
		cin >> n;
		vector<segyid> q[3];
		int ans = 0;
		for(int i = 1; i <= n; i ++) {
			int x, y, z;
			cin >> x >> y >> z;
			if(x >= y && x >= z) q[0].push_back({x, min(x - y, x - z)});
			else if(y >= x && y >= z) q[1].push_back({y, min(y - x, y - z)});
			else if(z >= y && z >= x) q[2].push_back({z, min(z - y, z - x)});
		}
		for(int j = 0; j <= 2; j ++) {
			for(auto v : q[j]) ans += v.x;
			if(q[j].size() > n / 2) {//cout << ans << "\n";
//				sort(q[j].begin(), q[j].end(), cmp1);
				
				sort(q[j].begin(), q[j].end(), cmp2);
				q[j].erase(q[j].begin(), q[j].begin() + n / 2);
				for(auto v : q[j]) ans -= v.y;//, cout << v.y << "\n";
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
