#include <bits/stdc++.h>
using namespace std;
int t, n, a[100010][3], a1, a2, a3;
long long an1, an2, an3, ans, co;
int cnt1, cnt2, cnt3;

struct node {
	int va, nu, ca;
	bool operator <(const node &c)const {
		return ca < c.ca;
	}
} cu1[100010], cu2[100010], cu3[100010];

int fi(int x) {
	int re;
	re = max(max(a[x][1], a[x][2]), a[x][3]);
	//cout << re << endl;

	if (re == a[x][1]) {
		an1 = an1 + re;
		cu1[cnt1].va = a[x][1];
		cu1[cnt1].ca = a[x][1] - max(a[x][2], a[x][3]);
		cu1[cnt1].nu = x;
		cnt1++;
		return 1;

	} else if (re == a[x][2]) {
		an2 = an2 + re;
		cu2[cnt2].va = a[x][2];
		cu2[cnt2].ca = a[x][2] - max(a[x][1], a[x][3]);
		cu2[cnt2].nu = x;
		cnt2++;
		return 2;

	} else {
		an3 = an3 + re;
		cu3[cnt3].va = a[x][3];
		cu3[cnt3].ca = a[x][3] - max(a[x][1], a[x][2]);
		cu3[cnt3].nu = x;
		cnt3++;
		return 3;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		an1 = 0, an2 = 0, an3 = 0, ans = 0, a1 = 0, a2 = 0, a3 = 0;
		cnt1 = 1, cnt2 = 1, cnt3 = 1, co = 0;
		memset(cu1, 0, sizeof(cu1));
		memset(cu2, 0, sizeof(cu2));
		memset(cu3, 0, sizeof(cu3));
		for (int i = 1; i <= n; i++) {
			int x1;
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			x1 = fi(i);
			if (x1 == 1)
				a1++;
			if (x1 == 2)
				a2++;
			if (x1 == 3)
				a3++;
		}
		if (a1 <= (n / 2) && a2 <= (n / 2) && a3 <= (n / 2)) {
			ans = an1 + an2 + an3;
			//cout << an2;
			printf("%lld\n", ans);
			continue;
		} else {
			if (a1 > (n / 2)) {
				sort(cu1 + 1, cu1 + cnt1);
				for (int i = 1; i <= cnt1 - 1 - (n / 2); i++) {
					co = co + max(a[cu1[i].nu][2], a[cu1[i].nu][3]);
					an1 = an1 - cu1[i].va;
				}
				ans = an1 + an2 + an3 + co;
				printf("%lld\n", ans);
				continue;
			}
			if (a2 > (n / 2)) {
				sort(cu2 + 1, cu2 + cnt2);
				for (int i = 1; i <= cnt2 - 1 - (n / 2); i++) {
					//	cout << cu2[i].va;
					co = co + max(a[cu2[i].nu][1], a[cu2[i].nu][3]);
					an2 = an2 - cu2[i].va;
				}
				ans = an1 + an2 + an3 + co;

				printf("%lld\n", ans);
				continue;
			}
			if (a3 > (n / 2)) {
				sort(cu3 + 1, cu3 + cnt3);
				for (int i = 1; i <= cnt3 - 1 - (n / 2); i++) {
					co = co + max(a[cu3[i].nu][2], a[cu3[i].nu][1]);
					an3 = an3 - cu3[i].va;
				}
				ans = an1 + an2 + an3 + co;
				printf("%lld\n", ans);
				continue;
			}
		}
	}
	return 0;
}
