#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n;
int a[N][4];
long long ans;

void dfs(int u, int ca, int cb, int cc, long long sum) {
	if (u > n) {
		ans = max(ans, sum);
		return ;
	}
	if (ca < n / 2) {
		dfs(u + 1, ca + 1, cb, cc, sum + a[u][1]);
	}
	if (cb < n / 2) {
		dfs(u + 1, ca, cb + 1, cc, sum + a[u][2]);
	}
	if (cc < n / 2) {
		dfs(u + 1, ca, cb, cc + 1, sum + a[u][3]);
	}
}

int wk(int x) {
	if (x == 1) return 2;
	return 1;
}

void Solve()
{
	bool f1 = 1, f = 1;
	cin >> n;
	for (int i = 1; i <= n; i++ ) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][3] != 0) f = 0;
		if (a[i][2] != 0 || a[i][3] != 0) f1 = 0;
	}
	if (f1) {
		ans = 0;
		vector<int> ve;
		for (int i = 1; i <= n;i ++ ) {
			ve.push_back(a[i][1]);
		}
		sort(ve.begin(), ve.end());
		long long res = 0;
		for (int i = n; i > n / 2; i -- ) {
			res += ve[i - 1];
		}
		cout << res << "\n";
		return ;
	}
	if (n <= 30) {
		ans = 0;
		dfs(1, 0, 0, 0, 0ll);
		cout << ans << endl;
		return ;
	}
		ans = 0;
		int cnt[4] = {0, 0,0,n};
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq[3];
		map<int, int> mp;
		for (int i = 1; i <= n; i ++ ) {
			vector<pair<int, int>> ve;
			for (int j = 1; j <= 3; j ++ ) {
				ve.push_back({ a[i][j], j });
			}
			sort(ve.begin(), ve.end());
			int tar1 = 0, tar2 = 0;
			int pos = -1;
			for (int j = 2; j >= 0; j -- ) {
				if (cnt[ve[j].second] < n / 2) {
					tar1 = ve[j].first;
					tar2 = ve[j].second;
					pos = j;
					break;
				}
			}
	//		cout << tar1 << "@\n";
			if (pos != 2) {
				bool flag = 0;
				for (int j = 2; j > pos; j -- ) {
					int fi = pq[ve[j].second].top().first, se = pq[ve[j].second].top().second;
					int tp1 = ve[j].first;
					int	tp2 = ve[j].second;
					if (fi < tp1 - tar1) {
						mp[se] = wk(ve[j].second);
						pq[ve[j].second].pop();
						pq[wk(ve[j].second)].push({ -fi, se }); 
						pq[ve[j].second].push({ ve[i].first - tar1, i });
						mp[i] = ve[j].second;
						flag = 1;break;
					}
				}
				if (flag) continue;
			}
			int d = 0;
			if (tar1 == ve[2].first) d = ve[2].first - ve[1].first;
			else d = -ve[2].first + ve[1].first;
	//		cout << d << "#" << tar2 << endl;
			pq[tar2].push({ d, i });
			mp[i] = tar2;
			cnt[tar2] ++ ;
	//		ans += tar1;
		}
		for (int i = 1; i <= n; i ++ ) {
	//		cout << mp[i] << " " << endl;
			ans += a[i][mp[i]];
		}
		cout << ans << endl;
	return ;	
} 

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	int _ = 1; cin >> _;
	while (_ -- ) {
		Solve();
	}
	return 0;
}
// die in the last OIcontest...
