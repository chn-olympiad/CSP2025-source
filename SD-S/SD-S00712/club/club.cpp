#include<bits/stdc++.h>
#define rep(_id, _st, _ed) for(int (_id) = (_st); _id <= (_ed); _id++)
#define per(_id, _st, _ed) for(int (_id) = (_st); _id >= (_ed); _id--)
#define db std::cerr
#define dbg(x) std::cerr << (#x) << " : " << (x) << "\n";
#define dbendl std::cerr << "\n";
#define fastread std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
#define file(x) std::freopen(x".in", "r", stdin); std::freopen(x".out", "w", stdout);

typedef long long i64;
typedef unsigned long long u64;

constexpr int maxn = 100005;

int n;
std::pair<int, int> a[maxn][3];

namespace Sol {
	constexpr int inf = 0x3f3f3f3f;
	
	inline void solve() {
		rep (i, 1, n) {
			std::sort(a[i], a[i] + 3);
			std::reverse(a[i], a[i] + 3);
		}
		
		std::array<std::priority_queue<std::pair<int, std::pair<int, int>>>, 3> q;
		
		i64 ans = 0;
		rep (i, 1, n) {
			ans += a[i][0].first; 
			q[a[i][0].second].push({ -a[i][0].first + a[i][1].first, {i, 0} });
			if (q[a[i][0].second].size() > (n >> 1)) {
				std::pair<int, int> t = q[a[i][0].second].top().second;
				ans += q[a[i][0].second].top().first;
				q[a[i][0].second].pop();
				q[t.second + 1].push({-inf, {t.first, t.second + 1} });
			}		
		}

		std::cout << ans << "\n";
	}
}

inline void solve() {
	std::cin >> n;
	rep (i, 1, n) rep (j, 0, 2) {
		std::cin >> a[i][j].first;
		a[i][j].second = j;
	}
	
	Sol::solve();
}

int main() {
	fastread
	
	file("club")

	int _; std::cin >> _;
	while (_--) solve(); 
	
	return 0;
} 

