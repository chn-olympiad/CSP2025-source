#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int a[N][4];
vector<pair<int, int> > b[4];
bool tf[N];
int st[N], ct[4];
int res;
void dfs(int u) {
	if (u > n) {
		int sum = 0;
//		cout << endl;
		for (int i = 1; i <= n; i ++) {
			sum += a[i][st[i]];
//			cout << st[i] << ' ';
		}
//		cout << endl;
//		cout << sum << ' ' << res << endl;
		res = max(res, sum);
		return ;
	}
	if (ct[1] < n / 2) {
		st[u] = 1;
		ct[1] ++;
		dfs(u + 1);
		ct[1] --;
	}
	if (ct[2] < n / 2) {
		st[u] = 2;
		ct[2] ++;
		dfs(u + 1);
		ct[2] --;
	}
	if (ct[3] < n / 2) {
		st[u] = 3;
		ct[3] ++;
		dfs(u + 1);
		ct[3] --;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T --) {
		cin >> n;
		if (n <= 10) {
			memset(st, 0, sizeof st);
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= 3; j ++) {
					cin >> a[i][j];
				}
			}
			res = 0;
			dfs(1);
			cout << res << '\n';
			continue;
		}
		res = 0;
		int num = n / 2;
		for (int j = 1; j <= 3; j ++) b[j].clear();
		bool jd = true;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= 3; j ++) {
				cin >> a[i][j];
				b[j].push_back({a[i][j], i});
				if (j > 1 && a[i][j] != 0) jd = false;
			}
		}
		if (jd) {
			vector<int> vec;
			for (int i = 1; i <= n; i ++) {
				vec.push_back(a[i][1]);
			}
			sort(vec.begin(), vec.end(), greater<int>());
			int tot = 0;
			for (int i = 0; i < num; i ++) {
				tot += vec[i];
			}
			cout << tot << '\n';
			continue;
		}
//		cout << 111 << endl;
		for (int i = 1; i <= 3; i ++) {
			sort(b[i].begin(), b[i].end());
			b[i].push_back({0, 0});
			reverse(b[i].begin(), b[i].end());
		}
//		for (int i = 1; i <= 3; i ++) {
//			for (int j = 1; j <= n; j ++) {
//				cout << b[i][j].first << "," << b[i][j].second << ";";
//			}
//			cout << '\n';
//		}
//		cout << 222 << endl;
		for (int i = 1; i <= n / 2; i ++) {
			for (int j = 1; j <= n / 2; j ++) {
//				int i = 2, j = 1;
				int k = n - i - j;
				if (k > n / 2) continue;
//				cout << i << " " << j << " " << k << '\n';
				vector<int> tp;
				tp.push_back(1);
				tp.push_back(2);
				tp.push_back(3);
//				do {
					memset(tf, 0, sizeof tf);
//					cout << 333 << endl;
					int sum = 0;
					for (int p = 1, c = 1; p <= n && c <= i; p ++, c ++) {
						while (tf[b[tp[0]][p].second]) {
							p ++;
						}
						tf[b[tp[0]][p].second] = true;
						sum += b[tp[0]][p].first;
//						cout << sum << '\n';
					}
	//				cout << 444 << endl;
					for (int p = 1, c = 1; p <= n && c <= j; p ++, c ++) {
						while (tf[b[tp[1]][p].second]) {
							p ++;
						}
						tf[b[tp[1]][p].second] = true;
						sum += b[tp[1]][p].first;
//						cout << sum << '\n';
					}
	//				cout << 555 << endl;
					for (int p = 1, c = 1; p <= n && c <= j; p ++, c ++) {
						while (tf[b[tp[2]][p].second]) {
							p ++;
						}
						tf[b[tp[2]][p].second] = true;
						sum += b[tp[2]][p].first;
//						cout << sum << '\n';
					}
	//				cout << 666 << endl;
					res = max(res, sum);
//					cout << res << " " << sum << '\n';
//				}
//				while (next_permutation(tp.begin(), tp.end()));
			}
		}
		cout << res << '\n';
	}
	return 0;
}

