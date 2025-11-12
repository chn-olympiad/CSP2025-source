/*

检查以下的东西：
1、freopen
2、输入输出是否正确
3、文件名

*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
	ll a, b, c;
	int id;
};

struct node2 {
    ll val;
    int id;
};

int t;
int n;
node staff[100010];

bool cmp(node x, node y) {
    int tmp1[3];
    tmp1[0] = x.a;
    tmp1[1] = x.b;
    tmp1[2] = x.c;
    int tmp2[3];
    tmp2[0] = y.a;
    tmp2[1] = y.b;
    tmp2[2] = y.c;
    sort(tmp1, tmp1 + 3);
    sort(tmp2, tmp2 + 3);
    if (tmp1[2] != tmp2[2]) {
        return tmp1[2] > tmp2[2];
    }else if (tmp1[1] != tmp2[1]) {
        return tmp1[1] > tmp2[1];
    }else {
        return tmp1[0] > tmp2[0];
    }
}

bool cmp2(node2 x, node2 y) {
    return x.val > y.val;
}

bool cmp3(node x, node y) {
    int cha1 = abs(x.a - x.b);
    int cha2 = abs(y.a - y.b);
    if (cha1 != cha2) {
        return cha1 > cha2;
    }else {
        int mx1 = max(x.a, x.b);
        int mx2 = max(y.a, y.b);
        return mx1 > mx2;
    }
}

ll ans;

void dfs(int u, ll sum, int cnt1, int cnt2, int cnt3) {
	if (n == 2) {
		ll no;
		no = sum + cnt1;
	}
    if (u == n + 1) {
        if (cnt1 <= n / 2 && cnt2 <= n / 2 && cnt3 <= n / 2) {
            ans = max(ans, sum);
        }
        return ;
    }
    if (cnt2 < n / 2) {
        dfs(u + 1, sum - staff[u].a + staff[u].b, cnt1 - 1, cnt2 + 1, cnt3);
    }
    if (cnt3 < n / 2) {
        dfs(u + 1, sum - staff[u].a + staff[u].c, cnt1 - 1, cnt2, cnt3 + 1);
    }
    dfs(u + 1, sum, cnt1, cnt2, cnt3);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ll sum = 0;
        int yes1 = 1;
        int yes2 = 1;
		for (int i = 1; i <= n; i++) {
			ll x, y, z;
			scanf("%lld%lld%lld", &x, &y, &z);
            if (z != 0) {
                yes1 = yes2 = 0;
            }
            if (y != 0) {
                yes1 = 0;
            }
			staff[i].a = x;
			staff[i].b = y;
			staff[i].c = z;
			staff[i].id = i;
		}

        sort(staff + 1, staff + n + 1, cmp);
        /*for (int i = 1; i <= n; i++) {
            printf("%d %d %d\n", staff[i].a, staff[i].b, staff[i].c);
        }*/
		
        if (yes1) {
            for (int i = 1; i <= n / 2; i++) {
                sum += staff[i].a;
            }
            printf("%lld\n", sum);
            continue;
        }
        if (yes2) {
            sort(staff + 1, staff + n + 1, cmp3);
            int cnt1 = 0;
            int cnt2 = 0;
            for (int i = 1; i <= n; i++) {
                if (staff[i].a > staff[i].b) {
                    if (cnt1 < n / 2) {
                        cnt1++;
                        sum += staff[i].a;
                    }else {
                        cnt2++;
                        sum += staff[i].b;
                    }
                }else {
                    if (cnt2 < n / 2) {
                        cnt2++;
                        sum += staff[i].b;
                    }else {
                        cnt1++;
                        sum += staff[i].a;
                    }
                }
            }
            printf("%lld\n", sum);
            continue;
        }
        if (n <= 20) {
        	ans = 0;
        	/*for (int i = 1; i <= n; i++) {
            	printf("%d %d %d\n", staff[i].a, staff[i].b, staff[i].c);
        	}*/
            for (int i = 1; i <= n; i++) {
                sum += staff[i].a;
            }
            dfs(1, sum, n, 0, 0);
            printf("%lld\n", ans);
            continue;
        }

        int cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++) {
            int ta = staff[i].a;
            int tb = staff[i].b;
            int tc = staff[i].c;
            node2 tmp[3];
            tmp[0].val = ta;
            tmp[0].id = 0;
            tmp[1].val = tb;
            tmp[1].id = 1;
            tmp[2].val = tc;
            tmp[2].id = 2;
            sort(tmp, tmp + 3, cmp2);
            if (cnt[tmp[0].id] != n / 2) {
                sum += tmp[0].val;
                cnt[tmp[0].id]++;
            }else if (cnt[tmp[1].id] != n / 2) {
                sum += tmp[1].val;
                cnt[tmp[1].id]++;
            }else {
                sum += tmp[2].val;
                cnt[tmp[2].id]++;
            }
        }

		printf("%lld\n", sum);
	}
	return 0;
}

/*

3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


5
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
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
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

