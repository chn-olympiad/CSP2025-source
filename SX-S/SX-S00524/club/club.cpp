#include <bits/stdc++.h>
using namespace std;
int a[10060][4], lo[10060], cnt[4], gofn[10060];

struct ininl {
	int fro, bac;
};

bool operator<(const ininl &c, const ininl &b) {
	return c.fro < b.fro;
}
priority_queue<ininl> q[4]; //first存储差，第二个存储编号

struct node {
	int i, w, pl ;
};

vector<node> s;//事件序列

bool operator<(const node &c, const node &b) {
	return c.w < b.w;
}

bool operator>(const node &c, const node &b) {
	return c.w > b.w;
}

inline ininl move_num(int op, int b, int c) {
	ininl x[3] = {{op, 1}, {b, 2}, {c, 3}};
	sort(x, x + 3);
	ininl lk = {x[1].fro - x[2].fro, x[1].bac};
	return lk;
}

ininl max(ininl &op, ininl &b) {
	if (op < b)
		return b;
	return op;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int t;
	scanf("%d", &t);
	while (t--) {

		s.erase(s.begin(), s.end());
		memset(cnt, 0, sizeof(cnt));
		memset(gofn, 0, sizeof(gofn));
		memset(a, 0, sizeof(a));
		memset(lo, 0, sizeof(lo));
		for (int i = 0; i <= 3; i++) {
			while (!q[i].empty())
				q[i].pop();
		}
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			ininl stay;
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);

			ininl onl, sc, thr;
			onl.fro = a[i][1], onl.bac = 1;
			sc.fro = a[i][2], sc.bac = 2;
			thr.fro = a[i][3], thr.bac = 3;

			stay = max(max(onl, sc), max(sc, thr)); //max
			ininl kml = move_num(a[i][1], a[i][2], a[i][3]); //求差
			lo[i] = kml.fro;
			gofn[i] = kml.bac;
			node lkk;
			lkk.i = i;
			lkk.w = stay.fro;
			lkk.pl = stay.bac;
			s.push_back(lkk);

		}

		sort(s.begin(), s.end(), greater<node>());

		for (auto x : s) {
			int pl = x.pl;
			if (q[pl].size() < n / 2) {
				ininl now;
				now.fro = lo[x.i];
				now.bac = x.i;
				q[pl].push(now);
				cnt[pl]++;
			} else {

				ininl cha = q[pl].top();
				if (cha.fro + x.w > 0 && cha.fro + x.w > a[x.i][gofn[x.i]]) {

					q[pl].pop();
					ininl now;
					now.fro = lo[x.i];
					now.bac = x.i;
					q[pl].push(now);
					q[gofn[cha.bac]].push(cha);
					cnt[gofn[cha.bac]]++;
				} else {
					ininl now;
					now.fro = lo[x.i];
					now.bac = x.i;
					q[gofn[x.i]].push(now);
					cnt[gofn[x.i]]++;
				}
			}

		}
		long long ans = 0;
		for (int i = 0; i <= 3; i++) {
			while (!q[i].empty()) {
				ininl now = q[i].top();
				q[i].pop();
				ans += a[now.bac][i];
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}
