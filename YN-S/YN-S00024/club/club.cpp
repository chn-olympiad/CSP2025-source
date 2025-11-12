#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int t, n;
int a[N][4];
vector<int> v[4];

int main (void) {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		int num[] = {0, 0, 0, 0};
		for (int i : {1, 2, 3})
			v[i].clear();
		int mxn = -1, idn;
		for (int i = 1; i <= n; i++) {
			int mx = -1, id = 0;
			for (int j : {1, 2, 3}) {
				cin >> a[i][j];
				if (mx < a[i][j])
					mx = a[i][j], id = j;
			}
			ans += mx, num[id]++;
			v[id].push_back(mx - max({(id != 1) * a[i][1], (id != 2) * a[i][2], (id != 3) * a[i][3]}));
			if (mxn < num[id])
				mxn = num[id], idn = id;
		}
		if (mxn > n / 2) {
			int tmp = 0;
			sort(v[idn].begin(), v[idn].end());
			while (mxn > n / 2)
				ans -= v[idn][tmp++], mxn--;
		}
		cout << ans << '\n';
	}
	return 0;
}

//特殊性质1：直接贪心选前n/2大的
//特殊性质2：结果必为一半1一半2，那么先按最优情况划分，再贪心将人多的分到人少的
//正解：与2类似，划分后将人最多且大于n/2的贪心划分到另外两组，可以随便划分，人数必不大于n/2