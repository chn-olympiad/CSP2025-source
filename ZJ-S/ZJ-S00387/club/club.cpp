#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct Node {
	int v[3];
	int max;
	int diff;
};

bool cmp(Node x, Node y) {
	return x.diff < y.diff;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t = 0;
	std::cin >> t;
	
	while (t--) {
		int n = 0;
		std::vector<Node> vct;
		std::cin >> n;
		vct.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			std::cin >> vct[i].v[0] >> vct[i].v[1] >> vct[i].v[2];
			int max = 0;
			if (vct[i].v[1] > vct[i].v[max]) {
				max = 1;
			}
			if (vct[i].v[2] > vct[i].v[max]) {
				max = 2;
			}
			
			vct[i].diff = std::numeric_limits<int>::max();
			for (int j = 0; j < 3; ++j) {
				if (j == max) {
					continue;
				}
				vct[i].diff = std::min(vct[i].diff, vct[i].v[max] - vct[i].v[j]);
			}
			vct[i].max = max;
		}
		
		long long ans = 0;
		std::vector<Node> in[3];
		for (int i = 1; i <= n; ++i) {
			in[vct[i].max].push_back(vct[i]);
			ans += vct[i].v[vct[i].max];
		}
		int imax = -1;
		for (int i = 0; i < 3; ++i) {
			if (in[i].size() > n / 2) {
				imax = i;
				break;
			}
		}
		
		if (~imax) {
			std::sort(in[imax].begin(), in[imax].end(), cmp);
			for (int i = 0; i < in[imax].size() - n / 2; ++i) {
				ans -= in[imax][i].diff;
			}
		}
		
		std::cout << ans << "\n";
	}
	
	return 0;
}
