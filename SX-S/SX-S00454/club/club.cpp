#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int T, n, a1[N][3];

struct Node {
	int x, y, z;   // 三个部门
	int maxn, maxnid;  // 找最大值
	int minn, minnid;  // 最小值
	int middle, middleid;  // 中值
} a[N];

bool cmp( Node xx, Node yy ) {
	return xx.maxn > yy.maxn; // 按最大值排序说明最大值越大
}

int check( int t, int i ) {
	int c = 0;
	for ( int k = 1 ; k <= 3 ; k ++ ) {
		if ( a1[i][k] == t )
			c = k;
	}
	return c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	while ( T-- ) {
		cin >> n;
		int ans = 0, ans1 = 0;
		memset( a, 0, sizeof(a) );
		for ( int i = 1 ; i <= n ; i ++ ) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			a[i].maxn = max( a[i].x, max( a[i].y, a[i].z ) );
			a[i].minn = min( a[i].x, min( a[i].y, a[i].z ) );
			if ( a[i].x != a[i].maxn && a[i].x != a[i].minn )
				a[i].middle = a[i].x;
			else if ( a[i].y != a[i].maxn && a[i].y != a[i].minn )
				a[i].middle = a[i].y;
			else
				a[i].middle = a[i].z;
		}

		//cout << "\n";

		stable_sort( a + 1, a + n + 1, cmp );

		for ( int i = 1 ; i <= n ; i ++ )
			a1[i][1] = a[i].x, a1[i][2] = a[i].y, a1[i][3] = a[i].z;

		if ( n == 2 ) {
			int p = a[1].middle, anss = 0, ansss = 0, anssss = 0;
			if ( check(p, 1) != check(a[2].maxn, 2) && check(a[1].maxn, 1) == check(a[2].maxn, 2) )
				anss += p + a[2].maxn;
			else if ( check(a[1].maxn, 1) != check(a[2].maxn, 2))
				ansss += a[1].maxn + a[2].maxn;
			else if (check(a[2].middle, 2) != check(a[1].maxn, 1) && check(a[1].maxn, 1) == check(a[2].maxn, 2))
				anssss += a[2].middle + a[1].maxn;
			cout << max(anss, max(ansss, anssss));
			return 0;
		}

		int cnt1 = 0, cnt2 = 0, cnt3 = 0;   // 限制人数
		for ( int i = 1 ; i <= n ; i ++ ) {
			//for ( int j = 1 ; j <= 3 ; j ++ ) {
			int tt = a[i].maxn;
			int cnt = check( tt, i );
			//cout << cnt << "\n";
			if ( cnt == 1 ) {
				cnt1 ++;
				if ( cnt1 > ( n / 2 ) ) {
					cnt1 --;
					int t = a[i].middle;
					int cnt4 = check( t, i );
					if ( cnt4 == 2 ) {
						cnt2 ++;
						if ( cnt2 > ( n / 2 ) ) {
							cnt2 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt3 ++;
							ans += ttt;
						} else
							ans += t;
					} else if ( cnt4 == 3 ) {
						cnt3 ++;
						if ( cnt3 > ( n / 2 ) ) {
							cnt3 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt2 ++;
							ans += ttt;
						} else
							ans += t;
					}
				} else {
					ans += tt;
				}
			} else if ( cnt == 2 ) {
				cnt2 ++;
				if ( cnt2 > ( n / 2 ) ) {
					cnt2 --;
					int t = a[i].middle;
					int cnt4 = check( t, i );
					if ( cnt4 == 3 ) {
						cnt3 ++;
						if ( cnt3 > ( n / 2 ) ) {
							cnt3 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt1 ++;
							ans += ttt;
						} else
							ans += t;
					} else if ( cnt4 == 1 ) {
						cnt1 ++;
						if ( cnt1 > ( n / 2 ) ) {
							cnt1 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt3 ++;
							ans += ttt;
						} else
							ans += t;
					}
				} else
					ans += tt;
			} else if ( cnt == 3 ) {
				cnt3 ++;
				if ( cnt3 > ( n / 2 ) ) {
					cnt3 --;
					int t = a[i].middle;
					int cnt4 = check( t, i );
					if ( cnt4 == 2 ) {
						cnt2 ++;
						if ( cnt2 > ( n / 2 ) ) {
							cnt2 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt1 ++;
							ans += ttt;
						} else
							ans += t;
					} else if ( cnt4 == 1 ) {
						cnt1 ++;
						if ( cnt1 > ( n / 2 ) ) {
							cnt1 --;
							int ttt = a[i].minn;
							int cnt5 = check( ttt, i );
							cnt2 ++;
							ans += ttt;
						} else
							ans += t;
					}
				} else {
					ans += tt;
				}
			}
			//}
		}

		cout << ans << "\n";
	}

	return 0;
}