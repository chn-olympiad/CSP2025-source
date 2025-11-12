#include <bits/stdc++.h>
using namespace std;
#define ll long long
int T, n, a1[100010], a2[100010], a3[100010], ans;
vector<int>jl1, jl2, jl3;

bool cmp1(int x, int y) {
	int ls1 = max(a2[x] - a1[x], a3[x] - a1[x]), ls2 = max(a3[y] - a1[y], a2[y] - a1[y]);
	return ls1 < ls2;
}

bool cmp2(int x, int y) {
	int ls1 = max(a1[x] - a2[x], a3[x] - a2[x]), ls2 = max(a3[y] - a2[y], a1[y] - a2[y]);
	return ls1 < ls2;
}

bool cmp3(int x, int y) {
	int ls1 = max(a2[x] - a3[x], a1[x] - a3[x]), ls2 = max(a1[y] - a3[y], a2[y] - a3[y]);
	return ls1 < ls2;
}
int main(int argv, char **argc) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;

	while (T--) {
		jl1.clear();
		jl2.clear();
		jl3.clear();
		ans = 0;
		cin >> n;
		for (int z = 1; z <= n; z++) {
			cin >> a1[z] >> a2[z] >> a3[z];
			int ls = max(max(a1[z], a2[z]), a3[z]);
			if (ls == a1[z]) {
				jl1.push_back(z);
			} else if (ls == a2[z]) {
				jl2.push_back(z);
			} else if (ls == a3[z]) {
				jl3.push_back(z);
			}
			ans += ls;
		}
		if (jl1.size() > (n >> 1)) {
			int t = jl1.size() - (n >> 1), len = jl1.size();
//			jl1.push_back(0);
			sort(jl1.begin(), jl1.end(), cmp1);
			for (int z = 1; z <= t; z++) {
				ans += max(a2[jl1[len - z]] - a1[jl1[len - z]], a3[jl1[len - z]] - a1[jl1[len - z]]);
			}
		} else if (jl2.size() > (n >> 1)) {
			int t = jl2.size() - (n >> 1), len = jl2.size();
//			jl2.push_back(0);
			sort(jl2.begin(), jl2.end(), cmp2);
			for (int z = 1; z <= t; z++) {
				ans += max(a1[jl2[len - z]] - a2[jl2[len - z]], a3[jl2[len - z]] - a2[jl2[len - z]]);
//				cout << "::::" << max(a1[jl2[len - z]] - a2[jl2[len - z]], a3[jl2[len - z]] - a2[jl2[len - z]]) << '\n';
			}
		} else if (jl3.size() > (n >> 1)) {
			int t = jl3.size() - (n >> 1), len = jl3.size();
//			jl3.push_back(0);
			sort(jl3.begin(), jl3.end(), cmp3);
			for (int z = 1; z <= t; z++) {
				ans += max(a2[jl3[len - z]] - a3[jl3[len - z]], a1[jl3[len - z]] - a3[jl3[len - z]]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
