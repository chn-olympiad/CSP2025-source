#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define GL return
#define HF 0

const int N = 100100;

struct info {
	int x, y, pos;
};

bool operator < (info a,  info b) {
	return a.x - a.y > b.x - b.y;
}

int test, n, m, a[N][3], c1, c2, c3;
vector<info> b[3];
ll ans = 0ll, s1, s2, s3;

void solve () {
	for (int i = 0; i < 3; i++) {
		b[i].clear();
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	ans = 0ll;
	for (int i = 1; i <= n; i++) {
		int x = max(a[i][0], max(a[i][1], a[i][2]));
		if (a[i][0] == x)  {
			info t;
			t.x = a[i][0], t.y = max(a[i][1], a[i][2]);
			t.pos = i;
			b[0].push_back(t);
		} else {
			if (a[i][1] == x) {
				info t;
				t.x = a[i][1], t.y = max(a[i][0], a[i][2]);
				t.pos = i;
				b[1].push_back(t);
			} else {
				info t;
				t.x = a[i][2], t.y = max(a[i][0], a[i][1]);
				t.pos = i;
				b[2].push_back(t);
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		sort(b[i].begin(), b[i].end());
		int len = b[i].size();
		for (int j = 0; j < len; j++) {
			ans += b[i][j].x;
		}
	}
	if ((int)b[1].size() > n / 2) {
		swap(b[0], b[1]);
	}
	if ((int)b[2].size() > n / 2) {
		swap(b[0], b[2]);
	}
	if ((int)b[0].size() > n / 2) {
		int len = b[0].size();
		for (int i = n / 2; i < len; i++) {
			ans -= b[0][i].x;
			ans += b[0][i].y;
		}
	}
	printf("%lld\n", ans);
	GL;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for (scanf("%d", &test); test--; solve());
	GL HF;
}
//key Ren5Jie4Di4Ling5%s
