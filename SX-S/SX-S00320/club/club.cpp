#include <bits/stdc++.h>
using namespace std;
int t, n, ans, s[1000005][3];

//
//struct dat {
//	int a, b, c;
//} s[100005];

//bool cmp(dat xx, dat yy) {
//	return xx.a < yy.a;
//}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 0; i <= t; i++) {
		ans = 0;
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> s[j][0] >> s[j][1] >> s[j][2];
		for (int j = 0; j < n; j++) {

			ans += max(max(s[j][0], s[j][1]), s[j][2]);

		}
		cout << ans<<endl;
	}

//	cin >> t;
//	for (int qi = 1; qi <= t; qi++) {
//		cin >> n;
//		int qw1[n], qw2[n], qw3[n];
//		int hh1 = 1, hh2 = 1, hh3 = 1, top1 = 1, top2 = 1, top3 = 1;
//		int maxxa = n / 2, maxxb = n / 2, maxxc = n / 2;
//		for (int i = 1; i <= n; i++) {
//			cin >> s[i].a >> s[i].b >> s[i].c;
//		}
//		sort(s + 1, s + n + 1, cmp);
//		for (int i = 1; i <= n; i++) {
//			if (s[i].a > s[i].b && s[i].a > s[i].c) {
//				if (maxxa) {
//					ans += s[i].a;
//					maxxa--;
//					qw1[top1] = s[i].a;
//					top1++;
//				} else if (qw1[hh1] + max(s[i].b, s[i].c) < s[i].a) {
//					if (s[i].b > s[i].c) {
//						qw2[++top2] = s[i].b;
//						maxxb--;
//					} else {
//						qw3[++top3] = s[i].c;
//						maxxc--;
//					}
//					hh1++;
//				} else {
//					ans = ans - qw1[hh1] + max(s[qw1[hh1]].b, s[qw1[hh1]].c);
//					if (qw2[hh2] > qw3[hh3]) {
//						maxxb--;
//						qw2[top2] = s[qw1[hh1]].b;
//					} else {
//						maxxc--;
//						qw3[top3] = s[qw1[hh1]].c;
//					}
//				}
//			}//
//			else if (s[i].c > s[i].b && s[i].c > s[i].a ) {
//				ans += s[i].c;
//				maxxc--;
//				qw3[top3] = s[i].c;
//				top3++;
//				if (qw3[hh3] + max(s[i].b, s[i].a) < s[i].c) {
//					if (s[i].b > s[i].a) {
//						qw2[++top2] = s[i].b;
//						maxxb--;
//					} else {
//						qw1[++top1] = s[i].a;
//						maxxa--;
//					}
//					hh3++;
//				} else {
//					ans = ans - qw3[hh3] + max(s[qw3[hh3]].a, s[qw3[hh3]].b);
//					if (qw2[hh3] > qw1[hh3]) {
//						maxxb--;
//						qw2[top2] = s[qw3[hh3]].b;
//					} else {
//						maxxa--;
//						qw1[top1] = s[qw3[hh3]].a;
//					}
//				}
//			}
//			//
//			else if (s[i].b > s[i].a && s[i].b > s[i].c ) {
//				ans += s[i].b;
//				maxxb--;
//				qw2[top2] = s[i].b;
//				top2++;
//				if (qw2[hh2] + max(s[i].a, s[i].c) < s[i].b) {
//					if (s[i].a > s[i].c) {
//						qw1[++top1] = s[i].a;
//						maxxa--;
//					} else {
//						qw3[++top3] = s[i].c;
//						maxxc--;
//					}
//					hh2++;
//				} else {
//					ans = ans - qw2[hh2] + max(s[qw2[hh2]].a, s[qw2[hh2]].c);
//					if (qw1[hh1] > qw3[hh3]) {
//						maxxa--;
//						qw1[top1] = s[qw2[hh2]].a;
//					} else {
//						maxxc--;
//						qw3[top3] = s[qw2[hh2]].c;
//					}
//				}
//			}//
//			if (s[i].b == s[i].c == s[i].a )
//				ans += s[i].b;
//			if (s[i].b == s[i].a) {
//				if (s[i].c > s[i].b) {
//					qw3[++top3] = s[i].c;
//					maxxc--;
//				}
//			}
//if (s[i].b == s[i].c) {
//				if (s[i].a > s[i].b) {
//					qw1[++top1] = s[i].a;
//					maxxa--;
//				}
//			}
//			if (s[i].b == s[i].a) {
//				if (s[i].b > s[i].a) {
//					qw2[++top2] = s[i].b;
//					maxxb--;
//				}
//			}
//		}
//		}
//		cout << ans;
//		ans = 0;
//	}
	return 0;
}

