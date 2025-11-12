#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

template <typename type>
inline void read(type &x) {
	x = 0; int ch = getchar(); bool flag (false);
	while (!isdigit(ch)) flag = ch == '-', ch = getchar();
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	flag ? x = -x : 0;
}
template <typename type>
inline void write(type x, bool mode = 1) {
	x < 0 ? putchar('-'), x = -x : 0; static int stack[20], top (0);
	do stack[++top] = x % 10, x /= 10; while (x);
	while (top) putchar(stack[top--] | 48);
	mode ? putchar('\n') : putchar(' ');
}

using namespace std;

using ll = long long;

constexpr int MaxN = 1e5 + 10;
constexpr int inf = 1e9;

int n;

struct peo {
	int a, b, c;
	int mx;
	bool operator < (const peo &rhs) const {
		return mx > rhs.mx;
	}
} p[MaxN];

int cnt[3];

struct node {
	int idx, to, val;
	bool operator < (const node &rhs) const {
		return val < rhs.val;
	}
};

inline void solve() {
//	debug(" testcase");
	read(n);
	
	cnt[0] = cnt[1] = cnt[2] = 0;
	
	const int lim = n >> 1; 
	
	priority_queue <node> A, B, C;
	
	for (int i = 1; i <= n; i++) {
		read(p[i].a), read(p[i].b), read(p[i].c);
		p[i].mx = max(max(p[i].a, p[i].b), p[i].c);
	}
	sort(p + 1, p + n + 1);
	
	int ans = 0;
	for (int i = 1; i <= lim; i++) {
		ans += p[i].mx;
		if (p[i].mx == p[i].a) { // a is max
			++ cnt[0];
			int sec = max(p[i].b, p[i].c);
			if (sec == p[i].b)
				A.push((node){i, 1, sec - p[i].mx});
			else A.push((node){i, 2, sec - p[i].mx});
		} else if (p[i].mx == p[i].b) {
			++ cnt[1];
			int sec = max(p[i].a, p[i].c);
			if (sec == p[i].a)
				B.push((node){i, 0, sec - p[i].mx});
			else B.push((node){i, 2, sec - p[i].mx}); 
		} else if (p[i].mx == p[i].c) {
			++ cnt[2];
			int sec = max(p[i].a, p[i].b);
			if (sec == p[i].a)
				C.push((node){i, 0, sec - p[i].mx});
			else C.push((node){i, 1, sec - p[i].mx});
		}
	}
	for (int i = lim + 1; i <= n; i++) {
//		debug(" i = %d\n", i);
//		debug(" now = (%d, %d, %d)\n", p[i].a, p[i].b, p[i].c);
		int fir = -inf, sec = -inf;
		//choose max / adjust
		if (p[i].mx == p[i].a) {
			if (cnt[0] == lim) {
				fir = max(p[i].b, p[i].c);
			} else fir = p[i].a;
			if (!A.empty()) sec = A.top().val + p[i].a;
			
			if (fir >= sec) {
				ans += fir;
				if (cnt[0] == lim) {
					if (fir == p[i].b) {
						++ cnt[1];
						B.push((node){i, 2, p[i].c - p[i].b});
					} else {
						++ cnt[2];
						C.push((node){i, 1, p[i].b - p[i].c});
					}
				} else {
					++ cnt[0];
					int ano = max(p[i].b, p[i].c);
					if (ano == p[i].b) {
						A.push((node){i, 1, p[i].b - p[i].a});
					} else {
						A.push((node){i, 2, p[i].c - p[i].a});
					}
				}
			} else {
				assert(A.size());
				ans += sec;
				++ cnt[A.top().to];
				A.pop();
				int ano = max(p[i].b, p[i].c);
				if (ano == p[i].b) {
					A.push((node){i, 1, p[i].b - p[i].a});
				} else {
					A.push((node){i, 2, p[i].c - p[i].a});
				}
			}
		} else if (p[i].mx == p[i].b) {
//			debug(" cnt[1] = %d\n", cnt[1]);
			if (cnt[1] == lim) {
				fir = max(p[i].a, p[i].c);
			} else fir = p[i].b;
			if (!B.empty()) sec = B.top().val + p[i].b;
			
			if (fir >= sec) {
				ans += fir;
				if (cnt[1] == lim) {
					if (fir == p[i].a) {
						++ cnt[0];
						A.push((node){i, 2, p[i].c - p[i].a});
					} else {
						++ cnt[2];
						C.push((node){i, 0, p[i].a - p[i].c});
					}
				} else {
					++ cnt[1];
					int ano = max(p[i].a, p[i].c);
					if (ano == p[i].a) {
						B.push((node){i, 0, p[i].a - p[i].b});
					} else {
						B.push((node){i, 2, p[i].c - p[i].b});
					}
				}
			} else {
				assert(B.size());
				ans += sec;
				++ cnt[B.top().to];
				B.pop();
				int ano = max(p[i].a, p[i].c);
				if (ano == p[i].a) {
					B.push((node){i, 0, p[i].a - p[i].b});
				} else {
					B.push((node){i, 2, p[i].c - p[i].b});
				}
			}
		} else if (p[i].mx == p[i].c) {
			if (cnt[2] == lim) {
				fir = max(p[i].a, p[i].b);
			} else fir = p[i].c;
			if (!C.empty()) sec = C.top().val + p[i].c;
			
			if (fir >= sec) {
				ans += fir;
				if (cnt[2] == lim) {
					if (fir == p[i].a) {
						++ cnt[0];
						A.push((node){i, 1, p[i].b - p[i].a});
					} else {
						++ cnt[1];
						B.push((node){i, 0, p[i].a - p[i].b});
					}
				} else {
					++ cnt[2];
					int ano = max(p[i].a, p[i].b);
					if (ano == p[i].a) {
						C.push((node){i, 0, p[i].a - p[i].c});
					} else {
						C.push((node){i, 1, p[i].b - p[i].c});
					}
				}
			} else {
				assert(C.size());
				ans += sec;
				++ cnt[C.top().to];
				C.pop();
				int ano = max(p[i].a, p[i].b);
				if (ano == p[i].a) {
					C.push((node){i, 0, p[i].a - p[i].c});
				} else {
					C.push((node){i, 1, p[i].b - p[i].c});
				}
			}
		}
	}
	
	write(ans);
	
//	debug(" %d %d %d\n", (int)A.size(), (int)B.size(), (int)C.size());
	
	while (!A.empty()) A.pop();
	while (!B.empty()) B.pop();
	while (!C.empty()) C.pop(); 
}

signed main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
//	freopen("club5.in", "r", stdin);
	
	int T; read(T);
	while (T--) solve();
}
