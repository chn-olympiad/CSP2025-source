#include <bits/stdc++.h>

using namespace std;
int t;

struct co {
	int num, like;
	bool used = 0;
};

bool cmp(co a, co b) {
	return a.like > b.like;

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {

		int n;
		co ac[10005], bc[10005], cc[10005], ac1[10005], bc1[10005], cc1[10005];
		cin >> n;
		//输入  A B C 各自的可能者与喜爱值
		for (int i = 1; i <= n; i++) {
			cin >> ac[i].like >> bc[i].like >> cc[i].like;
			ac[i].num = i;
			bc[i].num = i;
			cc[i].num = i;
			ac1[i].num = i;
			bc1[i].num = i;
			cc1[i].num = i;
			ac1[i].like = ac[i].like;
			bc1[i].like = bc[i].like;
			cc1[i].like = cc[i].like;
		}

//贪心 求最值 优先求出各组中的前1/2n的喜爱值之和 求max  而后组数减一 人数/2
// 再于剩余的人与组中求最值 选最大即可
		sort(ac + 1, ac + 1 + n, cmp);
		sort(bc + 1, bc + 1 + n, cmp);
		sort(cc + 1, cc + 1 + n, cmp);

		long long af = 0, bf = 0, cf = 0;
		for (int i = 1; i <= n / 2; i++) {
			af += ac[i].like;
			bf += bc[i].like;
			cf += cc[i].like;
			ac[i].used = 1;
			bc[i].used = 1;
			cc[i].used = 1;
		}
		long long maxx, ans = 0;
		maxx = max(af, max(bf, cf));
		ans += maxx;

		if (maxx == af) {
			for (int i = n / 2 + 1; i <= n; i++) {
				for (int j = n / 2 + 1; j <= n; j++) {
					if (bc[i].num == cc[j].num && bc[i].used == 0 && cc[i].used == 0) {
						if (bc[i].like >= cc[i].like) {
							ans += bc[i].like;
						} else {
							ans += cc[i].like;
						}
					}
				}
			}
		} else if (maxx == bf) {
			for (int i = n / 2 + 1; i <= n; i++) {
				for (int j = n / 2 + 1; j <= n; j++) {
					if (ac[i].num == cc[j].num && ac[i].used == 0 && cc[i].used == 0) {
						if (ac[i].like >= cc[i].like) {
							ans += ac[i].like;
						} else {
							ans += cc[i].like;
						}
					}
				}
			}
		} else if (maxx == cf) {
			for (int i = n / 2 + 1; i <= n; i++) {
				for (int j = n / 2 + 1; j <= n; j++) {
					if (ac[i].num == bc[j].num && ac[i].used == 0 && bc[i].used == 0) {
						if (ac[i].like >= bc[i].like) {
							ans += ac[i].like;
						} else {
							ans += bc[i].like;
						}
					}
				}
			}
		}
		cout << ans;

	}
	return 0;
}