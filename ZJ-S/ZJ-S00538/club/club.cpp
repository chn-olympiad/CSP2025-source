#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100005
int n, t;
struct Node {
	int id, val, cb;
	bool operator<(const Node& other) const {
		return val > other.val;
	}
} a[N][3];
int read() {
	int dgt = 0;
	char c;
	while (!isdigit(c = getchar()));
	do {
		dgt = dgt * 10 + c - '0';
	} while (isdigit(c = getchar()));
	return dgt;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			a[i][0].id = a[i][1].id = a[i][2].id = i;
			a[i][0].cb = 0;
			a[i][1].cb = 1;
			a[i][2].cb = 2;
			a[i][0].val = read();
			a[i][1].val = read();
			a[i][2].val = read();
			sort(a[i], a[i] + 3);
		}
		int ans = 0;
		vector<Node> club[3];
		for (int i = 1; i <= n; ++i) {
			club[a[i][0].cb].push_back(a[i][0]);
			ans += a[i][0].val;
		}
		int mp = n >> 1;
		int ov = -1;
		if (club[0].size() > mp) ov = 0;
		if (club[1].size() > mp) ov = 1;
		if (club[2].size() > mp) ov = 2;
		if (ov == -1) {
			cout << ans << endl;
			continue;
		}
		vector<int> cmp(club[ov].size());
		for (int i = 0; i < cmp.size(); ++i)
			cmp[i] = club[ov][i].val - a[club[ov][i].id][1].val;
		sort(cmp.begin(), cmp.end(),
			[](int x, int y) {
				return x > y;
			});
		for (int i = mp; i < cmp.size(); ++i)
			ans -= cmp[i];
		cout << ans << endl;
	}
	return 0;
}
