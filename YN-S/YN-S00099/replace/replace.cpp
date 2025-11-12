#include <bits/stdc++.h>
using namespace std;

int n, q, cnt, x;

string s, c, s1, a1, a2, a3;

bool f[200100];

struct str {
	string a;
	string b;
	int num;
} st[200100];

bool cmp(str s1, str s2) {
	if (s1.a.size() > s2.a.size())
		return true;
	return false;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> st[i].a >> st[i].b;
		st[i].num ++;
	}
	sort(st + 1, st + n, cmp);
	for (int i = 1; i < n; i++) {
		if (!f[i]) {
			for (int j = i + 1; j <= n; j++) {
				if (!f[j]) {
					a1 = st[i].a;
					a2 = st[j].a;
					a3 = st[j].b;
					if (a1.find(a2) != -1) {
						x = a1.find(a2);
						a1.replace(x, a2.size(), a3);
						if (a1 == st[i].b) {
							f[j] = true;
							st[i].num ++;
						}
					}
				}
			}
		}
	}
	/*for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			cout << i << ' ' << st[i].num << endl;
		}
	}*/
	while (q--) {
		cnt = 0;
		cin >> s >> s1;
		c = s;
		//cout << s << endl;
		for (int i = 1; i <= n; i++) {
			if (!f[i]) {
				c = s;
				if (c.find(st[i].a) != -1) {
					x = c.find(st[i].a);
					//cout << x << endl;
					c.replace(x, st[i].a.size(), st[i].b);
				}
				if (c == s1)
					cnt += st[i].num;
			}
		}
		//cout << endl;
		cout << cnt << '\n';
		//cout << endl;
	}
	return 0;
}