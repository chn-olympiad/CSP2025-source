#include <bits/stdc++.h>
using namespace std;
//const int N = 1e5 + 10;
//struct memb {
//	int id;
//	int a, b, c;
//};
//memb p[N];
//bool cnt[N];
//bool cmp1(memb A, memb B) {
//	int flag1 = cnt[A.id], flag2 = cnt[B.id];
//	if (flag1 && flag2) {
//		return false; 
//	}
//	if (flag1 && !flag2) {
//		return true;
//	}
//	if (!flag1 && flag2) {
//		return false;
//	}
//	int bf1 = ((int)(A.a == 0) + (int)(A.b == 0) + (int)(A.c == 0)), bf2 = ((int)(B.a == 0) + (int)(B.b == 0) + (int)(B.c == 0));
////	cout << "BF: " << bf1 << ' ' << bf2 << '\n';
//	if (bf1 != bf2) {
//		return bf1 > bf2;
//	}
//	return A.a > B.a;
//}
//bool cmp2(memb A, memb B) {
//	int flag1 = cnt[A.id], flag2 = cnt[B.id];
//	if (flag1 && flag2) {
//		return false; 
//	}
//	if (flag1 && !flag2) {
//		return true;
//	}
//	if (!flag1 && flag2) {
//		return false;
//	}
//	int bf1 = ((int)(A.a == 0) + (int)(A.b == 0) + (int)(A.c == 0)), bf2 = ((int)(B.a == 0) + (int)(B.b == 0) + (int)(B.c == 0));
//	if (bf1 == bf2) {
//		return bf1 > bf2;
//	}
//	return A.b > B.b;
//}
//bool cmp3(memb A, memb B) {
//	int flag1 = cnt[A.id], flag2 = cnt[B.id];
//	if (flag1 && flag2) {
//		return false; 
//	}
//	if (flag1 && !flag2) {
//		return true;
//	}
//	if (!flag1 && flag2) {
//		return false;
//	}
//	int bf1 = ((int)(A.a == 0) + (int)(A.b == 0) + (int)(A.c == 0)), bf2 = ((int)(B.a == 0) + (int)(B.b == 0) + (int)(B.c == 0));
//	if (bf1 == bf2) {
//		return bf1 > bf2;
//	}
//	return A.c > B.c;
//}
//int get_club(int num, int id) {
//	if (num == p[id].a) {
//		return 1;
//	}
//	if (num == p[id].b) {
//		return 2;
//	}
//	if (num == p[id].c) {
//		return 3;
//	}
//}
//bool check(int num, int c1, int c2, int c3, int n) {
//	if (num == 1) {
//		return c1 < n / 2;
//	}
//	if (num == 2) {
//		return c2 < n / 2;
//	}
//	if (num == 3) {
//		return c3 < n / 2;
//	}
//}
//void add_club(int num, int & c1, int & c2, int & c3) {
//	if (num == 1) {
//		c1++;
//	}
//	if (num == 2) {
//		c2++;
//	}
//	if (num == 3) {
//		c3++;
//	}
//}
//// d0
//void show_cnt(int n) {
//	for (int i = 1; i <= n; i++) {
//		int val = (cnt[i] == true ? 1 : 0);
//		cout << val<< ' ';
//	}	
//}
//// d0
//void solve() {
//	int n;
//	cin >> n;
//	int ans = 0;
//	int c1, c2, c3;
//	c1 = c2 = c3 = 0;
//	for (int i = 1; i <= n; i++) {
//		p[i].id = i;
//		cnt[i] = false;
//		cin >> p[i].a >> p[i].b >> p[i].c;
//	}
//	sort(p + 1, p + n + 1, cmp1);
////	cout << "PID: " << p[1].id << " " << p[2].id << '\n';
//	for (int i = 1; i <= n; i++) {
//		int mx = max(p[i].a, max(p[i].b, p[i].c));
//		if (mx == p[i].a) {
////			cout << "Used: " << p[i].a << ' ' << p[i].b << ' ' << p[i].c <<  "  by: " << 1 << '\n';
//			c1++;
//			ans += mx;
//			cnt[p[i].id] = true;
//			if (c1 == n / 2) {
//				break;
//			}
//		}
//	}
//	sort(p + 1, p + n + 1, cmp2);
//	for (int i = 1; i <= n; i++) {
//		int mx = max(p[i].a, max(p[i].b, p[i].c));
//		if (mx == p[i].b) {
////			cout << "Used: " << p[i].a << ' ' << p[i].b << ' ' << p[i].c << "  by: " << 2 << '\n';
//			c2++;
////			cout << "C2: " << c2 << ' ' << '\n';
//			ans += mx;
//			cnt[p[i].id] = true;
//			if (c2 == n / 2) {
//				break;
//			}
//		}
//	}
//	sort(p + 1, p + n + 1, cmp3);
//	for (int i = 1; i <= n; i++) {
//		int mx = max(p[i].a, max(p[i].b, p[i].c));
//		if (mx == p[i].c) {
////			cout << "Used: " << p[i].a << ' ' << p[i].b << ' ' << p[i].c <<  "  by: " << 3 << '\n';
//			c3++;
//			ans += mx;
//			cnt[p[i].id] = true;
//			if (c3 == n / 2) {
//				break;
//			}
//		}
//	}
//	// 0
////	show_cnt(n);
//	// 0
//	for (int i = 1; i <= n; i++) {
//		if (cnt[p[i].id] == false) {
//			int lar = max(p[i].a, max(p[i].b, p[i].c));
//			int sma = min(p[i].a, min(p[i].b, p[i].c));
//			int mid = (p[i].a + p[i].b + p[i].c) - (lar + sma);
//			int larc = get_club(lar, i);
//			int smac = get_club(sma, i);
//			int midc = get_club(mid, i);
//			if (check(larc, c1, c2, c3, n)) {
//				ans += lar;
//				add_club(larc, c1, c2, c3);
//				cnt[p[i].id] = true;
//			}
//			else if (check(midc, c1, c2, c3, n)) {
//				ans += mid;
//				add_club(midc, c1, c2, c3);
//				cnt[p[i].id] = true;
//			}
//			else if (check(smac, c1, c2, c3, n)) {
//				ans += sma;
//				add_club(smac, c1, c2, c3);
//				cnt[p[i].id] = true;
//			}
//		}
//	}
//	cout << ans << '\n';
//}
const int N = 1e5 + 10;
int memb[N][10];
int ans = 0;
void dfs(int u, int tot, int c1, int c2, int c3, const int n) {
	if (u > n) {
		if (c1 <= n / 2 && c2 <= n / 2 && c3 <= n / 2) {
			ans = max(ans, tot);
			return ;
		}
		else {
			return ;
		}
	}
	if (c1 < n / 2) {
		dfs(u + 1, tot + memb[u][1], c1 + 1, c2, c3, n);
	}
	if (c2 < n / 2) {
		dfs(u + 1, tot + memb[u][2], c1, c2 + 1, c3, n);
	}
	if (c3 < n / 2) {
		dfs(u + 1, tot + memb[u][3], c1, c2, c3 + 1, n);
	}
	
}
void solve() {
	int n;
	cin >> n;
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> memb[i][1] >> memb[i][2] >> memb[i][3];
	}
	dfs(1, 0, 0, 0, 0, n);
	cout << ans << '\n';
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
} 