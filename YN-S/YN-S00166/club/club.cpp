//对谁贡献最多就尽可能安排去谁；安排满n/2个，再考虑安排给次大的
//先选出每个满意值确定的前k名，再考虑去重
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, t, ans;

struct e {
	int a;
	int b;
	int c;
	int max = -1;
} el[N];

bool cmp(e s1, e s2) {
	if (s1.max != s2.max)
		return s1.max < s2.max;
	if (s1.max == 1)
		return s1.a > s2.a;
	if (s1.max == 2)
		return s1.b > s2.b;
	return s1.c > s2.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		bool A = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &el[i].a, &el[i].b, &el[i].c);

			if (el[i].a > el[i].b && el[i].a > el[i].c)
				el[i].max = 1;
			if (el[i].b > el[i].a && el[i].b > el[i].c)
				el[i].max = 2;
			if (el[i].c > el[i].b && el[i].c > el[i].a)
				el[i].max = 3;
			if (el[i].b != 0 || el[i].c != 0)
				A = false;
		}
		if (A) {
			long long ans = 0;
			sort(el + 1, el + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += el[i].a;
			cout << ans << endl;
			return 0;
		};
		sort(el + 1, el + n + 1, cmp);
		int la = 0, lb = 0, lc = 0;
		for (int i = 1; i <= n; i++) {
			if (el[i].max == 1)
				la++;
			if (el[i].max == 2)
				lb++;
			if (el[i].max == 3)
				lc++;
		}
		//	cout << la << ' ' << lb << ' ' << lc << endl;
		//	cout << endl;
		//	for (int i = 1; i <= n; i++)
		//		cout << el[i].a << ' ' << el[i].b << ' ' << el[i].c << endl;
		//cout << endl;
		int ls = -1;
		if (max(max(la, lb), lc) > n / 2)
			ls = max(max(la, lb), lc);
		for (int i = 1; i <= la; i++) {
			ans += el[i].a;
			//	cout << el[i].a << endl;
		}

		for (int i = 1; i <= lb; i++) {
			ans += el[la + i].b;
			//	cout << el[la + i].b << endl;
		}

		for (int i = 1; i <= lc; i++) {
			ans += el[la + lb + i].c;
			//	cout << el[la + lb + i].c << endl;
		}

		//	cout << endl;
		int temp[N];
		memset(temp, 0, sizeof temp);
		if (ls == la) {
			ls -= n / 2;
			for (int i = 1; i <= la; i++)
				temp[i] = min(el[i].a - el[i].b, el[i].a - el[i].c);
			sort(temp + 1, temp + la + 1);
			for (int i = 1; i <= ls; i++)
				ans -= temp[i];
		} else if (ls == lb) {
			ls -= n / 2;
			for (int i = 1; i <= lb; i++)
				temp[i] = min(el[la + i].b - el[la + i].a, el[la + i].b - el[la + i].c);
			sort(temp + 1, temp + lb + 1);
			for (int i = 1; i <= ls; i++)
				ans -= temp[i];
		} else if (ls == lc) {
			ls -= n / 2;
			for (int i = 1; i <= lc; i++)
				temp[i] = min(el[la + lb + i].c - el[la + lb + i].b, el[la + lb + i].c - el[la + lb + i].a);
			sort(temp + 1, temp + lc + 1);
			//for (int i = 1; i <= lc; i++)
			//	cout << temp[i] << ' ';
			//	cout << endl;
			for (int i = 1; i <= ls; i++)
				ans -= temp[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

/*
1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
*/

/*
//对谁贡献最多就尽可能安排去谁；安排满n/2个，再考虑安排给次大的
//先选出每个满意值确定的前k名，再考虑去重
#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
ll n, t, ans;

struct e {
	int a;
	int b;
	int c;
	int max = -1;
} el1[N],el2[N],el3[N];

bool cmp(e s1, e s2) {
	if (s1.max != s2.max)
		return s1.max < s2.max;
	if (s1.max == 1)
		return s1.a > s2.a;
	if (s1.max == 2)
		return s1.b > s2.b;
	return s1.c > s2.c;
}

bool cmp2(e s1, e s2) {
	if (s1.b != s2.b)
		return s1.b > s2.b;
	if (s1.a != s2.a)
		return s1.a > s2.a;
	return s1.c > s2.c;
}

bool cmp3(e s1, e s2) {
	if (s1.c != s2.c)
		return s1.a > s2.a;
	if (s1.b != s2.b)
		return s1.b > s2.b;
	return s1.a > s2.a;
}

bool cmp1(e s1, e s2) {
	if (s1.a != s2.a)
		return s1.a > s2.a;
	if (s1.b != s2.b)
		return s1.b > s2.b;
	return s1.c > s2.c;
}

int main() {
	//freopen("club.in", "r", stdin);
	//freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d", &n);
		bool A = true;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &el1[i].a, &el1[i].b, &el1[i].c);
			el2[i]=el1[i];el3[i]=el1[i];
			if (el1[i].a > el1[i].b && el1[i].a > el1[i].c)
				el1[i].max = 1;
			if (el1[i].b > el1[i].a && el1[i].b > el1[i].c)
				el1[i].max = 2;
			if (el1[i].c > el1[i].b && el1[i].c > el1[i].a)
				el1[i].max = 3;
			if (el1[i].b != 0 || el1[i].c != 0)
				A = false;
		}
		if (A) {
			long long ans = 0;
			sort(el1 + 1, el1 + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++)
				ans += el1[i].a;
			cout << ans << endl;
			return 0;
		};
		sort(el1 + 1, el1 + n + 1, cmp1);
		sort(el2 + 1, el2 + n + 1, cmp2);
		sort(el3 + 1, el3 + n + 1, cmp3);
		for(int )
	}
	return 0;
}
*/
/*
1
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107
*/

/*
*/