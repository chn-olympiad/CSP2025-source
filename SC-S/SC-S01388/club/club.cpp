#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using pii = std::pair <int, int>;
const int MAXN = 1e5 + 10;

int T, val[5];

std::priority_queue <int, std::vector <int>, std::greater <int> > q[5];

void solve () {
	while (!q[1].empty()) q[1].pop();
	while (!q[2].empty()) q[2].pop();
	while (!q[3].empty()) q[3].pop();
	
	int n, ans = 0; std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> val[1] >> val[2] >> val[3];
		if (val[1] >= val[2] && val[1] >= val[3])
			q[1].push(val[1] - std::max(val[2], val[3]));
		else if (val[2] >= val[1] && val[2] >= val[3])
			q[2].push(val[2] - std::max(val[1], val[3]));
		else q[3].push(val[3] - std::max(val[1], val[2]));
		ans += std::max({val[1], val[2], val[3]});
	}
	
	while (q[1].size() > (n >> 1)) {
		ans -= q[1].top();
		q[1].pop();
	}
	while (q[2].size() > (n >> 1)) {
		ans -= q[2].top();
		q[2].pop();
	}
	while (q[3].size() > (n >> 1)) {
		ans -= q[3].top();
		q[3].pop();
	}
	
	std::cout << ans << '\n';
}

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	std::cin >> T;
	while (T--)
		solve();
	
	
	
	return 0;
}