#include <bits/stdc++.h>
using namespace std;
int t, n, ans, f1[100010], f2[100010];
bool flaga = true, flagb = true;

struct affaction {
	int ai[4];
} a[100010];

bool cmp(affaction x, affaction y) {
	return x.ai[1] > y.ai[1];
}

void spA() {
	sort(a + 1, a + 1 + n, cmp);
	for (int i = 1; i <= n / 2; i++)
		ans += a[i].ai[1];
}

void back() {
	for (int i = 1; i <= n; i++)
		for (int j = n / 2; j > 0; j--) {
			f1[j] += a[i].ai[1];
			f1[j] = max(f1[j], f1[j - 1] + a[i].ai[2]);
		}
	for (int i = 1; i <= n; i++)
		for (int j = n / 2; j > 0; j--) {
			f2[j] += a[i].ai[2];
			f2[j] = max(f2[j], f2[j - 1] + a[i].ai[1]);
		}
	ans = min(f1[n / 2], f2[n / 2]);
}
int num[4];

void brute(int d, int now) {

	if (d > n) {
		ans = max(ans, now);
		return ;
	}
	for (int i = 1; i <= 3; i++) {
		if (num[i] >= n / 2)
			continue;
		num[i]++;
		brute(d + 1, now + a[d].ai[i]);
		num[i]--;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		memset(num, 0, sizeof(num));
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].ai[1] >> a[j].ai[2] >> a[j].ai[3];
			if (a[j].ai[3])
				flaga = false, flagb = false;
			if (a[j].ai[2])
				flaga = false;
		}
		if (n <= 10) {
			brute(1, 0);
		} else if (flaga)
			spA();
		else if (flagb)
			back();
		cout << ans << "\n";
	}
	return 0;
}