#include <bits/stdc++.h>

using namespace std;

int T, n;

priority_queue<int> p;
priority_queue<int> q;

struct Node {
	int v1;
	int v2;
	int v3;
	int id;
	int sid;
	int tid;
	int fnum;
	int snum;
	int tnum;
} a[100005];

int num[11];

void rst() {
	for (int i = 1; i <= n; i ++) {
		if (a[i].v1 >= a[i].v2 && a[i].v1 >= a[i].v3) {
			a[i].id = 1;
			a[i].fnum = a[i].v1;
			if (a[i].v2 >= a[i].v3) {
				a[i].snum = a[i].v2;
				a[i].sid = 2;
				a[i].tnum = a[i].v3;
				a[i].tid = 3;
			} else {
				a[i].snum = a[i].v3;
				a[i].sid = 3;
				a[i].tnum = a[i].v2;
				a[i].tid = 2;
			}
		} else if (a[i].v2 >= a[i].v1 && a[i].v2 >= a[i].v3) {
			a[i].id = 2;
			a[i].fnum = a[i].v2;
			if (a[i].v1 >= a[i].v3) {
				a[i].snum = a[i].v1;
				a[i].sid = 1;
				a[i].tnum = a[i].v3;
				a[i].tid = 3;
			} else {
				a[i].snum = a[i].v3;
				a[i].sid = 3;
				a[i].tnum = a[i].v1;
				a[i].tid = 1;
			}
		} else {
			a[i].id = 3;
			a[i].fnum = a[i].v3;
			if (a[i].v1 >= a[i].v2) {
				a[i].snum = a[i].v1;
				a[i].sid = 1;
				a[i].tnum = a[i].v2;
				a[i].tid = 2;
			} else {
				a[i].snum = a[i].v2;
				a[i].sid = 2;
				a[i].tnum = a[i].v1;
				a[i].tid = 1;
			}
		}
	}
}

bool cmp(Node x, Node y) {
	if (x.fnum == y.fnum)
		if (x.snum == y.snum)
			return x.tnum > y.tnum;
	return x.snum > y.snum;
	return x.fnum > y.fnum;
}

int arr[100005][11];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T --) {
		cin >> n;
		num[1] = 0, num[2] = 0, num[3] = 0;
		int sum = 0;
		if (n <= 300) {
			for (int i = 1; i <= n; i ++) {
				cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
				sum += max(arr[i][1], max(arr[i][2], arr[i][3]));
				int te = max(arr[i][1], max(arr[i][2], arr[i][3]));
				if (te == arr[i][1]) {
					arr[i][4] = 1;
				}
				if (te == arr[i][2]) {
					arr[i][4] = 2;
				}
				if (te == arr[i][3]) {
					arr[i][4] = 3;
				}
			}
			for (int i = 1; i <= n; i ++) {

			}

		}
		long long ans = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
		}
		rst();
		sort(a + 1, a + 1 + n, cmp);
		int atid;
		for (int i = 1; i <= n; i ++) {
			if (num[a[i].id] >= n / 2) {
				atid = a[i].id;
				ans += a[i].snum;
				p.push(a[i].fnum - a[i].snum);
			} else {
				num[a[i].id] ++;
				ans += a[i].fnum;
			}
		}
		for (int i = 1; i <= n; i ++) {
			if (a[i].id == atid) {
				q.push(-(a[i].fnum - a[i].snum));
			}
		}
		if (q.empty() || p.empty()) {
			cout << ans << "\n";
			continue;
		}
		while ((!q.empty()) && (!p.empty())) {
			if (p.top() > -q.top()) {
				ans = ans + p.top() + q.top();
			}
			p.pop();
			q.pop();
		}
		cout << ans << "\n";
	}
	return 0;
}
