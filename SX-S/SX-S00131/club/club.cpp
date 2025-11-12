#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, n, maxn, numa, numb, numc, flag, ans, zty1, zty2, sc, sb, ans1, ans2;
ll acl[5005], bcl[5005], ccl[5005], secsort[5005], second[5005], ztyzty[5005];

struct node {
	ll a, b, c;
} per[100010];

int qread() {
	char c = getchar();
	int x = 0, f = 1;
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

void qwrite(int nn) {
	if (nn >= 10) {
		qwrite(nn / 10);
	}
	putchar(nn % 10 + '0');
}

int cmpa(int aa, int bb) {
	return per[aa].a < per[bb].a;
}

int cmpb(int aa, int bb) {
	return per[aa].b < per[bb].b;
}

int cmpc(int aa, int bb) {
	return per[aa].c < per[bb].c;
}

int findsec(int ff) {	//找第二大的元素
	int mmax = max(per[ff].a, max(per[ff].b, per[ff].c));
	int mmin = min(per[ff].a, min(per[ff].b, per[ff].c));
	int aa = 1, bb = 2, cc = 3;
	if (mmax == per[ff].a)
		aa = 0;
	else if (mmax == per[ff].b)
		bb = 0;
	else if (mmax == per[ff].c)
		cc = 0;
	if (mmin == per[ff].a && aa == 1)
		aa = 0;
	else if (mmin == per[ff].b && bb == 2)
		bb = 0;
	else if (mmin == per[ff].c && cc == 3)
		cc = 0;
	if (aa == 1)
		return aa;
	else if (bb == 2)
		return bb;
	else if (cc == 3)
		return cc;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t = qread();
	while (t--) {
		flag = 0;
		ans = 0;
		ans1 = 0;
		ans2 = 0;
		numa = 0;
		numb = 0;
		numc = 0;
		sb = 0;
		sc = 0;
		memset(acl, 0, sizeof(acl));
		memset(bcl, 0, sizeof(bcl));
		memset(ccl, 0, sizeof(ccl));
		memset(per, 0, sizeof(per));
		n = qread();
		for (int i = 1; i <= n; i++) {
			per[i].a = qread();
			per[i].b = qread();
			per[i].c = qread();
			if (per[i].b != 0)
				sb = 1;
			if (per[i].c != 0)
				sc = 1;
			ztyzty[i] = i;
		}
		if (sb == 0 && sc == 0) {
			sort(ztyzty + 1, ztyzty + 1 + n, cmpa);
			for (int i = n; i >= n / 2; i--)
				ans += per[ztyzty[i]].a;
			qwrite(ans);
			cout << endl;
			continue;
		} else if (sb != 0 && sc == 0) {
			sort(ztyzty + 1, ztyzty + 1 + n, cmpa);
			for (int i = n; i > n / 2; i--)
				ans1 += per[ztyzty[i]].a;
			for (int i = 1; i <= n / 2; i++) {
				ans1 += per[ztyzty[i]].b;
			}
			sort(ztyzty + 1, ztyzty + 1 + n, cmpb);
			for (int i = n; i > n / 2; i--)
				ans2 += per[ztyzty[i]].b;
			for (int i = 1; i <= n / 2; i++) {
				ans2 += per[ztyzty[i]].a;
			}
			ans = max(ans1, ans2);
			qwrite(ans);
			cout << endl;
			continue;
		} else {
			for (int i = 1; i <= n; i++) {
				maxn = max(per[i].a, max(per[i].b, per[i].c));
				if (maxn == per[i].a) {
					numa++;
					acl[numa] = i;
					//cout << i << " ";
				}

				else if (maxn == per[i].b) {
					numb++;
					bcl[numb] = i;


				} else if (maxn = per[i].c) {
					numc++;
					ccl[numc] = i;
				}
			}//初步分组
			int abcmax = max(numa, max(numb, numc));

			while (1) {
				if (flag != 0)
					break;
				if (abcmax == numa && flag == 0) {	//deal a

					if (numa <= (n / 2)) {
						flag = 4;

					} else {
						sort(acl + 1, acl + numa +  1, cmpa);
						for (int i = 1; i <= numa - n / 2; i++) {
							if (findsec(acl[i]) == 2) {
								numb++;
								bcl[numb] = acl[i];
							} else if (findsec(acl[i]) == 3) {
								numc++;
								ccl[numc] = acl[i];
							}
						}
						flag = 1;
					}
				}
				if (abcmax == numb && flag == 0) {	//deal b
					if (numb <= n / 2)
						flag = 4;
					else {
						sort(bcl + 1, bcl + numb + 1, cmpb);
						for (int i = 1; i <= numb - n / 2; i++) {
							if (findsec(bcl[i]) == 1) {
								numa++;
								acl[numa] = bcl[i];
							} else if (findsec(bcl[i]) == 3) {
								numc++;
								ccl[numc] = bcl[i];
							}
						}
						flag = 2;
					}
				}
				if (abcmax == numc && flag == 0) {	//deal c
					if (numc <= n / 2)
						flag = 4;
					else {
						sort(ccl + 1, ccl + numc + 1, cmpc);
						for (int i = 1; i <= numc - n / 2; i++) {
							if (findsec(ccl[i]) == 2) {
								numb++;
								bcl[numb] = ccl[i];
							} else if (findsec(ccl[i]) == 1) {
								numa++;
								ccl[numa] = ccl[i];
							}
						}
						flag = 3;
					}
				}
			}// 处理a的话flag=1，b的话flag=2，c的话flag=3，无需处理的话flag=4
			if (flag == 1) {
				for (int i = numa - n / 2 + 1; i <= numa; i++)
					ans += per[acl[i]].a;
				for (int i = 1; i <= numb; i++)
					ans += per[bcl[i]].b;
				for (int i = 1; i <= numc; i++)
					ans += per[ccl[i]].c;
				/*	for (int i = 1; i <= numa; i++) {
						if (findsec(acl[i]) == 1) {
							second[acl[i]] = per[acl[i]].a;
							secsort[acl[i]] = second[i];
						} else if (findsec(acl[i]) == 2) {
							second[acl[i]] = per[acl[i]].b;
							secsort[acl[i]] = second[acl[i]];
						} else if (findsec(acl[i]) == 3) {
							second[acl[i]] = per[acl[i]].c;
							secsort[acl[i]] = second[acl[i]];
						}
					}
					sort(secsort + 1, secsort + 1 + numa);
					for (int i = 1; i <= numa; i++) {
						if (second[acl[i]] == secsort[1]) {
							zty1 = per[acl[i]].a - second[acl[i]];
							zty2 = per[acl[numa - n / 2]].a - second[acl[numa - n / 2]];
							if (zty1 < zty2)
								ans += (zty2 - zty1);
						}
					}*/
			}
			if (flag == 2) {
				for (int i = numb - n / 2 + 1; i <= numb; i++)
					ans += per[bcl[i]].b;
				for (int i = 1; i <= numa; i++)
					ans += per[acl[i]].a;
				for (int i = 1; i <= numc; i++)
					ans += per[ccl[i]].c;
				/*	for (int i = 1; i <= numb; i++) {
						if (findsec(bcl[i]) == 1) {
							second[bcl[i]] = per[bcl[i]].a;
							secsort[bcl[i]] = second[i];
						} else if (findsec(bcl[i] ) == 2) {
							second[bcl[i]] = per[bcl[i]].b;
							secsort[bcl[i]] = second[bcl[i]];
						} else if (findsec(bcl[i]) == 3) {
							second[bcl[i]] = per[bcl[i]].c;
							secsort[bcl[i]] = second[bcl[i]];
						}
					}
					sort(secsort + 1, secsort + 1 + numb);
					for (int i = 1; i <= numb; i++) {
						if (second[bcl[i]] == secsort[1]) {
							zty1 = per[bcl[i]].b - second[bcl[i]];
							zty2 = per[bcl[numb - n / 2]].b - second[bcl[numb - n / 2]];
							if (zty1 < zty2)
								ans += (zty2 - zty1);
						}
					}*/
			}
			if (flag == 3) {
				for (int i = numc - n / 2 + 1; i <= numc; i++)
					ans += per[ccl[i]].c ;

				for (int i = 1; i <= numb; i++)
					ans += per[bcl[i]].b ;

				for (int i = 1; i <= numa; i++)
					ans += per[acl[i]].a;
				/*for (int i = 1; i <= numc; i++) {
					if (findsec(ccl[i] ) == 1) {
						second[ccl[i]] = per[ccl[i]].a;
						secsort[ccl[i]] = second[i];
					} else if (findsec(ccl[i] ) == 2) {
						second[ccl[i]] = per[ccl[i]].b;
						secsort[ccl[i]] = second[ccl[i]];
					} else if (findsec(ccl[i]) == 3) {
						second[ccl[i]] = per[ccl[i]].c;
						secsort[ccl[i]] = second[ccl[i]];
					}
				}
				sort(secsort + 1, secsort + 1 + numc);
				for (int i = 1; i <= numc; i++) {
					if (second[ccl[i]] == secsort[1]) {
						zty1 = per[ccl[i]].c - second[ccl[i]];
						zty2 = per[ccl[numc - n / 2]].c - second[ccl[numc - n / 2]];
						if (zty1 < zty2)
							ans += (zty2 - zty1);
					}
				}*/
			}
			if (flag == 4) {
				for (int i = 1; i <= numa; i++)
					ans += per[acl[i]].a;
				for (int i = 1; i <= numb; i++)
					ans += per[bcl[i]].b;
				for (int i = 1; i <= numc; i++)
					ans += per[ccl[i]].c;
			}

			qwrite(ans);
			cout << endl;
		}
	}


	return 0;
}