#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 1e4 + 9;

int n, m, k;

int num[N];

long long ans = 0;

std::vector<std::tuple<int, int, int>> e;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, u, v, w; i <= n; i++) {
		scanf("%d%d%d", &u, &v, &w);
		e.emplace_back(u, v, w);
		num[u]++, num[v]++, ans += w;
	}
	
	std::sort(e.begin(), e.end(), [](const std::tuple<int, int, int>& x, const std::tuple<int, int, int>& y) {
		return std::get<2>(x) > std::get<2>(y);
	});
	
	for (int i = 0; i < m; i++) {
		if (num[std::get<0>(e[i])] > 1 && num[std::get<1>(e[i])] > 1) {
			num[std::get<0>(e[i])] --;
			num[std::get<1>(e[i])] --;
			ans -= std::get<2>(e[i]);
		}
	}
		
	printf("%lld", ans);
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}