#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;

struct Road {
	int u;
	int v;
	int w;
	bool cityToCity;
};

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	int n, m, k;
//	cin >> n >> m >> k;
	scanf("%d%d%d", &n, &m, &k);

	vector<Road> roads;

	for (int i = 0; i < m; i++) {
		roads.emplace_back();
		Road& road = roads[roads.size() - 1];
//		cin >> road.u >> road.v >> road.w;
		scanf("%d%d%d", &road.u, &road.v, &road.w);
		road.cityToCity = true;
	}

	sort(roads.begin(), roads.end(), [](Road & a, Road & b) {
		return a.w < b.w;
	});

	vector<bool> connected(n + 1, false);
	int connected_size = 0;
	ll cost = 0;
	vector<Road> connected_roads;
	vector<int> city_connects(n + 1, 0);

	for (Road& road : roads) {
		if (!connected[road.u] && !connected[road.v]) {
			connected_size += 2;
			connected[road.u] = true;
			connected[road.v] = true;
			cost += road.w;
			connected_roads.push_back(road);
			city_connects[road.u]++;
			city_connects[road.v]++;
//			cout << "BUILD ROAD BETWEEN " << road.u << " AND " << road.v << " COST " << road.w << endl;
		} else if (!connected[road.u] || !connected[road.v]) {
			connected_size += 1;
			connected[road.u] = true;
			connected[road.v] = true;
			cost += road.w;
			connected_roads.push_back(road);
			city_connects[road.u]++;
			city_connects[road.v]++;
//			cout << "BUILD ROAD BETWEEN " << road.u << " AND " << road.v << " COST " << road.w << endl;
		}
	}

	unordered_map<int, vector<Road>> town_to_city_roads;
	unordered_map<int, int> costs;

	for (int i = 0; i < k; i++) {
		int c;
		cin >> c;
		costs[i + 1] = c;
//		scanf("%d", &c);
		town_to_city_roads[i] = vector<Road>();
		town_to_city_roads[i].push_back({});
		for (int j = 0; j < m; j++) {
//			town_to_city_roads[i].emplace_back();
//			Road& road = town_to_city_roads[i][town_to_city_roads[i].size()-1];
			Road road;
			cin >> road.w;
//			scanf("%d", &road.w);
			road.u = i + 1;
			road.v = j + 1;
			road.cityToCity = false;
			town_to_city_roads[i].push_back(road);
		}
	}

	sort(connected_roads.begin(), connected_roads.end(), [](Road & a, Road & b) {
		return a.w > b.w;
	});

	unordered_map<int, int> city_hased_town;
	unordered_set<Road*> built_roads;
	vector<bool> developed(k + 1, false);

	for (Road& road : connected_roads) {
		int lonely, centerly;
		if (city_connects[road.u] == 1) {
			lonely = road.u;
			centerly = road.v;
		} else if (city_connects[road.v] == 1) {
			lonely = road.v;
			centerly = road.u;
		}
		ll min_new_w = 2e9;
		int chose_town = -1;
		int min_min_i;
		for (int i = 0; i < k; i++) {
			ll new_w = town_to_city_roads[i][lonely].w;
			int other_min = 1e9;
			int min_i;
			for (int j = 1; j <= n; j++) {
				if (j == lonely) {
					continue;
				}
				if (city_hased_town.find(lonely)!=city_hased_town.end()&&city_hased_town.find(j)!=city_hased_town.end()){
					continue;
				}
				other_min = min(other_min, town_to_city_roads[i][j].w);
				if (other_min == town_to_city_roads[i][j].w) {
					min_i = j;
				}
			}
			if (!developed[i + 1]) {
				new_w += costs[i + 1];
			}
			new_w += other_min;
			min_new_w = min(min_new_w, new_w);
			if (new_w == min_new_w) {
				chose_town = i+1;
				min_min_i = min_i;
//				cout <<  "FOUND MIN CONN. T="<<(i+1)<<"A="<<lonely<<",B="<<min_i<<",new_w="<<new_w<<",DEV_C="<<costs[i+1]<<",DEVD="<<developed[i + 1]<<endl;
			}
		}
		if (min_new_w >= road.w) {
			continue;
		}
//		cout << "REPLACE "<<road.w << " TO "<<min_new_w<<endl;
		cost -= road.w;
		cost += min_new_w;
		developed[chose_town] = true;
		city_hased_town[lonely]=chose_town;
		city_hased_town[min_min_i]=chose_town;
	}

	cout << cost << endl;
}
