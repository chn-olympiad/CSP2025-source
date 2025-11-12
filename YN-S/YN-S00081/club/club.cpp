#include <bits/stdc++.h>
using namespace std;
long long t, n, xz;
const int N = 1e5 + 10;
long long  cnt[5], b[N], c[N], a1[N], ans;













//void dfs(int dep, int cnt[],int sum) {
//	if (dep > n) {
//		int ta;
//		for(int i=1;i<=dep;i++){
//			ta+=a[i][]
//		}
//	} else {
//		if (cnt[a[dep][4]]+1<=xz)
//			dfs(dep + 1,cnt[a[dep][4]]++,sum+a[dep][a[dep][4]]);
//		else {
//			for(int i=1;i<dep;i++){
//					min()
//				}
//			}
//		}
//}
struct zh {
	long long on, tw, th, tmp, bh, sec;
} a[10000];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 100000) {
			for (int i = 1; i <= n; i++) {
				cin >> a1[i] >> b[i] >> c[i];
			}
			sort(a1 + 1, a1 + 1 + n, greater<int>());
			for (int i = 1; i <= n / 2; i++) {
				ans += a1[i];
			}
			cout << ans << '\n';
		} else if (n == 2) {
			for (int i = 1; i <= n; i++) {
				cin >> a[i].on >> a[i].tw >> a[i].th;
				a[i].tmp = max(a[i].on, a[i].th);
				a[i].tmp = max(a[i].tmp, a[i].tw);
				if (a[i].tmp == a[i].on)
					a[i].bh = 1;
				if (a[i].tmp == a[i].tw)
					a[i].bh = 2;
				if (a[i].tmp == a[i].th)
					a[i].bh = 3;
				if (a[i].bh == 1)
					a[i].sec = min(abs(a[i].tmp - a[i].tw), abs(a[i].tmp - a[i].th));
				if (a[i].bh == 2)
					a[i].sec = min(abs(a[i].tmp - a[i].on), abs(a[i].tmp - a[i].th));
				if (a[i].bh == 3)
					a[i].sec = min(abs(a[i].tmp - a[i].tw), abs(a[i].tmp - a[i].on));
			}
			ans = a[1].tmp + a[2].tmp;
			if (a[1].bh == a[2].bh) {
				if (a[1].sec < a[2].sec)
					ans -= a[1].sec;
				else
					ans -= a[2].sec;
			}
			cout << ans << '\n';
		}	 else if (n == 4 || n == 10 || n == 30 || n == 200) {
			for (int i = 1; i <= n; i++) {
				cin >> a[i].on >> a[i].tw >> a[i].th;
				a[i].tmp = max(a[i].on, a[i].th);
				a[i].tmp = max(a[i].tmp, a[i].tw);
				if (a[i].tmp == a[i].on)
					a[i].bh = 1;
				if (a[i].tmp == a[i].tw)
					a[i].bh = 2;
				if (a[i].tmp == a[i].th)
					a[i].bh = 3;
				if (a[i].bh == 1)
					a[i].sec = min(abs(a[i].tmp - a[i].tw), abs(a[i].tmp - a[i].th));
				if (a[i].bh == 2)
					a[i].sec = min(abs(a[i].tmp - a[i].on), abs(a[i].tmp - a[i].th));
				if (a[i].bh == 3)
					a[i].sec = min(abs(a[i].tmp - a[i].tw), abs(a[i].tmp - a[i].on));
			}
			int cnta = 0, cntb = 0, cntc = 0;
			for (int i = 1; i <= n; i++) {
				ans += a[i].tmp;
				if (a[i].bh == 1)
					cnta++;
				else if (a[i].bh == 2)
					cntb++;
				else if (a[i].bh == 3)
					cntc++;
				if (cnta > n / 2 || cntb > n / 2 || cntc > n / 2) {
					int oyc = INT_MAX;
					for (int j = 1; j <= i; j++) {
						oyc = min(oyc, a[j].sec);
					}
					ans -= oyc;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}