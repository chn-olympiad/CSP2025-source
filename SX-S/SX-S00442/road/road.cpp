#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


struct road {
	int u, v, w;
};

struct web {
	vector<vector<int>> w;
	int pointnum, weight;
	web(int point) {
		pointnum = point;
		for (int i = 0; i < pointnum; i++) {
			w.push_back({i});
		}
	}
	int find(int point) {
		for (int i = 0; i < (int)w.size(); i++) {
			for (int j = 0; j < (int)w[i].size(); j++) {
				if (w[i][j] == point) {
					return i;
				}
			}
		}
		return -1;
	}
	int stick(road r) {
		int pu = find(r.u), pv = find(r.v);
		if (pu == pv) {
			return 0;
		}
		int t = max(pu, pv);
		pv = min(pu, pv);
		pu = t;
		vector<int> tmp = w[pv];
		w.erase(w.begin() + pv);
		for (int i = 0; i < (int)tmp.size(); i++) {
			w[pu].push_back(tmp[i]);
		}
		weight += r.w;
		return w.size() == 1;
	}
};

inline int cmp1(road r1, road r2) {
	return r1.w < r2.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
	vector<road> roads(500001);

	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &roads[i].u, &roads[i].v, &roads[i].w);
		roads[i].u--;
		roads[i].v--;
	}
	sort(roads.begin(), roads.begin() + m, cmp1);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			int tmp;
			scanf("%d", &tmp);
		}
	}

	web w(n);
	for (int i = 0; i < m; i++) {
		if (w.stick(roads[i])) {
			printf("%d\n", w.weight);
			break;
		}
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
