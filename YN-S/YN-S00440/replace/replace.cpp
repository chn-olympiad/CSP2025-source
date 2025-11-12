/*********************************************************************
    程序名:replace
    版权:
    作者:
    日期: 2025-11-01
    说明:
*********************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

struct node {
	string s1, s2;
	int len;
};
node a[200010];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		a[i].s1 = "";
		a[i].s2 = "";
		char c = getchar();
		while (!(c >= 'a' && c <= 'z'))
			c = getchar();
		while (c >= 'a' && c <= 'z') {
			a[i].s1 += c;
			c = getchar();
		}
		while (!(c >= 'a' && c <= 'z'))
			c = getchar();
		while (c >= 'a' && c <= 'z') {
			a[i].s2 += c;
			c = getchar();
		}
		a[i].len = (int)a[i].s1.size();
	}
	while (q--) {
		string t1 = "", t2 = "";
		char c = getchar();
		while (!(c >= 'a' && c <= 'z'))
			c = getchar();
		while (c >= 'a' && c <= 'z') {
			t1 += c;
			c = getchar();
		}
		while (!(c >= 'a' && c <= 'z'))
			c = getchar();
		while (c >= 'a' && c <= 'z') {
			t2 += c;
			c = getchar();
		}
		int sz1 = t1.size(), sz2 = t2.size();
		if (sz1 != sz2) {
			puts("0");
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j + a[i].len - 1 < sz1; j++) {
				string s1 = "", s2 = "";
				for (int k = 0; k < j; k++)
					s2 += t1[k];
				for (int k = j; k <= j + a[i].len - 1; k++) {
					s1 += t1[k];
				}
				if (a[i].s1 != s1) {
					continue;
				}
				s2 += a[i].s2;
				for (int k = j + a[i].len; k < sz1; k++) {
					s2 += t1[k];
				}
				if (s2 == t2)
					ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
