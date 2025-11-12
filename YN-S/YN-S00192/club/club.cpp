//2025csp-s mzyz ÀîÄ­è°
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 6;
int n, T, a[N][6], b[N][6];

struct F {
	int x;
};

bool operator<(const F &X, const F &Y) {
	return a[X.x][b[X.x][2]] - a[X.x][1] < a[Y.x][b[Y.x][2]] - a[Y.x][1];
}

struct F1 {
	int x;
};

bool operator<(const F1 &X, const F1 &Y) {
	return a[X.x][b[X.x][2]] - a[X.x][2] < a[Y.x][b[Y.x][2]] - a[Y.x][2];
}

struct F2 {
	int x;
};

bool operator<(const F2 &X, const F2 &Y) {
	return a[X.x][b[X.x][2]] - a[X.x][3] < a[Y.x][b[Y.x][2]] - a[Y.x][3];
}
priority_queue<F>q;
priority_queue<F1>q1;
priority_queue<F2>q2;

void f() {
	if (q.size() > n) {
		while (q.size() > n) {
			int x = q.top().x;
			q.pop();
			b[x][1] = b[x][2];
			b[x][2] = b[x][3];
			if (b[x][1] == 1) {
				q.push({x});
			} else if (b[x][1] == 2) {
				q1.push({x});
			} else {
				q2.push({x});
			}
		}
	} else if (q1.size() > n) {
		while (q1.size() > n) {
			int x = q1.top().x;
			q1.pop();
			b[x][1] = b[x][2];
			b[x][2] = b[x][3];
			if (b[x][1] == 1) {
				q.push({x});
			} else if (b[x][1] == 2) {
				q1.push({x});
			} else {
				q2.push({x});
			}
		}
	} else {
		while (q2.size() > n) {
			int x = q2.top().x;
			q2.pop();
			b[x][1] = b[x][2];
			b[x][2] = b[x][3];
			if (b[x][1] == 1) {
				q.push({x});
			} else if (b[x][1] == 2) {
				q1.push({x});
			} else {
				q2.push({x});
			}
		}
	}
}

inline void r(int &in) {
	in = 0;
	bool bo = 0;
	char ch = getchar();
	while (!isdigit(ch)) {
		bo ^= (ch == '-');
		ch = getchar();
	}
	while (isdigit(ch)) {
		in = (in << 1) + (in << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (bo) {
		in = -in;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
//	freopen("T1.out", "w", stdout);
	r(T);
	while (T--) {
		ll ans = 0;
		r(n);
		for (int i = 1; i <= n; ++i) {
			int maxx = 0, minn = 4;
			a[i][4] = 2e9 + 6;
			a[i][0] = -1;
			for (int u = 1; u <= 3; ++u) {
				r(a[i][u]);
				if (a[i][u] > a[i][maxx]) {
					maxx = u;
				}
				if (a[i][u] <= a[i][minn]) {
					minn = u;
				}
			}
			b[i][1] = maxx;
			b[i][2] = 6 - maxx - minn;
			b[i][3] = minn;
			if (b[i][1] == 1) {
				q.push({i});
			} else if (b[i][1] == 2) {
				q1.push({i});
			} else {
				q2.push({i});
			}
		}
		n >>= 1;
		f();
		f();
		while (q.size()) {
			int x = q.top().x;
			q.pop();
			ans += a[x][1];
		}
		while (q1.size()) {
			int x = q1.top().x;
			q1.pop();
			ans += a[x][2];
		}
		while (q2.size()) {
			int x = q2.top().x;
			q2.pop();
			ans += a[x][3];
		}
		cout << ans << "\n";
	}
	return 0;
}