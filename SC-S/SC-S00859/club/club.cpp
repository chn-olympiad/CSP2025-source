#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;
int n;
struct node {
	int num, id;
}a[N][5];
bool cmp(node x, node y) {
	return x.num > y.num;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1].num  >> a[i][2].num >> a[i][3].num;
			a[i][1].id = 1;
			a[i][2].id = 2;
			a[i][3].id = 3;
			sort(a[i] + 1, a[i] + 4, cmp);
		}
		int c[5] = {0}, sum = 0;
		for (int i = 1; i <= n; i++) {
			c[a[i][1].id]++;
			sum += a[i][1].num;
		}
		int dd = 0;
		if (c[1] > n / 2) {
			dd = 1;
		} else if (c[2] > n / 2) {
			dd = 2;
		} else if (c[3] > n / 2) {
			dd = 3;
		}
		if (dd != 0) {
			int jd = c[dd] - n / 2;
			priority_queue<int, vector<int> > ck;
			for (int i = 1; i <= n; i++) {
				if (a[i][1].id != dd) {
					continue;
				}
				if (ck.size() < jd) {
					ck.push(a[i][1].num - a[i][2].num);
				} else {
					if (a[i][1].num - a[i][2].num < ck.top()) {
						ck.pop();
						ck.push(a[i][1].num - a[i][2].num);
					}
				}
			}
			int ans = 0;
			while(ck.size()) {
				ans += ck.top();
				ck.pop();
			}
			sum -= ans;
		}
		cout << sum << "\n";
	}
	return 0;
}













