#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	int fr, sc, sd, mmax, mmin, mmix;
};
node arr[1000086];

bool cmp(node a, node b) {
	if (a.fr != b.fr)
		return a.fr > b.fr;
	if (b.sc != b.sc)
		return a.sc > b.sc;
	else
		a.sd > b.sd;
}
int n;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 2) {
			int mmax = -1e9, xdd[4] = {}, brr[4] = {};
			cin >> xdd[1] >> xdd[2] >> xdd[3] >> brr[1] >> brr[2] >> brr[3];
			for (int i = 1; i <= 3; i++) {
				for (int j = 1; j <= 3; j++) {
					if (i != j) {
						mmax = max(mmax, xdd[i] + brr[j]);
					}
				}
			}
			cout << mmax;
			continue;
		}
		int k = n / 2, tot[4] = {};
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].fr >> arr[i].sc >> arr[i].sd;
			if (arr[i].fr >= arr[i].sc && arr[i].sc >= arr[i].sd)
				arr[i].mmax = 1, arr[i].mmin = 2, arr[i].mmix = 3;
			if (arr[i].fr >= arr[i].sd && arr[i].sd >= arr[i].sc)
				arr[i].mmax = 1, arr[i].mmin = 3, arr[i].mmix = 2;
			if (arr[i].sc >= arr[i].sd && arr[i].sd >= arr[i].fr)
				arr[i].mmax = 2, arr[i].mmin = 3, arr[i].mmix = 1;
			if (arr[i].sc >= arr[i].fr && arr[i].fr >= arr[i].sd)
				arr[i].mmax = 2, arr[i].mmin = 1, arr[i].mmix = 3;
			if (arr[i].sd >= arr[i].sc && arr[i].sc >= arr[i].fr)
				arr[i].mmax = 3, arr[i].mmin = 2, arr[i].mmix = 1;
			if (arr[i].sd >= arr[i].fr && arr[i].fr >= arr[i].sc)
				arr[i].mmax = 3, arr[i].mmin = 1, arr[i].mmix = 2;
		}
		sort(arr + 1, arr + n + 1, cmp);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int x = arr[i].mmax, y = arr[i].mmin, z = arr[i].mmix;
			if (tot[x] < k) {
				if (x == 1)
					ans += arr[i].fr;
				if (x == 2)
					ans += arr[i].sc;
				if (x == 3)
					ans += arr[i].sd;
				tot[x]++;
			} else if (tot[y] < k) {
				if (y == 1)
					ans += arr[i].fr;
				if (y == 2)
					ans += arr[i].sc;
				if (y == 3)
					ans += arr[i].sd;
				tot[y]++;
			} else {
				if (z == 1)
					ans += arr[i].fr;
				if (z == 2)
					ans += arr[i].sc;
				if (z == 3)
					ans += arr[i].sd;
				tot[z]++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
