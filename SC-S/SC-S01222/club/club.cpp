#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 100005;
ll ans;
int T, n;
int val[MAXN][4], nodesz[4];
int diff[MAXN], maxind[MAXN];

vector<int> difs;

inline int check() {
	for (int i = 1; i <= 3; ++i)
		if (nodesz[i] > n / 2)
			return i;
	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0;
		difs.clear();
		memset(nodesz, 0, sizeof(nodesz));
		for (int i = 1; i <= n; ++i) {
			cin >> val[i][1] >> val[i][2] >> val[i][3];
			int maxx = max(val[i][1], max(val[i][2], val[i][3]));
			int minn = min(val[i][1], min(val[i][2], val[i][3]));
			int summ = val[i][1] + val[i][2] + val[i][3];
			for (int j = 1; j <= 3; ++j) {
				if (val[i][j] == maxx) {
					maxind[i] = j;
					break;
				}
			}
			diff[i] = maxx - (summ - minn - maxx);
			ans += maxx;
			++nodesz[maxind[i]];
		}
		
		int opt = check();
		if (opt) {
			for (int i = 1; i <= n; ++i) {
				if (maxind[i] == opt)
					difs.push_back(diff[i]);
			}
			sort(difs.begin(), difs.end());
			for (int k = 0; k < nodesz[opt] - n / 2; ++k)
				ans -= difs[k];
		}
		cout << ans << '\n';
	}
	return 0;
}