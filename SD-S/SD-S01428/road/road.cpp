#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
constexpr int mxn = 1e4 + 1;
constexpr int mxm = 1e6 + 1;

struct Link {
	int sta, end;
	int wei;
	
	bool operator <(const Link &other) const {
		return wei < other.wei;
	}
};

int fa[mxn];
inline int findfa(const int x) {
	if(fa[x] == x)	return x;
	return fa[x] = findfa(fa[x]);
}

inline void merge(int set1, int set2) {
	set1 = findfa(set1), set2 = findfa(set2);
	if(set1 == set2)
		return;
	fa[set1] = set2;
}

inline bool is_one_set(const int set1, const int set2) {
	return findfa(set1) == findfa(set2);
}

vector<Link> in;
int n, m, k;
vector<pair<int, vector<int>>> bui;

inline long long kur(vector<Link> &to) {
	for(int i = 1; i <= n; i++)
		fa[i] = i; 
	sort(to.begin(), to.end());
	long long ans = 0;
	for(auto &i: to) {
		if(!is_one_set(i.sta, i.end)) {
			merge(i.sta, i.end);
			ans += i.wei;
		}
	}
	return ans;
}

inline void add_link(vector<Link> &in) {
	int su = 0;
	for(int i = 1; i <= n; i++) {
		if(bui[i].first == 0 && su <= k) {
			for(int j = 1; j <= n; j++)
				in.push_back({i, j, bui[i].second[j]});
			su++;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int sta, end, wei;
		cin >> sta >> end >> wei;
		in.push_back({sta, end, wei});
	}
	bui.push_back({});
	for(int i = 1; i <= n; i++) {
		int wei;
		cin >> wei;
		bui.push_back({wei, {0}});
		for(int j = 1; j <= n; j++) {
			cin >> wei;
			bui[i].second.push_back(wei);
		}
	}
//	add_link(in);
	cout << kur(in);
	return 0;
}
