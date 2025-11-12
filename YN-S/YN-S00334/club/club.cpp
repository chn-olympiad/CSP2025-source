#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t;

struct str {
	LL a1, a2, a3, id, used;
} a[101000];
LL m1[50500], m2[50500], m3[50500];
map<LL, LL> mp1, mp2, mp3;

LL read() {
	LL num = 0;
	char ch = getchar();
	while (ch > '9' || ch < '0')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		(num *= 10) += LL(ch - '0'), ch = getchar();
	return num;
}

void write(LL num) {
	if (num < 0)
		putchar('-');
	if (num > 9)
		write(num / 10);
	putchar(num % 10 + 48);
}

struct SS {
	LL val, ID;
	friend bool operator <(SS A, SS B) {
		return A.val < B.val;
	}
} md[100100];

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = read();
//	write(t);
	while (t--) {
		LL Ccnt = 0, n, ll = 0, k1 = 0, k2 = 0, k3 = 0;
		memset(md, 0, sizeof md);
		memset(m1, 0, sizeof m1);
		memset(m2, 0, sizeof m2);
		memset(m3, 0, sizeof m3);
		memset(a, 0, sizeof a);
		mp1.clear(), mp2.clear(), mp3.clear();
		n = read();
		for (LL i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].id = i;
			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) {
				a[i].used = 1;
				k1++;
				m1[k1] = i;
				mp1[a[i].id] = k1;
			} else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3) {
				a[i].used = 2;
				k2++;
				m2[k2] = i;
				mp2[a[i].id] = k2;
			} else {
				a[i].used = 3;
				k3++;
				m3[k3] = i;
				mp3[a[i].id] = k3;
			}
		}
//		for (LL i = 1; i <= n; i++) {
//			cout << a[i].used << endl;
//		}
		for (LL www = 1; www <= 2; www++) {
			ll = 0;
			if (k1 > n / 2) {
				for (LL i = 1; i <= k1; i++) {
					md[++ll].val = a[m1[i]].a1 - max(a[m1[i]].a3, a[m1[i]].a2);
					md[ll].ID = i;
				}
				sort(md + 1, md + 1 + ll);
				for (LL i = 1; i <= ll; i++) {
					if (k1 <= n / 2)
						break;
					if (a[m1[md[i].ID]].a1 - a[m1[md[i].ID]].a3 == md[i].val) {
						if (k3 < n / 2) {
							a[m1[md[i].ID]].used = 3;
							m1[mp1[a[m1[md[i].ID]].id]] = -1;
							mp1[a[m1[md[i].ID]].id] = 0;
							k1--;
							k3++;
						}
					} else if (k2 < n / 2) {
						a[m1[md[i].ID]].used = 2;
						m1[mp1[a[m1[md[i].ID]].id]] = -1;
						mp1[a[m1[md[i].ID]].id] = 0;
						k1--;
						k2++;
					}
				}
			}
			if (k2 > n / 2) {
				for (LL i = 1; i <= k2; i++) {
					md[++ll].val = a[m2[i]].a2 - max(a[m2[i]].a1, a[m2[i]].a3);
					md[ll].ID = i;
				}
//				cout << k2 << endl;
				sort(md + 1, md + 1 + ll);
//				for (LL i = 1; i <= k2 * 2; i++) {
//					cout << md[i].ID << ' ' << md[i].val << endl;
//				}
				for (LL i = 1; i <= ll; i++) {
					if (k2 <= n / 2)
						break;
					if (a[m2[md[i].ID]].a2 - a[m2[md[i].ID]].a3 == md[i].val) {
						if (k3 < n / 2) {
							a[m2[md[i].ID]].used = 3;
							m2[mp2[a[m2[md[i].ID]].id]] = -1;
							mp2[a[m2[md[i].ID]].id] = 0;
							k2--;
							k3++;
						}
					} else if (k1 < n / 2) {
						a[m2[md[i].ID]].used = 1;
						m2[mp2[a[m2[md[i].ID]].id]] = -1;
						mp2[a[m2[md[i].ID]].id] = 0;
						k2--;
						k1++;
					}
				}
//				cout << "gfgdsfgfsdg" << endl;
			}
			if (k3 > n / 2) {
				for (LL i = 1; i <= k3; i++) {
					md[++ll].val = a[m3[i]].a3 - max(a[m3[i]].a1, a[m3[i]].a2);
					md[ll].ID = i;
				}
				sort(md + 1, md + 1 + ll);
				for (LL i = 1; i <= ll; i++) {
					if (k3 <= n / 2)
						break;
					if (a[m3[md[i].ID]].a3 - a[m3[md[i].ID]].a1 == md[i].val) {
						if (k1 < n / 2) {
							a[m3[md[i].ID]].used = 1;
							m2[mp3[a[m3[md[i].ID]].id]] = -1;
							mp3[a[m3[md[i].ID]].id] = 0;
							k3--;
							k1++;
						}
					} else if (k2 < n / 2) {
						a[m3[md[i].ID]].used = 2;
						m3[mp3[a[m3[md[i].ID]].id]] = -1;
						mp3[a[m3[md[i].ID]].id] = 0;
						k3--;
						k2++;
					}
				}
			}
		}
		for (LL i = 1; i <= n; i++) {
			if (a[i].used == 1) {
				Ccnt += a[i].a1;
			} else if (a[i].used == 2) {
				Ccnt += a[i].a2;
			} else {
				Ccnt += a[i].a3;
			}
		}
		cout << Ccnt << endl;
	}
	return 0;
}/*

*/