#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 100005
#define INF 0x3f3f3f3f
using namespace std;
int t, n;
struct Node {
	int val1, val2, val3;
	int max_val, next_max_val, c;
	int max_id, next_max_id;
	bool operator<(Node &b) {
		if (max_val == b.max_val) return next_max_val > b.next_max_val;
		return max_val > b.max_val;
	}
} a[maxn];
void solve();
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
		solve();
	return 0;
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val1 >> a[i].val2 >> a[i].val3;
		if (a[i].val1 >= a[i].val2 && a[i].val1 >= a[i].val3) {
			a[i].max_val = a[i].val1, a[i].max_id = 1;
			if (a[i].val2 >= a[i].val3) a[i].next_max_val = a[i].val2, a[i].next_max_id = 2;
			else  a[i].next_max_val = a[i].val3, a[i].next_max_id = 3;
		} else if (a[i].val2 >= a[i].val1 && a[i].val2 >= a[i].val3) {
			a[i].max_val = a[i].val2, a[i].max_id = 2;
			if (a[i].val1 >= a[i].val3) a[i].next_max_val = a[i].val1, a[i].next_max_id = 1;
			else  a[i].next_max_val = a[i].val3, a[i].next_max_id = 3;
		} else if (a[i].val3 >= a[i].val2 && a[i].val3 >= a[i].val1) {
			a[i].max_val = a[i].val3, a[i].max_id = 3;
			if (a[i].val1 >= a[i].val2) a[i].next_max_val = a[i].val1, a[i].next_max_id = 1;
			else  a[i].next_max_val = a[i].val2, a[i].next_max_id = 2;
		}
		a[i].c = a[i].max_val - a[i].next_max_val;
	}
	int cnt[4] = {0}, ans = 0;
	priority_queue<int, vector<int>, greater<int>> min_c[4];
	for (int i = 1; i <= n; i++) {
		if (cnt[a[i].max_id] >= n / 2) {
			if (!min_c[a[i].max_id].empty()) {
				if (a[i].max_val - min_c[a[i].max_id].top() > a[i].next_max_val) {
					ans += a[i].max_val - min_c[a[i].max_id].top();
					min_c[a[i].max_id].pop();
					min_c[a[i].max_id].push(a[i].c);
				} else {
					ans += a[i].next_max_val;
				}
			} else {
				ans += a[i].next_max_val;
			}
		} else {
			ans += a[i].max_val;
			cnt[a[i].max_id]++;
			min_c[a[i].max_id].push(a[i].c);
		}
	}
	cout << ans << endl;
}