#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n, t, ans, a[4][100100], shu[4], flag = 0, fg = 0;//iu;
ll iu;

struct Ab {
	ll i1;
	ll be_st;
	ll wor_se;
	ll wor_st;
};

struct Ba {
	ll i1;
	ll maa;
};

bool cmm(Ba q, Ba w) {
	return q.maa < w.maa;
}

bool cmp(Ab q, Ab w) {
	if (a[q.be_st][q.i1] != a[w.be_st][w.i1]) {
		return a[q.be_st][q.i1] < a[w.be_st][w.i1];
	} else if (a[q.wor_se][q.i1] != a[w.wor_se][w.i1]) {
		return a[q.wor_se][q.i1] > a[w.wor_se][w.i1];
	} else {
		return a[q.wor_st][q.i1] > a[w.wor_st][w.i1];
	}
}
Ab wor[100100];
Ba joo[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t != 0) {
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(joo, 0, sizeof(joo));
		memset(wor, 0, sizeof(wor));
		memset(shu, 0, sizeof(shu));
		t--;
		cin >> n;
		for (ll i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
			joo[0].i1 = 1;
			joo[0].maa = a[1][i];
			joo[1].i1 = 2;
			joo[1].maa = a[2][i];
			joo[2].i1 = 3;
			joo[2].maa = a[3][i];
			sort(joo, joo + 3, cmm);
			wor[i].i1 = i;
			wor[i].be_st = joo[2].i1;
			wor[i].wor_se = joo[1].i1;
			wor[i].wor_st = joo[0].i1;
		}
		sort(wor + 1, wor + n + 1, cmp);
		flag = 1;
		fg = wor[1].be_st;
		for (ll j = 1; j <= n; j++) {
			iu = wor[j].i1;
			if (fg != wor[j].be_st) {
				fg = wor[j].be_st;
				flag = j;
			}
			ans += a[wor[j].be_st][iu];
			shu[wor[j].be_st]++;
			if (shu[wor[j].be_st] > (n / 2)) {
				shu[wor[j].be_st]--;
				if (flag == wor[j].i1) {
					if (a[wor[j].wor_se][iu] > a[wor[j].wor_st][iu]) {
						ans -= a[wor[j].be_st][iu];
						ans += a[wor[j].wor_se][iu];
						shu[wor[j].wor_se]++;
					} else {
						ans -= a[wor[j].be_st][iu];
						ans += a[wor[j].wor_st][iu];
						shu[wor[j].wor_st]++;
					}
					flag++;
				} else {
					ans -= a[wor[flag].be_st][wor[flag].i1];
					if (shu[wor[j].wor_se] + 1 <= (n / 2)) {
						shu[wor[j].wor_se]++;
						ans += a[wor[flag].wor_se][iu];
					} else {
						shu[wor[j].wor_st]++;
						ans += a[wor[flag].wor_st][iu];
					}
					flag++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
