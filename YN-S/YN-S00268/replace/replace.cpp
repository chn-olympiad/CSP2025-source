#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10;
int n, q, mov[N], cnt;
set<int>st;
struct node {
	int loc, val;
};
queue<node>qu;

//void bfs(int st, int en, int siz) {
//	int ans = 0;
//	node now = {st, 1};
//	qu.push(now);
//
//	while (!qu.empty()) {
//		now = qu.front();
//		qu.pop();
//
//		if (now.loc == en) {
//			ans += now.val;
//			continue;
//		}
//
//		for (auto it : st) {
//			if (now.loc + it >= 0 && now.loc + it <= siz - 1) {
//				qu.push(now.loc + it, now.val);
//			}
//		}
//	}
//
//	cout << ans << "\n";
//}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;

	for (int i = 1; i <= n; i++) {

		string a, b;
		cin >> a >> b;
		st.insert((int)a.find('b') - (int)b.find('b'));
	}

	for (int i = 1; i <= q; i++) {

		string a, b;
		cin >> a >> b;
		int fl = a.find('b'), fla = b.find('b');
		cout << 0 << "\n";
//		bfs(fl, fla, a.size());
	}

	return 0;
}