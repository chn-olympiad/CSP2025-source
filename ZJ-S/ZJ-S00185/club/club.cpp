#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 11;
int T , n;
ll ans , a[N][4];
struct Info {
	int id , v;
}p1[N] , p2[N] , p3[N];

inline bool cmp1(Info x , Info y) {
	int idx1 = x.id , idx2 = y.id;
	ll smx = max(a[idx1][2] , a[idx1][3]) , smy = max(a[idx2][2] , a[idx2][3]);
	return a[idx1][1] - smx > a[idx2][1] - smy;
}

inline bool cmp2(Info x , Info y) {
	int idx1 = x.id , idx2 = y.id;
	ll smx = max(a[idx1][1] , a[idx1][3]) , smy = max(a[idx2][1] , a[idx2][3]);
	return a[idx1][2] - smx > a[idx2][2] - smy;
}

inline bool cmp3(Info x , Info y) {
	int idx1 = x.id , idx2 = y.id;
	ll smx = max(a[idx1][1] , a[idx1][2]) , smy = max(a[idx2][1] , a[idx2][2]);
	return a[idx1][3] - smx > a[idx2][3] - smy;
}
int main () {
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	scanf ("%d" , &T);
	while (T--) {
		scanf ("%d" , &n);
		for (int i = 1;i <= n;i++) for (int j = 1;j <= 3;j++) scanf ("%lld" , &a[i][j]);
		int cnt1 = 0 , cnt2 = 0 , cnt3 = 0;
		for (int i = 1;i <= n;i++) {
			ll x = max(a[i][1] , max(a[i][2] , a[i][3]));
			if (x == a[i][1]) {
				p1[++cnt1].v = a[i][1] , p1[cnt1].id = i;				
			} else if (x == a[i][2]) {
				p2[++cnt2].v = a[i][2] , p2[cnt2].id = i;
			} else {
				p3[++cnt3].v = a[i][3] , p3[cnt3].id = i;
			}
		}
		sort (p1 + 1 , p1 + cnt1 + 1 , cmp1);
		sort (p2 + 1 , p2 + cnt2 + 1 , cmp2);
		sort (p3 + 1 , p3 + cnt3 + 1 , cmp3);
		for (int i = cnt1;i >= n / 2 + 1;i--) {
			int idx = p1[i].id;
			if (a[idx][2] > a[idx][3]) p2[++cnt2].v = a[idx][2] , p2[cnt2].id = idx;
			else p3[++cnt3].v = a[idx][3] , p3[cnt3].id = idx;
			cnt1--;
		}
		sort (p2 + 1 , p2 + cnt2 + 1 , cmp2);
		sort (p3 + 1 , p3 + cnt3 + 1 , cmp3);
		for (int i = cnt2;i >= n / 2 + 1;i--) {
			int idx = p2[i].id;
			if (a[idx][1] > a[idx][3]) p1[++cnt1].v = a[idx][1] , p1[cnt1].id = idx;
			else p3[++cnt3].v = a[idx][3] , p3[cnt3].id = idx;
			cnt2--;
		}
		sort (p1 + 1 , p1 + cnt1 + 1 , cmp1);
		sort (p3 + 1 , p3 + cnt3 + 1 , cmp3);
		for (int i = cnt3;i >= n / 2 + 1;i--) {
			int idx = p3[i].id;
			if (a[idx][1] > a[idx][2]) p1[++cnt1].v = a[idx][1] , p1[cnt1].id = idx;
			else p2[++cnt2].v = a[idx][2] , p2[cnt2].id = idx;
			cnt3--;
		}
		ll ans = 0;
		for (int i = 1;i <= cnt1;i++) ans += p1[i].v;
		for (int i = 1;i <= cnt2;i++) ans += p2[i].v;
		for (int i = 1;i <= cnt3;i++) ans += p3[i].v;
		printf ("%lld\n" , ans);
	}
	return 0;
}