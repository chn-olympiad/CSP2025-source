#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct nodea
{
	int a, b, c, idx;
	bool operator < (const nodea & r) const { return a < r.a; }
};
struct nodeb
{
	int a, b, c, idx;
	bool operator < (const nodeb & r) const { return b < r.b; }
};
struct nodec
{
	int a, b, c, idx;
	bool operator < (const nodec & r) const { return c < r.c; }
};
struct nodeab
{
	int a, b, c, idx;
	bool operator < (const nodeab & r) const { return a - b > r.a - r.b; }
};
struct nodeac
{
	int a, b, c, idx;
	bool operator < (const nodeac & r) const { return a - c > r.a - r.c; }
};
struct nodeba
{
	int a, b, c, idx;
	bool operator < (const nodeba & r) const { return b - a > r.b - r.a; }
};
struct nodebc
{
	int a, b, c, idx;
	bool operator < (const nodebc & r) const { return b - c > r.b - r.c; }
};
struct nodeca
{
	int a, b, c, idx;
	bool operator < (const nodeca & r) const { return c - a > r.c - r.a; }
};
struct nodecb
{
	int a, b, c, idx;
	bool operator < (const nodecb & r) const { return c - b > r.c - r.b; }
};
int n, col[N];

void solve()
{
	priority_queue<nodea> qa;
	priority_queue<nodeb> qb;
	priority_queue<nodec> qc;
	cin >> n;
	for (int i = 1, a, b, c;i <= n;i++)
		cin >> a >> b >> c, qa.push({a, b, c, i}), qb.push({a, b, c, i}), qc.push({a, b, c, i}), col[i] = 0;
	int s1 = 0, s2 = 0, s3 = 0, ans = 0;
	priority_queue<nodeab> qab;
	priority_queue<nodeac> qac;
	priority_queue<nodeba> qba;
	priority_queue<nodebc> qbc;
	priority_queue<nodeca> qca;
	priority_queue<nodecb> qcb;
	while (s1 + s2 + s3 < n)
	{
		nodea x = nodea{0, 0, 0, 0};
		nodeb y = nodeb{0, 0, 0, 0};
		nodec z = nodec{0, 0, 0, 0};
		while (!qa.empty() && col[qa.top().idx]) qa.pop();
		while (!qb.empty() && col[qb.top().idx]) qb.pop();
		while (!qc.empty() && col[qc.top().idx]) qc.pop();
		if (!qa.empty()) x = qa.top();
		if (!qb.empty()) y = qb.top();
		if (!qc.empty()) z = qc.top();
		/*
		cout << s1 << " " << s2 << " " << s3 << " " << s1 + s2 + s3 << " " << n << "\n";
		// cout << qc.size() << "\n";

		cout << x.a << " " << x.b << " " << x.c << " " << x.idx << "\n";
		cout << y.a << " " << y.b << " " << y.c << " " << y.idx << "\n";
		cout << z.a << " " << z.b << " " << z.c << " " << z.idx << "\n";
*/
		if (x.a >= y.b && x.a >= z.c)
		{
			qa.pop();
			if (s1 < n / 2) ans += x.a, s1++, col[x.idx] = 1, qab.push({x.a, x.b, x.c, x.idx}), qac.push({x.a, x.b, x.c, x.idx});
			else
			{
				int db = -1, dc = -1;
				nodeab ab;
				nodeac ac;
				while (col[qab.top().idx] != 1) qab.pop();
				while (col[qac.top().idx] != 1) qac.pop();
				ab = qab.top(), ac = qac.top();
				if (ab.a - ab.b < x.a - x.b) db = x.a + ab.b - ab.a;
				if (ac.a - ac.c < x.a - x.c) dc = x.a + ac.c - ac.a;
				if (db == -1 && dc == -1) continue;
				col[x.idx] = 1, qab.push({x.a, x.b, x.c, x.idx}), qac.push({x.a, x.b, x.c, x.idx});
				if (db > dc || db == dc && s2 < s3) qab.pop(), ans += db, s2++, col[ab.idx] = 2, qba.push({ab.a, ab.b, ab.c, ab.idx}), qbc.push({ab.a, ab.b, ab.c, ab.idx});
				else qac.pop(), ans += dc, s3++, col[ac.idx] = 3, qca.push({ac.a, ac.b, ac.c, ac.idx}), qcb.push({ac.a, ac.b, ac.c, ac.idx});
			}
		}
		else if (y.b >= x.a && y.b >= z.c)
		{
			// printf ("bbb\n");
			// cout << "bbb" << "\n";
			qb.pop();
			if (s2 < n / 2) ans += y.b, s2++, col[y.idx] = 2, qba.push({y.a, y.b, y.c, y.idx}), qbc.push({y.a, y.b, y.c, y.idx});
			else
			{
				int da = -1, dc = -1;
				nodeba ba;
				nodebc bc;
				while (col[qba.top().idx] != 2) qba.pop();
				while (col[qbc.top().idx] != 2) qbc.pop();
				ba = qba.top(), bc = qbc.top();
				if (ba.b - ba.a < y.b - y.a) da = y.b + ba.a - ba.b;
				if (bc.b - bc.c < y.b - y.c) dc = y.b + bc.c - bc.b;
				if (da == -1 && dc == -1) continue;
				col[y.idx] = 2, qba.push({y.a, y.b, y.c, y.idx}), qbc.push({y.a, y.b, y.c, y.idx});
				if (da > dc || da == dc && s1 < s3) qba.pop(), ans += da, s1++, col[ba.idx] = 1, qab.push({ba.a, ba.b, ba.c, ba.idx}), qac.push({ba.a, ba.b, ba.c, ba.idx});
				else qbc.pop(), ans += dc, s3++, col[bc.idx] = 3, qca.push({bc.a, bc.b, bc.c, bc.idx}), qcb.push({bc.a, bc.b, bc.c, bc.idx});
			}
		}
		else
		{
			// cout << qc.size() << "\n";
			qc.pop();
			// cout << s3 << " " << n / 2 << "\n";
			if (s3 < (n / 2)) ans += z.c, s3++, col[z.idx] = 3, qca.push({z.a, z.b, z.c, z.idx}), qcb.push({z.a, z.b, z.c, z.idx});
			else
			{
				int da = -1, db = -1;
				nodeca ca;
				nodecb cb;
				while (col[qca.top().idx] != 3) qca.pop();
				while (col[qcb.top().idx] != 3) qcb.pop();
				ca = qca.top(), cb = qcb.top();
				if (ca.c - ca.a < z.c - z.a) da = z.c + ca.a - ca.c;
				if (cb.c - cb.b < z.c - z.b) db = z.c + cb.b - cb.c;
				if (da == -1 && db == -1) continue;
				col[z.idx] = 2, qca.push({z.a, z.b, z.c, z.idx}), qcb.push({z.a, z.b, z.c, z.idx});
				if (da > db || da == db && s1 < s2) qca.pop(), ans += da, s1++, col[ca.idx] = 1, qab.push({ca.a, ca.b, ca.c, ca.idx}), qac.push({ca.a, ca.b, ca.c, ca.idx});
				else qcb.pop(), ans += db, s2++, col[cb.idx] = 2, qba.push({cb.a, cb.b, cb.c, cb.idx}), qbc.push({cb.a, cb.b, cb.c, cb.idx});
			}
		}
		
	}
	cout << ans << "\n";
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T; cin >> T;
	while (T--) solve();

	return 0;
}
