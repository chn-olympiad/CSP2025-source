//202511012025csp club tyk
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N][5], id[N];

//
//struct node {
//	long long val, id;
//	friend bool operator < (node n1, node n2) {
//		if (n1.val < n2.val)
//			return n1;
//		return n2;
//	}
//};

priority_queue<pair<int, int>>qab, qac, qba, qbc, qca, qcb;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		cin >> n;
		while (!qab.empty())
			qab.pop();
		while (!qac.empty())
			qac.pop();
		while (!qba.empty())
			qba.pop();
		while (!qbc.empty())
			qbc.pop();
		while (!qca.empty())
			qca.pop();
		while (!qcb.empty())
			qcb.pop();
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= max(a[i][2], a[i][3])) {//1
				if (cnt1 < (n >> 1)) {
					id[i] = 1, ans += a[i][1], cnt1++;
					qab.push({a[i][2] - a[i][1], i}), qac.push({a[i][3] - a[i][1], i});
				} else {
					int tmp1 = -INT_MAX, tmp2 = -INT_MAX, tmp = max(a[i][2], a[i][3]);
					int id1 = 0, id2 = 0;
					while (!qab.empty() && id[qab.top().second] != 1)
						qab.pop();
					while (!qac.empty() && id[qac.top().second] != 1)
						qac.pop();
					if (!qab.empty())
						tmp1 = qab.top().first, id1 = qab.top().second;
					if (!qac.empty())
						tmp2 = qac.top().first, id2 = qac.top().second;
					if (tmp1 + a[i][1] >= max(tmp2 + a[i][1], tmp)) {
						id[i] = 1, id[id1] = 2, ans += a[i][1] + tmp1, qab.pop(), cnt2++;
						qab.push({a[i][2] - a[i][1], i}), qac.push({a[i][3] - a[i][1], i});
						qba.push({a[id1][1] - a[id1][2], id1}), qbc.push({a[id1][3] - a[id1][2], id1});
					} else if (tmp2 + a[i][1] > max(tmp1 + a[i][1], tmp)) {
						id[i] = 1, id[id2] = 3, ans += a[i][1] + tmp2, qac.pop(), cnt3++;
						qab.push({a[i][2] - a[i][1], i}), qac.push({a[i][3] - a[i][1], i});
						qca.push({a[id2][1] - a[id2][3], id2}), qcb.push({a[id2][2] - a[id2][3], id2});
					} else if (a[i][2] > a[i][3]) {
						id[i] = 2, ans += a[i][2], cnt2++;
						qba.push({a[i][1] - a[i][2], i}), qbc.push({a[i][3] - a[i][2], i});
					} else {
						id[i] = 3, ans += a[i][3], cnt3++;
						qca.push({a[i][1] - a[i][3], i}), qcb.push({a[i][2] - a[i][3], i});
					}
				}
			} else if (a[i][2] > max(a[i][1], a[i][3])) {//2
				//	cout << "i" << i << " " << ans << "\n";
				if (cnt2 < (n >> 1)) {
					id[i] = 2, ans += a[i][2], cnt2++;
					qba.push({a[i][1] - a[i][2], i}), qbc.push({a[i][3] - a[i][2], i});
				} else {
					int tmp1 = -INT_MAX, tmp2 = -INT_MAX, tmp = max(a[i][1], a[i][3]);
					int id1 = 0, id2 = 0;
					while (!qba.empty() && id[qba.top().second] != 2)
						qba.pop();
					while (!qbc.empty() && id[qbc.top().second] != 2)
						qbc.pop();
					if (!qba.empty())
						tmp1 = qba.top().first, id1 = qba.top().second;
					if (!qbc.empty())
						tmp2 = qbc.top().first, id2 = qbc.top().second;
					//	cout << tmp1 << " " << id1 << " " << tmp2 << " " << id2 << "\n";
					if (tmp1 + a[i][2] >= max(tmp2 + a[i][2], tmp)) {
						//cout << "111" << "\n";
						id[i] = 2, id[id1] = 1, ans += a[i][2] + tmp1, qba.pop(), cnt1++;
						qba.push({a[i][1] - a[i][2], i}), qbc.push({a[i][3] - a[i][2], i});
						qab.push({a[id1][2] - a[id1][1], id1}), qac.push({a[id1][3] - a[id1][1], id1});
					} else if (tmp2 + a[i][2] > max(tmp1 + a[i][2], tmp)) {
						//cout << "222\n";
						id[i] = 2, id[id2] = 3, ans += a[i][2] + tmp2, qbc.pop(), cnt3++;
						qba.push({a[i][1] - a[i][2], i}), qbc.push({a[i][3] - a[i][2], i});
						qca.push({a[id2][1] - a[id2][3], id2}), qcb.push({a[id2][2] - a[id2][3], id2});
					} else if (a[i][1] > a[i][3]) {
						//	cout << "333\n";
						id[i] = 1, ans += a[i][1], cnt1++;
						qab.push({a[i][2] - a[i][1], i}), qac.push({a[i][3] - a[i][1], i});
					} else {
						//	cout << "444\n";
						id[i] = 3, ans += a[i][3], cnt3++;
						qca.push({a[i][1] - a[i][3], i}), qcb.push({a[i][2] - a[i][3], i});
					}
				}
			} else { //3
				if (cnt3 < (n >> 1)) {
					id[i] = 3, ans += a[i][3], cnt3++;
					qca.push({a[i][1] - a[i][3], i}), qcb.push({a[i][2] - a[i][3], i});
				} else {
					int tmp1 = -INT_MAX, tmp2 = -INT_MAX, tmp = max(a[i][1], a[i][2]);
					int id1 = 0, id2 = 0;
					while (!qca.empty() && id[qca.top().second] != 3)
						qca.pop();
					while (!qcb.empty() && id[qcb.top().second] != 3)
						qcb.pop();
					if (!qca.empty())
						tmp1 = qca.top().first, id1 = qca.top().second;
					if (!qcb.empty())
						tmp2 = qcb.top().first, id2 = qcb.top().second;
					if (tmp1 + a[i][3] >= max(tmp2 + a[i][3], tmp)) {
						id[i] = 3, id[id1] = 1, ans += a[i][3] + tmp1, qca.pop(), cnt1++;
						qca.push({a[i][1] - a[i][3], i}), qcb.push({a[i][2] - a[i][3], i});
						qab.push({a[id1][2] - a[id1][1], id1}), qac.push({a[id1][3] - a[id1][1], id1});
					} else if (tmp2 + a[i][3] > max(tmp1 + a[i][3], tmp)) {
						id[i] = 3, id[id2] = 2, ans += a[i][3] + tmp2, qcb.pop(), cnt2++;
						qca.push({a[i][1] - a[i][3], i}), qcb.push({a[i][2] - a[i][3], i});
						qba.push({a[id2][1] - a[id2][2], id2}), qbc.push({a[id2][3] - a[id2][2], id2});
					} else if (a[i][1] > a[i][2]) {
						id[i] = 1, ans += a[i][1], cnt1++;
						qab.push({a[i][2] - a[i][1], i}), qac.push({a[i][3] - a[i][1], i});
					} else {
						id[i] = 2, ans += a[i][2], cnt2++;
						qba.push({a[i][1] - a[i][2], i}), qbc.push({a[i][3] - a[i][2], i});
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/