#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n;

struct club {
	int id, w;
};

bool cmp(club a, club b) {
	return a.w > b.w;
}

struct student {
	int now, nw;
	club c[3];
	bool operator<(const student x)const {
		return x.nw < nw;
	}
} st[N];
priority_queue<student>pq[3];

void slove() {
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> st[i].c[j].w;
			st[i].c[j].id = j;
		}
		sort(st[i].c, st[i].c + 3, cmp);
		st[i].nw = st[i].c[0].w - st[i].c[1].w;
		st[i].now = 0;
		pq[st[i].c[0].id].push(st[i]);
		ans += st[i].c[0].w;
	}
	for (int j = 0; j < 3; j++) {
		while (pq[j].size() > n / 2) {
			auto s = pq[j].top();
			pq[j].pop();
			ans -= s.nw;
			s.now++;
			if (s.now == 2)
				s.nw = 1e9;
			else
				s.nw = s.c[s.now + 1].w - s.c[s.now].w;
			pq[s.c[s.now].id].push(s);
		}
	}
	for (int j = 0; j < 3; j++) {
		while (pq[j].size() > n / 2) {
			auto s = pq[j].top();
			pq[j].pop();
			ans -= s.nw;
			s.now++;
			if (s.now == 2)
				s.nw = 1e9;
			else
				s.nw = s.c[s.now + 1].w - s.c[s.now].w;
			pq[s.c[s.now].id].push(s);
		}
	}
	cout << ans << '\n';
	for (int j = 0; j < 3; j++) {
		while (pq[j].size()) {
			pq[j].pop();
		}
	}
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	cin >> T;
	while (T--)
		slove();

	return 0;
}