#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct zhen {
	int chen[10001];
	
} zh[12];



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int> > lian;
	
	int hmc = 0;
	int u, v, w;
	int iso[10004] = {0};
	int minn = 1e9 + 5;
	int mu;
	int mv;
	int minco;
	int uco;
	int vco;
	
	for (int i = 0; i < m; i++) {
		
		cin >> u >> v >> w;
	}
	
	int c, a;
	bool flag = false;
	
	for (int i = 0; i < k; i++) {
		
		cin >> c;
		
		if (c != 0) {
			flag = true;
		}
		
		for (int j = 0; j < n; j++) {
			
			cin >> a;
			
			if (a != 0)
				flag = true;
		}
		
	}
	
	if (!flag)
		cout << 0;
	
	return 0;
}
