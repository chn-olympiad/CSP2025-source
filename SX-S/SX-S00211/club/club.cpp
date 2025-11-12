#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
bool st[N];

struct f {
	int a, b, c;
} s[N];
int n;

bool cmp1(f x, f y) {
	return x.a > y.a;
}

bool cmp2(f x, f y) {
	return x.b > y.b;
}

bool cmp3(f x, f y) {
	return x.c > y.c;
}

bool cmp4(f x, f y) {
	if (x.a != y.a )
		return x.a < y.a;
	if (x.b != y.b )
		return x.b < y.b;
	return x.c < y.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		memset(st, true, sizeof st);
		memset(s, 0, sizeof s);
		cin >> n;
		int v1 = n / 2, v2 = n / 2, v3 = n / 2, d1 = 0, d2 = 0, d3 = 0;
		long long x = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			if (s[i].a != 0)
				d1++;
			if (s[i].b != 0)
				d2++;
			if (s[i].c != 0)
				d3++;
		}
		if (d1 > 0 && (d1 < d2 && d1 < d3 || d2 == 0 && d3 == 0)) {
			if (d2 < d3) {
				for (int i = 1; i <= n; i++) {
					if (s[i].a != 0 && v1 > 0) {
						x += s[i].a;
						v1--;
					} else if (s[i].b != 0 && v2 > 0) {
						x += s[i].b;
						v2--;
					} else {
						x += s[i].c;
						v3--;
					}
				}
			} else if (d3 < d2) {
				for (int i = 1; i <= n; i++) {
					if (s[i].a != 0 && v1 > 0) {
						x += s[i].a;
						v1--;
					} else if (s[i].c != 0 && v3 > 0) {
						x += s[i].c;
						v3--;
					} else {
						x += s[i].b;
						v2--;
					}
				}
			} else if (d2 == 0 && d3 == 0) {
				sort(s + 1, s + n + 1, cmp1);
				for (int j = 1; j <= v1; j++)
					x += s[j].a;
			}
		} else if ( d2 > 0 && (d2 < d3 && d2 < d1 || d1 == 0 && d3 == 0)) {
			if (d1 < d3) {
				for (int i = 1; i <= n; i++) {
					if (s[i].b != 0 && v2 > 0) {
						x += s[i].b;
						v2--;
					} else if (s[i].a != 0 && v1 > 0) {
						x += s[i].a;
						v1--;
					} else {
						x += s[i].c;
						v3--;
					}
				}
			} else if (d3 < d1) {
				for (int i = 1; i <= n; i++) {
					if (s[i].b != 0 && v2 > 0) {
						x += s[i].b;
						v2--;
					} else if (s[i].c != 0 && v3 > 0) {
						x += s[i].c;
						v3--;
					} else {
						x += s[i].a;
						v1--;
					}
				}
			} else if (d1 == 0 && d3 == 0) {
				sort(s + 1, s + n + 1, cmp2);
				for (int j = 1; j <= v2; j++)
					x += s[j].b;
			}
		} else if ( d3 > 0 && (d3 < d1 && d3 < d2 || d1 == 0 && d2 == 0)) {
			if (d1 < d2) {
				for (int i = 1; i <= n; i++) {
					if (s[i].c != 0 && v3 > 0) {
						x += s[i].c;
						v3--;
					} else if (s[i].a != 0 && v1 > 0) {
						x += s[i].a;
						v1--;
					} else {
						x += s[i].b;
						v2--;
					}
				}
			} else if (d2 < d1) {
				for (int i = 1; i <= n; i++) {
					if (s[i].c != 0 && v3 > 0) {
						x += s[i].c;
						v3--;
					} else if (s[i].b != 0 && v2 > 0) {
						x += s[i].b;
						v2--;
					} else {
						x += s[i].a;
						v1--;
					}
				}
			} else if (d1 == 0 && d2 == 0) {
				sort(s + 1, s + n + 1, cmp3);
				for (int j = 1; j <= v3; j++)
					x += s[j].c;
			}
		} else {
			sort(s + 1, s + n + 1, cmp4);
			for (int i = 1; i <= n; i++) {
				int p = x;
				if (s[i].a > s[i].b && s[i].a > s[i].c) {
					if (v1 > 0) {
						x += s[i].a;
						v1--;
					} else if (s[i].b > s[i].c && v2 > 0) {
						x += s[i].b;
						v2--;
					} else {
						x += s[i].c;
						v3--;
					}
				} else if (s[i].b > s[i].a && s[i].b > s[i].c) {
					if (v2 > 0) {
						x += s[i].b;
						v2--;
					} else if (s[i].a > s[i].c && v1 > 0 ) {
						x += s[i].a;
						v1--;
					} else {
						x += s[i].c;
						v3--;
					}
				} else {
					if (v3 > 0) {
						x += s[i].c;
						v3--;
					} else if (s[i].a > s[i].b && v1 > 0) {
						x += s[i].a;
						v1--;
					} else {
						x += s[i].b;
						v2--;
					}
				}
			}
		}
		cout << x << "\n";
	}
	return 0;
}