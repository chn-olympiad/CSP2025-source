#include <bits/stdc++.h>
using namespace std;
int T, n, ans1, ans2, ans3;

struct ren {
	int my1, my2, my3, bh, bm, b1, b2, b3; //my1、my2、my3分别为对三个部门满意度，bh为几号，bm为最终去向
	bool xc;//xc为选择情况
} a[10010];

bool cmp1(ren b, ren c) {
	return b.my1 > c.my1;
}

bool cmp2(ren b, ren c) {
	return b.my2 > c.my2;
}

bool cmp3(ren b, ren c) {
	return b.my3 > c.my3;
}

void fd(int p) {
	for (int i = 1; i <= n; i++) {
		if (a[i].bh == p) {
			a[i].my1 = -1;
			a[i].my2 = -1;
			a[i].my3 = -1;
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		ren x;
		int y = n / 2, ans = 0, t1 = 0, t2 = 0, t3 = 0;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].my1 >> a[j].my2 >> a[j].my3;
			a[j].bh = j;
			a[j].xc = 0;
			if (a[j].my2 == a[j].my3 && a[j].my2 == 0 && a[j].my3 == 0) {
				t1 += 1;
			} else if (a[j].my1 == a[j].my3 && a[j].my1 == 0 && a[j].my3 == 0) {
				t2 += 1;
			} else if (a[j].my1 == a[j].my2 && a[j].my1 == 0 && a[j].my2 == 0) {
				t3 += 1;
			}
		}
		if (t1 == n) {
			sort(a + 1, a + 1 + n, cmp1);
			for (int j = 1; j <= y; j++) {
				ans += a[j].my1;
			}
//			cout << "t1=0" << endl;
			cout << ans << endl;
		} else if (t2 == n) {
			sort(a + 1, a + 1 + n, cmp2);
			for (int j = 1; j <= y; j++) {
				ans += a[j].my2;
			}
//			cout << "t2=0" << endl;
			cout << ans << endl;
		} else if (t3 == n) {
			sort(a + 1, a + 1 + n, cmp3);
			for (int j = 1; j <= y; j++) {
				ans += a[j].my3;
			}
//			cout << "t3=0" << endl;
			cout << ans << endl;
		}//特判A特性
		else {
			for (int j = 1; j <= n; j++) {
				if (ans1 + ans2 + ans3 == n) {
					break;
				}//数量判断
				sort(a + 1, a + 1 + n, cmp1);
				x.my1 = a[1].my1;
				x.b1 = a[1].bh;
//				cout << x.b1 << " " << x.my1 << endl;
				sort(a + 1, a + 1 + n, cmp2);
				x.my2 = a[1].my2;
				x.b2 = a[1].bh;
//				cout << x.b2 << " " << x.my2 << endl;
				sort(a + 1, a + 1 + n, cmp3);
				x.my3 = a[1].my3;
				x.b3 = a[1].bh;
//				cout << x.b3 << " " << x.my3 << endl;
				if (x.b1 != x.b2 && x.b1 != x.b3 && x.b2 != x.b3) {
//					cout << x.my1 << " " << x.my2 << " " << x.my3 << " " << endl;
					ans += x.my1 + x.my2 + x.my3;
					ans1++;
					a[x.b1].xc = 1;
					fd(x.b1);
					a[x.b1].bm = 1;
					ans2++;
					a[x.b2].xc = 1;
					fd(x.b2);
					a[x.b2].bm = 2;
					ans3++;
					fd(x.b3);
					a[x.b3].bm = 3;
//					cout << a[x.b1].my1 << " " << a[x.b2].my2 << " " << a[x.b3].my3 << " " << endl;
				}//同时计入3个人进入三个部门
				else if (x.b1 == x.b2 && x.b1 != x.b3) {
					if (x.my1 >= x.my2) {
//						cout << x.my1 << " " << x.my3 << " " << endl;
						ans += x.my1 + x.my3;
						a[x.b1].xc = 1;
						fd(x.b1);
						a[x.b1].bm = 1;
						a[x.b3].xc = 1;
						fd(x.b3);
						a[x.b3].bm = 3;
						ans1++;
						ans3++;
//						cout << a[x.b1].my1 << " " << a[x.b3].my3 << " " << endl;
					} else {
//						cout << x.my2 << " " << x.my3 << " " << endl;
						ans += x.my2 + x.my3;
						a[x.b2].xc = 1;
						fd(x.b2);
						a[x.b2].bm = 2;
						a[x.b3].xc = 1;
						fd(x.b3);
						a[x.b3].bm = 3;
						ans2++;
						ans3++;
//						cout << a[x.b2].my2 << " " << a[x.b3].my3 << " " << endl;
					}
				} else if (x.b2 == x.b3 && x.b1 != x.b2) {
					if (x.my3 >= x.my2) {
//						cout << x.my1 << " " << x.my3 << " " << endl;
						ans += x.my1 + x.my3;
						a[x.b1].xc = 1;
						fd(x.b1);
						a[x.b1].bm = 1;
						a[x.b3].xc = 1;
						fd(x.b3);
						a[x.b3].bm = 3;
						ans1++;
						ans3++;
//						cout << a[x.b1].my1 << " " << a[x.b3].my3 << " " << endl;
					} else {
//						cout << x.my1 << " " << x.my2 << " " << endl;
						ans += x.my2 + x.my1;
						a[x.b1].xc = 1;
						fd(x.b1);
						a[x.b1].bm = 1;
						a[x.b2].xc = 1;
						fd(x.b2);
						a[x.b2].bm = 2;
						ans1++;
						ans2++;
//						cout << a[x.b1].my1 << " " << a[x.b2].my2 << " " << endl;
					}
				} else if (x.b1 == x.b3 && x.b1 != x.b2) {
					if (x.my1 >= x.my3) {
//						cout << x.my1 << " " << x.my2 << " " << endl;
						ans += x.my1 + x.my2;
						a[x.b1].xc = 1;
						fd(x.b1);
						a[x.b1].bm = 1;
						a[x.b2].xc = 1;
						fd(x.b2);
						a[x.b2].bm = 2;
						ans1++;
						ans2++;
//						cout << a[x.b1].my1 << " " << a[x.b2].my2 << " " << endl;
					} else {
//						cout << x.my2 << " " << x.my3 << " " << endl;
						ans += x.my2 + x.my3;
						a[x.b2].xc = 1;
						fd(x.b2);
						a[x.b2].bm = 2;
						a[x.b3].xc = 1;
						fd(x.b3);
						a[x.b3].bm = 3;
						ans2++;
						ans3++;
//						cout << a[x.b2].my2 << " " << a[x.b3].my3 << " " << endl;
					}
				} else if (x.b1 == x.b2 && x.b1 == x.b3) {
					if (x.my1 >= x.my2) {
						if (x.my1 >= x.my3) {
//							cout << x.my1 << " " << endl;
							ans += x.my1;
							a[x.b1].xc = 1;
							fd(x.b1);
							a[x.b1].bm = 1;
							ans1++;
//							cout << a[x.b1].my1 << " " << endl;
						} else {
//							cout << x.my3 << " " << endl;
							ans += x.my3;
							a[x.b3].xc = 1;
							fd(x.b3);
							a[x.b3].bm = 3;
							ans3++;
//							cout << a[x.b3].my3 << " " << endl;
						}//my3最大
					} else {
						if (x.my2 >= x.my3) {
//							cout << x.my2 << " " << endl;
							ans += x.my2;
							a[x.b2].xc = 1;
							fd(x.b2);
							a[x.b2].bm = 2;
							ans2++;
//							cout << a[x.b2].my2 << " " << endl;
						}//my2最大
						else {
//							cout << x.my3 << " " << endl;
							ans += x.my3;
							a[x.b3].xc = 1;
							fd(x.b3);
							a[x.b3].bm = 3;
							ans3++;
//							cout << a[x.b3].my3 << " " << endl;
						}//my3最大
					}//my1比my2小
				}//一个人进一个部门
			}
			cout << endl;
			cout << ans << endl;
		}
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
