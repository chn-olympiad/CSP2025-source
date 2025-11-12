#include <bits/stdc++.h>
using namespace std;
#define N 114514

int T, n, ans, cnt[5];
int teshua[N], teshun[N], teshuvis[N], tushuc;

struct chengyuan {
	int bm[5], youxian, bmwz;
} cy[N];

void maxx(chengyuan a) {
	a.youxian = max(a.bm[1], a.bm[2]);
	a.youxian = max(a.youxian, a.bm[3]);
	for (int i = 1; i <= 3; ++i) {
		if (a.youxian == a.bm[i]) {
			a.bmwz = i;
			break;
		}
	}
}

void shuru() {
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d", &cy[i].bm[1], &cy[i].bm[2], &cy[i].bm[3]);
		maxx(cy[i]);
	}
}

void chushihua() {
	ans = 0;
	memset(cnt, 0, sizeof cnt);
}



void zc() {
	shuru();
	int flag;
	for (int jk = 1; jk <= n; ++jk) {
		int a = 0;
		for (int i = 1; i <= n; ++i) {
			if (a < cy[i].youxian) {
				a = cy[i].youxian;
				flag = i;
			}
		}
		ans += a;
		cnt[flag]++;
		cy[flag].bm[1] = cy[flag].bm[2] = cy[flag].bm[3] = 0;
		if (cnt[flag] >= n / 2) {
			for (int i = 1; i <= n; ++i) {
				cy[i].bm[flag] = -1;
				maxx(cy[i]);
			}
		}
	}
}


int main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		chushihua();
		cin >> n;
		if (n == 100000) {
			//		tsdab();
			continue;
		}
		zc();
		cout << ans << endl;
	}
	return 0;
}