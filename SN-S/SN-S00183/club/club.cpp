#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define mkpr make_pair
#define fir first
#define sec second

using namespace std;

const int maxn = 1e5 + 7;
const int inf  = 0x3f3f3f3f;

int n, a[maxn][5];
int ans;
bool cmp(pii x, pii y) {
		if (x.fir != y.fir) return x.fir > y.fir;
		return x.sec < y.sec;
	}
struct stu {
	int now; pii pri[5];
	stu() {}
	stu(int a, int b, int c) {
		pri[1] = mkpr(a, 1), pri[2] = mkpr(b, 2), pri[3] = mkpr(c, 3);
		sort(pri + 1, pri + 3 + 1, cmp), now = -pri[1].fir + pri[2].fir;
	}
	bool operator < (const stu& oth) const {
		return now < oth.now;
	}
};
priority_queue<stu> q[5];
void clear() {
	ans = 0;
	for (int i = 1; i <= 3; ++i)
		while (q[i].size()) q[i].pop();
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 3; ++j) a[i][j] = 0;
}
void solution() {
//	puts("|||||||||||||||||||||||||||||||||||||||||||||||");
//	printf("tskid:%d\n", tskid);
	clear(); scanf("%d", &n);
//	if (tskid == 4) {
//		printf("n:%d\n", n);
//		for (int i = 1; i <= 3; ++i)
//			printf("q[%d].size():%d\n", i, (int)q[i].size());
//	}
	for (int i = 1; i <= n; ++i) {
		int mx = -inf, id = 0;
		for (int j = 1; j <= 3; ++j) {
			scanf("%d", &a[i][j]);
			if (mx < a[i][j]) mx = a[i][j], id = j;
		}
		ans += mx, q[id].push(stu(a[i][1], a[i][2], a[i][3]));
	}
	int ovrid = 0;
	for (int i = 1; i <= 3; ++i)
		if ((int)q[i].size() > n / 2) ovrid = i;
//	printf("ovrid:%d\n", ovrid);
//	for (int i = 1; i <= 3; ++i) {
//		puts("---------------------------------------");
//		printf("q:%d\n", i);
//		vector<stu> vec; vec.clear();
//		while (q[i].size()) {
//			stu x = q[i].top(); vec.push_back(x), q[i].pop();
//			printf("id:%d, now:%d, fir(%d, %d), sec(%d, %d), thi(%d, %d)\n",
//				x.id, x.now, x.pri[1].fir, x.pri[1].sec, x.pri[2].fir, x.pri[2].sec, x.pri[3].fir, x.pri[3].sec);
//		}
//		for (stu x : vec) q[i].push(x);
//	}
	if (!ovrid) {printf("%d\n", ans); return ;}
//	printf("ovrid:%d, siz:%d\n", ovrid, (int)q[ovrid].size());
	while ((int)q[ovrid].size() > n / 2) {
//		printf("siz:%d\n", (int)q[ovrid].size());
		stu x = q[ovrid].top(); q[ovrid].pop(), ans += x.now;
//		printf("fir(%d, %d), sec(%d, %d), thi(%d, %d)\n", x.pri[1].fir, x.pri[1].sec, x.pri[2].fir, x.pri[2].sec, x.pri[3].fir, x.pri[3].sec);
		q[x.pri[2].sec].push(stu(x.pri[1].fir, x.pri[2].fir, x.pri[3].fir));
	}
	printf("%d\n", ans);
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("my.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int i = 1; i <= T; ++i) solution();
	return 0;
}

