#include <bits/stdc++.h>
using namespace std;
int T;
int n;
int a1, a2, a3;
int t[5];
int ans;
bool book[100005];

struct node {
	int max_1_sum, max_1_id;
	int max_2_sum, max_2_id;
	int max_3_sum, max_3_id;
} w[100005];

inline bool cmp(node a, node b) {
	if ((a.max_1_sum - a.max_2_sum) == (b.max_1_sum - b.max_2_sum)) {
		if (a.max_1_sum == b.max_1_sum) {
			if (a.max_2_sum == b.max_2_sum) {
				return a.max_3_sum > b.max_3_sum;
			} else {
				return a.max_2_sum > b.max_2_sum;
			}
		} else {
			return a.max_1_sum > b.max_1_sum;
		}
	} else {
		return (a.max_1_sum - a.max_2_sum) > (b.max_1_sum - b.max_2_sum);
	}
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1 >> a2 >> a3;
			w[i].max_1_sum = max(a1, max(a2, a3));
			if (w[i].max_1_sum == a1) {
				w[i].max_1_id = 1;
				w[i].max_2_sum = max(a2, a3);
				if (w[i].max_2_sum == a2) {
					w[i].max_2_id = 2;
					w[i].max_3_sum = a3;
					w[i].max_3_id = 3;
				} else {
					w[i].max_2_id = 3;
					w[i].max_3_sum = a2;
					w[i].max_3_id = 2;
				}
			} else if (w[i].max_1_sum == a2) {
				w[i].max_1_id = 2;
				w[i].max_2_sum = max(a1, a3);
				if (w[i].max_2_sum == a1) {
					w[i].max_2_id = 1;
					w[i].max_3_sum = a3;
					w[i].max_3_id = 3;
				} else {
					w[i].max_2_id = 3;
					w[i].max_3_sum = a1;
					w[i].max_3_id = 1;
				}
			} else {
				w[i].max_1_id = 3;
				w[i].max_2_sum = max(a1, a2);
				if (w[i].max_2_sum == a1) {
					w[i].max_2_id = 1;
					w[i].max_3_sum = a2;
					w[i].max_3_id = 2;
				} else {
					w[i].max_2_id = 2;
					w[i].max_3_sum = a1;
					w[i].max_3_id = 1;
				}
			}
		}
		stable_sort(w + 1, w + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (t[w[i].max_1_id] < (n / 2)) {
				t[w[i].max_1_id]++;
				ans += w[i].max_1_sum;
			} else {
				t[w[i].max_2_id]++;
				ans += w[i].max_2_sum;
			}
		}
		cout << ans << '\n';
		t[1] = t[2] = t[3] = 0;
		ans = 0;
	}

	return 0;
}
