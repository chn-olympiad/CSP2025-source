#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int T, n, a1[maxn], a2[maxn], a3[maxn];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while(T--) {
		cin >> n;
		int ans = 0;
		vector <int> p1, p2, p3;
		for(int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			int maxx = max({a1[i], a2[i], a3[i]});
			ans += maxx;
			if(a1[i] == maxx) p1.emplace_back(a1[i] - max(a2[i], a3[i]));
			else if(a2[i] == maxx) p2.emplace_back(a2[i] - max(a1[i], a3[i]));
			else p3.emplace_back(a3[i] - max(a1[i], a2[i]));
		}
		if(p1.size() > n / 2) {
			sort(p1.begin(), p1.end());
			int len = p1.size() - n / 2;
			for(int i = 0; i < len; i++) ans -= p1[i];
		}
		else if(p2.size() > n / 2) {
			sort(p2.begin(), p2.end());
			int len = p2.size() - n / 2;
			for(int i = 0; i < len; i++) ans -= p2[i];
		}
		else if(p3.size() > n / 2) {
			sort(p3.begin(), p3.end());
			int len = p3.size() - n / 2;
			for(int i = 0; i < len; i++) ans -= p3[i];
		}
		cout << ans << "\n";
	}
	return 0;
}