#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
template<typename T>

inline void read(T &x) {
	bool f = 1;
	x = 0;
	char ch;
	ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template<typename T>

inline void print(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
	return ;
}

const int mod = 1e9+7;
const int N = 2e5+10;
int n, q;
int lens[N];
string s1, s2;

struct node {
	int p;
	ll w;
} ct, noww, a1, a2, tr;
vector<node>has1[N], has2[N];
ll has11[N], has22[N];

ll POW(int a, int b) {
	ll ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		b = (b >> 1);
	}
	return ans;
}
ll check1, check2;
int len, num, p1, p2;

//if(p1) check=(has22[p2]-has11[p1-1]*POW(26,len)%mod+mod)%mod;
//else check=has22[p2];
void work() {
	for (int id = 1; id <= n; id++) {
		for (int lhs = 0; lhs + len - 1 < lens[id] && lens[id] <= len; lhs++) {
			int rhs = lhs + len - 1;

			if (lhs)
				a1 = has1[id][lhs - 1];
			a2 = has1[id][rhs], tr = has1[id][lens[id] - 1];
			ll val1, val1l, val1r;
			if (lhs)
				val1 = (a2.w - a1.w * POW(26, len) % mod + mod) % mod, val1l = a1.w, val1r = (tr.w - a2.w * POW(26,
				       len) % mod + mod) % mod;
			else
				val1 = a2.w, val1l = 0, val1r = (tr.w - a2.w * POW(26, len) % mod + mod) % mod;

			if (lhs)
				a1 = has2[id][lhs - 1];
			a2 = has2[id][rhs], tr = has2[id][lens[id] - 1];
			ll val2, val2l, val2r;
			if (lhs)
				val2 = (a2.w - a1.w * POW(26, len) % mod + mod) % mod, val2l = a1.w, val2r = (tr.w - a2.w * POW(26,
				       len) % mod + mod) % mod;
			else
				val2 = a2.w, val2l = 0, val2r = (tr.w - a2.w * POW(26, len) % mod + mod) % mod;

			if (val1l != val2l)
				continue;
			if (val1r != val2r)
				continue;
			if (val1 != check1)
				continue;
			if (val2 != check2)
				continue;
			if (p1 && val1l != has11[p1 - 1])
				continue;
			if (p1 == 0 && val1l)
				continue;
			if (val1r != (has11[p2 + (lens[id] - rhs)] - has11[p2]*POW(26, lens[id] - rhs) % mod + mod) % mod)
				continue;

			num++;
		}
	}
	return ;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	read(n);
	read(q);
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
		lens[i] = s1.size();
		for (int pp = 0; pp < lens[i]; pp++) {
			ct.p = pp, ct.w = (noww.w * 26 + (s1[pp] - 'a' + 1)) % mod;
			has1[i].push_back(ct);
			noww.w = ct.w;
		}
		noww.w = 0;
		for (int pp = 0; pp < lens[i]; pp++) {
			ct.p = pp, ct.w = (noww.w * 26 + (s2[pp] - 'a' + 1)) % mod;
			has2[i].push_back(ct);
			noww.w = ct.w;
		}
		noww.w = 0;
	}
	for (int qq = 1; qq <= q; qq++) {
		cin >> s1 >> s2;
		lens[qq] = s1.size();
		p1 = 0, p2 = lens[qq] - 1;
		while (s1[p1] == s2[p1])
			p1++;
		while (s1[p2] == s2[p2])
			p2--;
		for (int pp = 0; pp < lens[qq]; pp++) {
			has11[pp] = (noww.w * 26 + (s1[pp] - 'a' + 1)) % mod;
			noww.w = has11[pp];
		}
		noww.w = 0;
		for (int pp = 0; pp < lens[qq]; pp++) {
			has22[pp] = (noww.w * 26 + (s2[pp] - 'a' + 1)) % mod;
			noww.w = has22[pp];
		}
		noww.w = 0;
		len = p2 - p1 + 1;
		num = 0;
		if (p1)
			check1 = (has11[p2] - has11[p1 - 1] * POW(26, len) % mod + mod) % mod, check2 = (has22[p2] - has22[p1 - 1] * POW(26,
			         len) % mod + mod) % mod;
		else
			check1 = has11[p2], check2 = has22[p2];
		work();
		printf("%d\n", num);
	}
	return 0;
}