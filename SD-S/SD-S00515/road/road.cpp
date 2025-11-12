#include <algorithm>
#include <cstdint>
#include <fstream>
#include <numeric>
#include <tuple>
#include <vector>

struct Min_set{
	unsigned* parent;
	unsigned find_root(unsigned node) {
		if(parent[node] == node)
			return node;
		return parent[node] = find_root(parent[node]);
	}
	void merge(unsigned x, unsigned y) {
		unsigned root1 = find_root(x), root2 = find_root(y);
		if(root1 != root2)
			parent[root1] = root2;
	}
	Min_set(unsigned size)
		:parent(new unsigned[size])
	{ std::iota(parent, parent + size, 0); }
	~Min_set() { delete[] parent; }
};

bool cmp(const std::tuple<int, int, int64_t>& a, const std::tuple<int, int, int64_t>& b) {
	return std::get<2>(a) < std::get<2>(b);	
}

int main() {
	using namespace std;
	ifstream cin("road.in");
	ofstream cout("road.out");
	int n, m, k;
	cin >> n >> m >> k;
	vector<tuple<int, int, int64_t>> edge;
	while(m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge.emplace_back(u, v, w);
	}
	sort(edge.begin(), edge.end(), cmp);
	auto cost = new int64_t[k];
	vector<vector<int64_t>> table(k, vector<int64_t>(n));
	for(int i = 0; i < k; i++)
	{
		cin >> cost[i]; 
		for(int j = 0; j < n; j++)
			cin >> table[i][j];
	}
	int64_t ans = 0xfffffffffffffff;
	for(unsigned i = (n <= 1000 ? 0 : (1u << k) - 1); i < 1u << k; i++)
	{
		int64_t res = 0;
		int used = 0;
		vector<tuple<int, int, int64_t>> edgen;  
		for(int j = 0; j < k; j++)
			if(i >> j & 1)
			{
				++used;
				res += cost[j];
				for(int l = 0; l < n; l++)
					edgen.emplace_back(n + 1 + j, l + 1, table[j][l]);
			}
		Min_set dsu(n + k + 1);
		sort(edgen.begin(), edgen.end(), cmp);
		int it0 = 0, it1 = 0;
		while(it0 != edge.size() || it1 != edgen.size())
		{
			tuple<int, int, int64_t> now; 
			if(it1 == edgen.size() || it0 != edge.size() && 
				get<2>(edge[it0]) < get<2>(edgen[it1]))
				now = edge[it0++];
			else
				now = edgen[it1++];
			if(dsu.find_root(get<0>(now)) == dsu.find_root(get<1>(now)))
				continue;
			res += get<2>(now); 
			dsu.merge(get<0>(now), get<1>(now)); 
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
	delete[] cost;
	return 0;
}
