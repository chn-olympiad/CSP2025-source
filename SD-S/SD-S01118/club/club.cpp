#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
int n, T, a[N][3];
#define PII pair<int, int>

struct Node {
	int x, y, id, id2;
	bool operator> (const Node& b) const{
		return y - x < b.y - b.x;
	}
//	bool operator< (const Node& b) const{
//		return y - x < b.y - b.x;
//	}
};
priority_queue<Node, vector<Node>, greater<Node>> q[3];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int mid = n >> 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
			int mxid = a[i][0] <= a[i][1], cmxid = !mxid;
			if (a[i][2] > a[i][mxid]) cmxid = mxid, mxid = 2;
			else if (a[i][2] > a[i][cmxid]) cmxid = 2;
			q[mxid].push({a[i][mxid], a[i][cmxid], i, cmxid});
//			printf("==> %d %d %d\n", i, mxid, cmxid);
			for (int j = 0; j < 3; j++) {
				if (q[j].size() > mid) {
					Node cur = q[j].top();
					q[j].pop();
					q[cur.id2].push({cur.y, cur.x, cur.id, cur.id2});
//					printf("==> %d %d %d %d\n", cur.x, cur.y, cur.id, cur.id2);
					break;
				}
			}
		}
		int ans = 0;
		for (int j = 0; j < 3; j++) {
			while (!q[j].empty()) {
				ans += q[j].top().x;
				q[j].pop();
			}
		}
		printf("%d\n", ans);
	}
	return 0; 
}


