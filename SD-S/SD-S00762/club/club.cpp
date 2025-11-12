#include <iostream>
#include <algorithm>
#include <fstream>
/*
 
*/
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
int cnt[4], a[N][4], rev[N], grt[N], pl[N];
int main() {
	ifstream fin("club.in");
	ofstream fout("club.out");
#define cin fin
#define cout fout
	int ttt;
	cin >> ttt;
	while (ttt--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		ll res = 0;
		for (int i = 1; i <= n; i++) {
			int mx = 1;
			if (a[i][2] > a[i][mx]) mx = 2;
			if (a[i][3] > a[i][mx]) mx = 3;
			cnt[mx]++;
			grt[i] = mx;
			res += a[i][mx];
			int tmp[4] = {0, a[i][1], a[i][2], a[i][3]};
			sort(tmp + 1, tmp + 4);
			pl[i] = tmp[3] - tmp[2];
		}
		int tn = n / 2;
		int ge = max(cnt[1], max(cnt[2], cnt[3])), tot = 0;
		for (int i = 1; i <= n; i++) if (cnt[grt[i]] == ge) rev[++tot] = pl[i];
		sort(rev + 1, rev + tot + 1);
		for (int i = 1; i <= ge - tn; i++) {
			res -= rev[i];
		}
		cout << res << endl;
		cnt[1] = cnt[2] = cnt[3] = 0;
	}
}
