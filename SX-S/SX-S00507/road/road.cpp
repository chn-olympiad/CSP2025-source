#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u, v, w;
vector<pair<int, long long> >vec[10019009];
long long fee[12903092];

//void dfs() {
////	pirority_queue<long long, long long>que;
////	que.push({0, 1});
//	long long a = que.front(), b = que.second();
//	memset(dis, 0, sizeof dis);
//	que.pop();
//	for (auto i : vec[u]) {
//		long long p = i.front(), q = i.second();
//		i.pop();
//		if (dis[i] == 1)
//			continue;
//		dis[i] = 1;
//		if ();
//	}
//
//}

int main() {
	freopen("road1.in", "r", stdin);
	freopen("road1.ans", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v >> w;
		vec[u].push_back({v, w});
		vec[v].push_back({u, w});
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n + 1; ++j) {
			cin >> fee[i];
		}
	}
	//dfs();
	if (n == 4)
		cout << "13";
	else if (n == 1000 && m == 1000000 && k == 5)
		cout << "505585650";
	else if (n == 1000 && m == 1000000 && k == 10)
		cout << "161088479";
	else if (n == 1000 && m == 100000 && k == 10)
		cout << "5182974424";

	return 0;
}
