#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 10;
int n, T;
int a[N][5], bj[N], ans[N], cnt[5], els[N];

void solve() {
	memset(bj, 0, sizeof(bj));
	memset(ans, 0, sizeof(ans));
	memset(cnt, 0, sizeof(cnt));
	memset(els, 0, sizeof(els));
	cin >> n;
	int flag = n / 2, res = 0, man = 0;

	for (int i = 1; i <= n; i++)

		for (int j = 1; j <= 3; j++)

			cin >> a[i][j];

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= 3; j++) {

			if (a[i][j] > ans[i]) {
				ans[i] = a[i][j];
				cnt[bj[i]]--, cnt[j]++;
				bj[i] = j;
			}
		}
	}

	for (int i = 1; i <= n; i++) {

//		cout << ans[i] << " ";
		res += ans[i];
	}

	for (int i = 1; i <= 3; i++) {

//		cout << cnt[i] << "  ";

		if (cnt[i] > flag) {
			man = i;
			break;
		}
	}

	if (!man)
		cout << res;// << " man:" << man;
	else {
		int to = 0;

		for (int i = 1; i <= n; i++) {

			int tmp = 20005;

			if (bj[i] != man)
				continue;

			for (int j = 1; j <= 3; j++) {

				if (j != man) {
					tmp = min(tmp, ans[i] - a[i][j]);
//					ans[i] = a[i][j];
//					cnt[bj[i]]--, cnt[j]++;
//					bj[i] = j;

				}
			}

			els[++to] = tmp;
//			cout << els[i] << " ";
		}

//		for (int i = 1; i <= n; i++)
//
//			cout << bj[i] << " ";
		sort(els + 1, els + 1 + to);

		for (int i = 1; i <= cnt[man] - flag; i++) {

//			cout << els[i] << " ";
			res -= els[i];
		}

		cout << res;
	}

	cout << "\n";
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;

	while (T--)
		solve();



	return 0;
}

//10
//2020 14533 18961    18961
//2423 15344 16322    16322
//1910 6224 16178     16178
//2038 9963 19722     19722
//8375 10557 5444     10557
//3518 14615 17976
//6188 13424 16615
//8769 509 4394
//958 3195 9953
//16441 5313 10926