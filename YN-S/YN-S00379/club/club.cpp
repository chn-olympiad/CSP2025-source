#include <bits/stdc++.h>
using namespace std;
int t, n, cnt, m;
const int N = 1e5 + 5;

struct a_1 {
	int u;
	int id;
	bool vis;
} a1[N];

struct a_2 {
	int v;
	int id;
	bool vis;
} a2[N];

struct a_3 {
	int w;
	int id;
	bool vis;
} a3[N];

bool cmp1(a_1 q, a_1 p) {
	if (q.u > p.u) {
		return q.u > p.u;
	} else {
		return q.id > p.id;
	}
}

bool cmp2(a_2 q, a_2 p) {
	if (q.v > p.v) {
		return q.v > p.v;
	} else {
		return q.id > p.id;
	}
}

bool cmp3(a_3 q, a_3 p) {
	if (q.w > p.w) {
		return q.w > p.w;
	} else {
		return q.id > p.id;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(a1, 0, sizeof(a1));
		memset(a2, 0, sizeof(a2));
		memset(a3, 0, sizeof(a3));
		cnt = 0;
		m = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i].u >> a2[i].v >> a3[i].w;
			a1[i].id = a2[i].id = a3[i].id = i;
		}
		stable_sort(a1 + 1, a1 + n + 1, cmp1);
		stable_sort(a2 + 1, a2 + n + 1, cmp2);
		stable_sort(a3 + 1, a3 + n + 1, cmp3);
		for (int i = 1; i <= n; i++) {
			if (a1[i].vis == 0) {
				a1[i].vis = 1;
				for (int j = 1; j <= n; j++) {
					if (a1[i].id == a2[j].id) {
						a2[j].vis = 1;
						break;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (a1[i].id == a3[j].id) {
						a3[j].vis = 1;
						break;
					}
				}
				cnt += a1[i].u;
				m++;
				//cout << "a1[i].u:" << a1[i].u << endl;
			}
			if (a2[i].vis == 0) {
				a2[i].vis = 1;
				for (int j = 1; j <= n; j++) {
					if (a2[i].id == a1[j].id) {
						a1[j].vis = 1;
						break;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (a2[i].id == a3[j].id) {
						a3[j].vis = 1;
						break;
					}
				}
				cnt += a2[i].v;
				m++;
				//cout << "a2[i].v:" << a2[i].v << endl;
			}
			if (a3[i].vis == 0) {
				a3[i].vis = 1;
				for (int j = 1; j <= n; j++) {
					if (a3[i].id == a1[j].id) {
						a1[j].vis = 1;
						break;
					}
				}
				for (int j = 1; j <= n; j++) {
					if (a3[i].id == a2[j].id) {
						a2[j].vis = 1;
						break;
					}
				}
				cnt += a3[i].w;
				m++;
				//cout << "a3[i].w:" << a3[i].w << endl;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}