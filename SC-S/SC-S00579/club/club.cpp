#include <bits/stdc++.h>
#define pi pair<int,int>
using namespace std;
constexpr int N = 1e5 + 15;

int n;
struct node {
	int a, b, c;
	int idmx, idse;
}p[N];
struct bao0 {
	int w, id;
	bool operator <(const bao0& x) const {
		return w < x.w;
	}
}; 
priority_queue <bao0> q[4];

bool cmp1 (node x, node y) {
	return x.a > y.a;
}

bool cmp2 (node x, node y) {
	return x.b > y.b;
}

void solve () {
	for (int i = 1; i <= 3; ++ i) {
		while (!q[i].empty ()) q[i].pop ();
	}
	scanf ("%d", &n);
	bool fA = true, fB = true;
	for (int i = 1; i <= n; ++ i) {
		scanf ("%d%d%d", &p[i].a, &p[i].b, &p[i].c);
		int maxx = max ({p[i].a, p[i].b, p[i].c});
		if (p[i].a == maxx) {
			p[i].idmx = 1;
			maxx = max (p[i].b, p[i].c);
			if (maxx == p[i].b) p[i].idse = 2;
			else p[i].idse = 3;
		} else if (p[i].b == maxx) {
			p[i].idmx = 2;
			maxx = max (p[i].a, p[i].c);
			if (maxx == p[i].c) p[i].idse = 3;
			else p[i].idse = 1;
		} else if (p[i].c == maxx) {
			p[i].idmx = 3;
			maxx = max (p[i].b, p[i].a);
			if (maxx == p[i].b) p[i].idse = 2;
			else p[i].idse = 1;
		}
		if (p[i].b != 0 || p[i].c != 0) fA = false;
		if (p[i].c != 0) fB = false;
	}
	if (fA || fB) {
		sort (p + 1, p + n + 1, cmp1);
		int ans1 = 0, tot1 = 0, tot2 = 0;
		for (int i = 1; i <= n; ++ i) {
			if (tot1 < n / 2) {
				++ tot1;
				ans1 += p[i].a;
			} else if (tot2 < n / 2) {
				++ tot2;
				ans1 += p[i].b;
			}
		}
		sort (p + 1, p + n + 1, cmp2);
		int ans2 = 0;
		tot1 = 0, tot2 = 0;
		for (int i = 1; i <= n; ++ i) {
			if (tot2 < n / 2) {
				++ tot2;
				ans2 += p[i].b;
			} else if (tot1 < n / 2) {
				++ tot1;
				ans2 += p[i].a;
			}
		}
		printf ("%d\n", max (ans1, ans2));
		return ;
	}
	int ans = 0;
	int tot1 = 0, tot2 = 0, tot3 = 0;
	for (int i = 1; i <= n; ++ i) {
		if (p[i].idmx == 1) {
			if (tot1 < n / 2) {
				++ tot1;
				q[1].push ({p[i].a, i});
				ans += p[i].a;
			} else {
				int j = q[1].top ().id;
				q[1].pop ();
				-- tot1;
				if (p[j].idse == 2) {
					if (tot2 < n / 2) {
						if (ans <= ans - p[j].a + p[j].b + p[i].a) {
							q[2].push ({p[j].b, j});
							q[1].push ({p[i].a, i});
							++ tot1;
							++ tot2;
							ans = ans - p[j].a + p[j].b + p[i].a;
						}
					} else {
						if (ans <= ans - p[j].a + p[j].c + p[i].a) {
							q[3].push ({p[j].c, j});
							q[1].push ({p[i].a, i});
							++ tot1;
							++ tot3;
							ans = ans - p[j].a + p[j].c + p[i].a;
						} else {
							q[1].push ({p[j].a, j});
							++ tot1;
						}
					}
				} else {
					if (tot3 < n / 2) {
						if (ans <= ans - p[j].a + p[j].c + p[i].a) {
							q[3].push ({p[j].c, j});
							q[1].push ({p[i].a, i});
							++ tot1;
							++ tot3;
							ans = ans - p[j].a + p[j].c + p[i].a;
						}
					} else {
						if (ans <= ans - p[j].a + p[j].b + p[i].a) {
							q[2].push ({p[j].b, j});
							q[1].push ({p[i].a, i});
							++ tot1;
							++ tot2;
							ans = ans - p[j].a + p[j].b + p[i].a;
						} else {
							q[1].push ({p[j].a, j});
							++ tot1;
						}
					}
				}
			}
		} else if (p[i].idmx == 2) {
			if (tot2 < n / 2) {
				++ tot2;
				q[2].push ({p[i].b, i});
				ans += p[i].b;
			} else {
				int j = q[2].top ().id;
				q[2].pop ();
				-- tot2;
				if (p[j].idse == 1) {
					if (tot1 < n / 2) {
						if (ans <= ans - p[j].b + p[j].a + p[i].b) {
							q[1].push ({p[j].a, j});
							q[2].push ({p[i].b, i});
							++ tot1;
							++ tot2;
							ans = ans - p[j].b + p[j].a + p[i].b;
						}
					} else {
						if (ans <= ans - p[j].b + p[j].c + p[i].b) {
							q[3].push ({p[j].c, j});
							q[2].push ({p[i].b, i});
							++ tot2;
							++ tot3;
							ans = ans - p[j].b + p[j].c + p[i].b;
						} else {
							q[2].push ({p[j].b, j});
							++ tot2;
						}
					}
				} else {
					if (tot3 < n / 2) {
						if (ans <= ans - p[j].b + p[j].c + p[i].b) {
							q[3].push ({p[j].c, j});
							q[2].push ({p[i].b, i});
							++ tot2;
							++ tot3;
							ans = ans - p[j].b + p[j].c + p[i].b;
						}
					} else {
						if (ans <= ans - p[j].b + p[j].a + p[i].b) {
							q[1].push ({p[j].a, j});
							q[2].push ({p[i].b, i});
							++ tot1;
							++ tot2;
							ans = ans - p[j].b + p[j].a + p[i].b;
						} else {
							q[2].push ({p[j].b, j});
							++ tot2;
						}
					}
				}
			}
		} else if (p[i].idmx == 3) {
			if (tot3 < n / 2) {
				++ tot3;
				q[3].push ({p[i].c, i});
				ans += p[i].c;
			} else {
				int j = q[3].top ().id;
				q[3].pop ();
				-- tot3;
				if (p[j].idse == 1) {
					if (tot1 < n / 2) {
						if (ans <= ans - p[j].c + p[j].a + p[i].c) {
							q[1].push ({p[j].a, j});
							q[3].push ({p[i].c, i});
							++ tot1;
							++ tot3;
							ans = ans - p[j].c + p[j].a + p[i].c;
						}
					} else {
						if (ans <= ans - p[j].c + p[j].b + p[i].c) {
							q[2].push ({p[j].b, j});
							q[3].push ({p[i].c, i});
							++ tot2;
							++ tot3;
							ans = ans - p[j].c + p[j].b + p[i].c;
						} else {
							q[3].push ({p[j].c, j});
							++ tot3;
						}
					}
				} else {
					if (tot2 < n / 2) {
						if (ans <= ans - p[j].c + p[j].b + p[i].c) {
							q[2].push ({p[j].b, j});
							q[3].push ({p[i].c, i});
							++ tot2;
							++ tot3;
							ans = ans - p[j].c + p[j].b + p[i].c;
						}
					} else {
						if (ans <= ans - p[j].c + p[j].a + p[i].c) {
							q[1].push ({p[j].a, j});
							q[3].push ({p[i].c, i});
							++ tot1;
							++ tot3;
							ans = ans - p[j].c + p[j].a + p[i].c;
						} else {
							q[3].push ({p[j].c, j});
							++ tot3;
						}
					}
				}
			}
		}
	}
	printf ("%d\n", ans);
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	int T;
	scanf ("%d", &T);
	while (T --) solve ();
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

我还不想保龄

但奈何我太菜了

唉 
*/