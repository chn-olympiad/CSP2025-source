#include <bits/stdc++.h>
using namespace std;
long long t, n, ans1, ans2, ans3, ans, n1, n2, n3, mmax;

struct node {
	long long a1, a2, a3, id;
} a[100005], f[100005];
long long id1[100005], id2[100005], id3[100005], h1, h2, h3, t1, t2, t3, f1, f2, f3;

inline int cmp(long long x, long long y) {
	return a[x].a1 < a[y].a1;
}

inline int cmp2(long long x, long long y) {
	return a[x].a2 < a[y].a2;
}

inline int cmp3(long long x, long long y) {
	return a[x].a3 < a[y].a3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;

	while (t--) {
		h1 = h2 = h3 = 1;
		t1 = t2 = t3 = 0;
		cin >> n;
		for (int i = 1 ; i <= n ; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a[i].id = i;
		}

		for (int i = 1 ; i <= n ; i++) {

			if (a[i].a1 >= a[i].a2 && a[i].a1 >= a[i].a3) {
				if (n1 >= n / 2) {
					for (int j = 1 ; j <= t1; j++) {
						int b = id1[j];
						if (ans - a[b].a1 + max(a[b].a2, a[b].a3) + a[i].a1 > ans + max(a[i].a2, a[i].a3)) {
							if (ans - a[b].a1 + max(a[b].a2, a[b].a3) + a[i].a1 > mmax)
								f1 = b;
							mmax = max(mmax, ans - a[b].a1 + max(a[b].a2, a[b].a3) + a[i].a1);
						}
					}
					int b = f1;
					if (b) {//pop<unpop

						id1[b] = a[i].id;
						ans1 = ans1 - a[b].a1 + a[i].a1;

						if (a[b].a2 > a[b].a3) {
							n2++;
							ans2 += a[b].a2;
							t2++;
							id2[t2] = b;
						} else {
							n3++;
							ans3 += a[b].a3;
							t3++;
							id3[t3] = b;
						}
					} else {
						if (a[i].a2 > a[i].a3) {
							n2++;
							ans2 += a[i].a2;
							t2++;
							id2[t2] = a[i].id;
						} else {
							n3++;
							ans3 += a[i].a3;
							t3++;
							id3[t3] = a[i].id;
						}
					}

				} else {
					ans1 += a[i].a1;
					t1++;
					id1[t1] = a[i].id;
					n1++;
				}


			} else if (a[i].a2 >= a[i].a1 && a[i].a2 >= a[i].a3) {
				if (n2 >= n / 2) {
					for (int j = 1 ; j <= t2; j++) {
						int b = id2[j];
						if (ans - a[b].a2 + max(a[b].a1, a[b].a3) + a[i].a2 > ans + max(a[i].a1, a[i].a3)) {
							if (ans - a[b].a2 + max(a[b].a1, a[b].a3) + a[i].a2 > mmax)
								f2 = b;
							mmax = max(mmax, ans - a[b].a2 + max(a[b].a1, a[b].a3) + a[i].a2);
						}
					}
					int b = f2;
					//cout << ans - a[b].a2 + max(a[b].a1, a[b].a3) + a[i].a2 << "--" << ans + max(a[i].a1, a[i].a3) << "\n";
					if (b) {//pop<unpop
						id2[b] = a[i].id;
						ans2 = ans2 - a[b].a2 + a[i].a2;
						if (a[b].a1 > a[b].a3) {
							n1++;
							ans1 += a[b].a1;
							t1++;
							id1[t1] = b;
						} else {
							n3++;
							ans3 += a[b].a3;
							t3++;
							id3[t3] = b;
						}

					} else {
						if (a[i].a1 > a[i].a3) {
							n1++;
							ans1 += a[i].a1;
							t1++;
							id1[t1] = a[i].id;
						} else {
							n3++;
							ans3 += a[i].a3;
							t3++;
							id3[t3] = a[i].id;
						}
					}

				} else {
					ans2 += a[i].a2;
					t2++;
					id2[t2] = a[i].id;
					n2++;
				}


			} else if (a[i].a3 >= a[i].a2 && a[i].a3 >= a[i].a1) {
				if (n3 >= n / 2) {
					for (int j = 1 ; j <= t3; j++) {
						int b = id3[j];
						if (ans - a[b].a3 + max(a[b].a2, a[b].a1) + a[i].a3 > ans + max(a[i].a2, a[i].a1)) {
							if (ans - a[b].a3 + max(a[b].a2, a[b].a1) + a[i].a3 > mmax)
								f3 = b;
							mmax = max(mmax, ans - a[b].a3 + max(a[b].a2, a[b].a1) + a[i].a3);
						}
					}
					int b = f3;

					if (b) {
						//pop<unpop
						id3[b] = a[i].id;
						ans3 = ans3 - a[b].a3 + a[i].a3;
						if (a[b].a1 > a[b].a2) {
							n1++;
							ans1 += a[b].a1;
							t1++;
							id1[t1] = b;
						} else {
							n2++;
							ans2 += a[b].a3;
							t2++;
							id2[t2] = b;
						}
					} else {
						if (a[i].a2 > a[i].a1) {
							n2++;
							ans2 += a[i].a2;
							t3++;
							id3[t3] = a[i].id;
						} else {
							n1++;
							ans1 += a[i].a1;
							t1++;
							id1[t1] = a[i].id;
						}
					}

				} else {
					ans3 += a[i].a3;
					t3++;
					id3[t3] = a[i].id;
					n3++;
				}

			}
			mmax = 0;
			f1 = f2 = f3 = 0;
			ans = ans1 + ans2 + ans3;
		}
		cout << ans << "\n";
		ans1 = ans2 = ans3 = ans = 0;
		n1 = n2 = n3 = f1 = f2 = f3 = 0;

	}
	return 0;
}

