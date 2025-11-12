#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
int maxn = INT_MIN, num;

int t, n, top;

//int ls[4], s[20005];
//int p[100005], last[100005];
//int b1, b2, b3;
//
//struct node {
//	int f, s, t;
//	int fid, sid, tid;
//} a[100005];

//暴力搜索（顶死10分）
void dfs(int step, int t1, int t2, int t3) {
	if (step > n) {
		maxn = max(maxn, num);
		return;
	}
//	for (int i = 1; i <= 3; i++) {
//		num += a[step][i];
//		if (i == 1) {
//			if (t1 < top) {
//				dfs(step + 1, t1 + 1, t2, t3);
//			}
//		} else if (i == 2) {
//			if (t2 < top) {
//				dfs(step + 1, t1, t2 + 1, t3);
//			}
//		} else if (i == 3) {
//			if (t3 < top) {
//				dfs(step + 1, t1, t2, t3 + 1);
//			}
//		}
//		num -= a[step][i];
//	}

	if (t1 < top) {
		num += a[step][1];
		dfs(step + 1, t1 + 1, t2, t3);
		num -= a[step][1];
	}
	if (t2 < top) {
		num += a[step][2];
		dfs(step + 1, t1, t2 + 1, t3);
		num -= a[step][2];
	}
	if (t3 < top) {
		num += a[step][3];
		dfs(step + 1, t1, t2, t3 + 1);
		num -= a[step][3];
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		top = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		}
		maxn = INT_MIN, num = 0;
		dfs(1, 0, 0, 0);
		printf("%d\n", maxn);
	}
//反悔贪心（失败）
//	while (t--) {
//		scanf("%d", &n);
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= 3; j++) {
//				scanf("%d", &ls[j]);
//				s[ls[j]] = j;
//			}
//			sort(ls + 1, ls + 3 + 1);
//			a[i].t = ls[1];
//			a[i].tid = s[ls[1]];
//			a[i].s = ls[2];
//			a[i].sid = s[ls[2]];
//			a[i].f = ls[3];
//			a[i].fid = s[ls[3]];
//		}
////		for (int i = 1; i <= n; i++) {
////			cout << a[i].t << " " << a[i].s << " " << a[i].f << endl;
////			cout << a[i].tid << " " << a[i].sid << " " << a[i].fid << endl;
////		}
//		int flag = 0, t = 0;
//		while (1) {
//			t++;
//			if (t > n) {
//				break;
//			}
//			if (flag == 0) {
//				p[t] = a[t].f;
//				last[t] = p[t];
//				if (a[t].fid == 1) {
//					b1++;
//					if (b1 > top) {
//						if (a[t].f > last[t - 1]) {
//							t--;
//							flag = 1;
//							continue;
//						}
//					}
//				}
//				if (a[t].fid == 2) {
//					b2++;
//					if (b2 > top) {
//						if (a[t].f > last[t - 1]) {
//							t--;
//							flag = 1;
//							continue;
//						}
//					}
//				}
//				if (a[t].fid == 3) {
//					b3++;
//					if (b3 > top) {
//						if (a[t].f > last[t - 1]) {
//							t--;
//							flag = 1;
//							continue;
//						}
//					}
//				}
//			}
//			if (flag == 1) {
//				p[t] = a[t].s;
//				last[t] = p[t];
//				if (a[t].sid == 1) {
//					b1++;
//					if (b1 > top) {
//						if (a[t].s > last[t - 1]) {
//							t--;
//							flag = 2;
//							continue;
//						}
//					}
//				}
//				if (a[t].sid == 2) {
//					b2++;
//					if (b2 > top) {
//						if (a[t].s > last[t - 1]) {
//							t--;
//							flag = 2;
//							continue;
//						}
//					}
//				}
//				if (a[t].sid == 3) {
//					b3++;
//					if (b3 > top) {
//						if (a[t].s > last[t - 1]) {
//							t--;
//							flag = 2;
//							continue;
//						}
//					}
//				}
//			}
////			cout << t << endl;
//			if (flag == 2) {
//				p[t] = a[t].t;
//				last[t] = p[t];
//				if (a[t].tid == 1) {
//					b1++;
////					if (b1 > top) {
////						if (a[t].t > last[t - 1]) {
////							t--;
////							flag = 0;
////							continue;
////						}
////					}
//				}
//				if (a[t].tid == 2) {
//					b2++;
////					if (b2 > top) {
////						if (a[t].t > last[t - 1]) {
////							t--;
////							flag = 0;
////							continue;
////						}
////					}
//				}
//				if (a[t].tid == 3) {
//					b3++;
////					if (b3 > top) {
////						if (a[t].t > last[t - 1]) {
////							t--;
////							flag = 0;
////							continue;
////						}
////					}
//				}
//			}
//		}
//		int num = 0;
//		for (int i = 1; i <= n; i++) {
//			cout << p[i] << " ";
//			num += p[i];
//		}
//		cout << endl;
//		printf("%d\n", num);
//	}
	return 0;
}
//我尽力了，于我而言，没有遗憾
//有缘再见，信奥