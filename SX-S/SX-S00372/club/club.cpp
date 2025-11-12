#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int t, n, a[N][10], cl[N];
long long ans;

struct node {
	int pos, w1, w2, w3;
} nd[N];

struct club {
	int pos, w;
};

bool cmp1(club a, club b) {
	return a.w == b.w ? cl[a.pos] < cl[b.pos] : a.w > b.w;
}

multiset<int> x[5];

void solve() {
	cin >> n;
	ans = 0;
	for (int i = 0; i <= 4; i++)
		x[i].clear();
	for (int i = 1; i <= n; i++)
		cl[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 3; j++)
			cin >> a[i][j];
	random_shuffle(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		vector<club> v;
		v.push_back({1, a[i][1]});
		v.push_back({2, a[i][2]});
		v.push_back({3, a[i][3]});
		sort(v.begin(), v.end(), cmp1);
		for (int j = 0; j <= 2; j++) {
			if (cl[v[j].pos] + 1 > (n / 2) && v[j].w > (*x[v[j].pos].begin())) {
				ans = ans - (*x[v[j].pos].begin()) + v[j].w;
				x[v[j].pos].erase(x[v[j].pos].begin());
				x[v[j].pos].insert(v[j].w);
				break;
			} else if (cl[v[j].pos] + 1 <= (n / 2)) {
				cl[v[j].pos]++,
				ans += v[j].w;
				x[v[j].pos].insert(v[j].w);
				break;
			}
		}
		v.clear();
	}
	cout << ans << '\n';
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
		solve();
	return 0;
}
