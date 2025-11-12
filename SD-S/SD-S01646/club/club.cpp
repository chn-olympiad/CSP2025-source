#include <bits/stdc++.h>

#define rep(it, st, ed) for(int it = st; it <= (ed); it++)
#define per(it, st, ed) for(int it = ed; it >= (st); it--)
#define Rep(it, st, ed) for(int it = st; it < (ed); it++)
#define pn putchar('\n');
#define ps putchar(' ');

using ll = long long;
using lf = double;
using ld = long double;

template<class T> void cmax(T& x, const T& y) { if(x < y) x = y; }
template<class T> void cmin(T& x, const T& y) { if(x > y) x = y; } 

template<class T>
void qr(T& x) {
	x = 0;
	int c, sg = 0;
	while(!isdigit(c = getchar())) if(c == '-') sg = 1;
	do x = (x << 3) + (x << 1) + (c ^ '0');
	while(isdigit(c = getchar()));
	if(sg) x = -x;
}
template<class T>
void qw(T x) {
	static int bf[123];
	int bp = 0;
	if(x == 0) return putchar('0'), void();
	if(x < 0) putchar('-'), x = -x;
	while(x)
	{
		bf[++bp] = x % 10;
		x /= 10;
	}
	per(i, 1, bp) putchar(bf[i] + '0');
}

bool _st;

const int N = 1e5 + 5;
int a[N][4], n;

namespace Subtask1 {

int f[202][202][202];
void run() {
	int t = n / 2;
	rep(i, 0, n - 1)
	{
		rep(x, 0, t) rep(y, 0, t)
		{
			int z = i - x - y;
			if(z < 0) break;
			if(z > n / 2) continue;
			if(x + 1 <= t) cmax(f[x + 1][y][z], f[x][y][z] + a[i + 1][1]);
			if(y + 1 <= t) cmax(f[x][y + 1][z], f[x][y][z] + a[i + 1][2]);
			if(z + 1 <= t) cmax(f[x][y][z + 1], f[x][y][z] + a[i + 1][3]);
		}
	}
	int ans = 0;
	rep(i, 0, t) rep(j, 0, t)
	{
		int k = n - i - j;
		if(k < 0 || k > t) continue;
		cmax(ans, f[i][j][k]);
	}
	qw(ans), pn;
	rep(i, 0, t) rep(j, 0, t) rep(k, 0, t) f[i][j][k] = 0;
}

}

namespace Subtask2 {

int ck() {
	int ok = 1;
	rep(i, 1, n) if(a[i][2] || a[i][3]) ok = 0;
	return ok;
}
void run() {
	::std::priority_queue<int> q;
	rep(i, 1, n) q.push(a[i][1]);
	ll ans = 0;
	rep(i ,1 , n / 2) ans += q.top(), q.pop();
	qw(ans), pn;
}

}

namespace Subtask3 {

int ck() {
	int ok = 1;
	rep(i, 1, n) if(a[i][3]) ok = 0;
	return ok;
}

struct T {
	int w, i;
	bool operator < (const T& rhs) const {
		return w < rhs.w;
	}
};
::std::priority_queue<T> q1, q2;
int in[N];
void run() {
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop();
	ll ans = 0;
	int t = n / 2;
	rep(i, 1, n) in[i] = 0;
	rep(i, 1, t)
	{
		q1.push({a[i][2] - a[i][1], i});
		ans += a[i][1];
		in[i] = 1;
	}
	rep(i, t + 1, n)
	{
		q2.push({a[i][1] - a[i][2], i});
		ans += a[i][2];
	}
	rep(_, 1, 10 * n)
	{
		T t1, t2;
		while(1)
		{
			t1 = q1.top(), t2 = q2.top();
			if(!in[t1.i]) {
				q1.pop();
				continue;
			}
			if(in[t2.i]) {
				q2.pop();
				continue;
			}
			break;
		}
		if(t1.w + t2.w > 0) {
			q1.pop();
			q2.pop();
			in[t1.i] = 0;
			in[t2.i] = 1;
			ans += t1.w + t2.w;
			q1.push({a[t2.i][2] - a[t2.i][1], t2.i});
			q2.push({a[t1.i][1] - a[t1.i][2], t1.i});
		} else break;
	}
	qw(ans), pn;
}

}

namespace SubtaskAC {

struct T {
	int w, i;
	bool operator < (const T& rhs) const {
		if(w ^ rhs.w) return w > rhs.w;
		return i < rhs.i;
	}
};
::std::set<T> s[4][4];
int in[N], c[4];
void run() {
	rep(i, 1, 3)
	{
		c[i] = 0;
		rep(j, 1, 3)
			s[i][j].clear();
	}
	c[1] = c[2] = c[3] = 0;
	int t = n / 2;
	ll ans = 0;
	rep(i, 1, t)
	{
		s[1][2].insert({a[i][2] - a[i][1], i});
		s[1][3].insert({a[i][3] - a[i][1], i});
		ans += a[i][1];
		in[i] = 1;
		c[1]++;
	}
	rep(i, t + 1, n)
	{
		s[2][1].insert({a[i][1] - a[i][2], i});
		s[2][3].insert({a[i][3] - a[i][2], i});
		ans += a[i][2];
		in[i] = 2;
		c[2]++;
	}

	int n6 = n;
	rep(_, 1, n6) rep(x, 1, 3) rep(y, 1, 3) if(x != y)
	{
		int z = 6 - x - y;
		if(s[x][y].empty()) continue;
		T l = *s[x][y].begin();
		if(c[y] + 1 <= t && l.w > 0) {
			c[x]--;
			c[y]++;
			s[x][y].erase(s[x][y].begin());
			s[x][z].erase({a[l.i][z] - a[l.i][x], l.i});
			s[y][x].insert({a[l.i][x] - a[l.i][y], l.i});
			s[y][z].insert({a[l.i][z] - a[l.i][y], l.i});
			ans += l.w;
			in[l.i] = y;
		} else {
			if(s[y][x].empty()) continue;
			T r = *s[y][x].begin();
			if(l.w + r.w < 0) {
				continue;
			} else {
				ans += l.w + r.w;
				s[x][y].erase(s[x][y].begin());
				s[x][z].erase({a[l.i][z] - a[l.i][x], l.i});
				s[y][x].erase(s[y][x].begin());
				s[y][z].erase({a[r.i][z] - a[r.i][y], r.i});

				s[y][x].insert({a[l.i][x] - a[l.i][y], l.i});
				s[y][z].insert({a[l.i][z] - a[l.i][y], l.i});
				s[x][y].insert({a[r.i][y] - a[r.i][x], r.i});
				s[x][z].insert({a[r.i][z] - a[r.i][x], r.i});
				in[l.i] = y;
				in[r.i] = x;
			}
		}
	}

	qw(ans), pn;
}

}

void solve() {
	qr(n);
	rep(i, 1, n) qr(a[i][1]) , qr(a[i][2]), qr(a[i][3]);
	if(n <= 200)
		Subtask1::run();
	else if(Subtask2::ck())
		Subtask2::run();
	else if(Subtask3::ck())
		Subtask3::run();
	else
		SubtaskAC::run();
}

bool _ed;
int main() { // ::std::cerr << (&_st - &_ed) / 1024. / 1024 << ::std::endl;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tcs;
	qr(tcs);
	while(tcs--) solve();
	return 0;
}





















