#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int T, n;


struct member {
	int a, b, c;
} A[N];

bool cmp(member x, member y) {
	if (x.a == y.a) {
		if (x.b == y.b) {
			return x.c > y.c;
		}
		return x.b > y.b;
	}
	return x.a > y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		memset(A, 0, sizeof(A));
		int ea = 0, eb = 0, ec = 0, cnta = 0, cntb = 0, cntc = 0;
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> A[i].a >> A[i].b >> A[i].c;
		}
		sort(A + 1, A + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (A[i].a > A[i].b && A[i].a > A[i].c) {
				if (ea < n / 2) {
					ea++;
					ans += A[i].a;
					cnta = i;
				} else {
					if (eb < n / 2) {
						if (ans - A[cnta].a + A[cnta].b + A[i].a > ans) {
							ans = ans - A[cnta].a + A[cnta].b + A[i].a;
							eb++;
						}
						if (ec < n / 2 && ans - A[cnta].b - A[i].a + A[cnta].c + A[i].a > ans) {
							ans = ans - A[cnta].b - A[i].a + A[cnta].c + A[i].a;
							eb--;
							ec++;
						}
					} else if (ec < n / 2) {
						if (ans - A[cnta].a + A[cnta].c + A[i].a > ans) {
							ans = ans - A[cnta].a + A[cnta].c + A[i].a;
							ec++;
						}
					}
				}
			} else if (A[i].b > A[i].a && A[i].b > A[i].c) {
				if (eb < n / 2) {
					eb++;
					ans += A[i].b;
					cntb = i;
				} else {
					if (ea < n / 2) {
						if (ans - A[cntb].b + A[cntb].a + A[i].b > ans) {
							ans = ans - A[cntb].b + A[cntb].a + A[i].b;
							ea++;
						}
						if (ec < n / 2 && ans - A[cntb].a - A[i].b + A[cntb].c + A[i].b > ans) {
							ans = ans - A[cntb].a - A[i].b + A[cntb].c + A[i].b;
							ea--;
							ec++;
						}
					} else if (ec < n / 2) {
						if (ans - A[cntb].b + A[cntb].c + A[i].b > ans) {
							ans = ans - A[cntb].b + A[cntb].c + A[i].b;
							ec++;
						}
					}
				}
			} else if (A[i].c > A[i].a && A[i].c > A[i].b) {
				if (ec < n / 2) {
					ec++;
					ans += A[i].c;
					cntc = i;
				} else {
					if (ea < n / 2) {
						if (ans - A[cntc].c + A[cntc].a + A[i].c > ans) {
							ans = ans - A[cntc].c + A[cntc].a + A[i].c;
							ea++;
						}
						if (eb < n / 2 && ans - A[cntc].a - A[i].c + A[cntc].b + A[i].c > ans) {
							ans = ans - A[cntc].a - A[i].c + A[cntc].b + A[i].c;
							ea--;
							eb++;
						}
					} else if (eb < n / 2) {
						if (ans - A[cntc].c + A[cntc].b + A[i].c > ans) {
							ans = ans - A[cntc].c + A[cntc].b + A[i].c;
							eb++;
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
