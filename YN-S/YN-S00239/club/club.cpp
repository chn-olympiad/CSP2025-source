#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e5 + 10;

struct Club {
	int happy, bh;
};

struct Person {
	int zt;
	Club c[5];
};

bool cmp_Club_happy(Club a, Club b) {
	if (a.happy != b.happy)
		return a.happy > b.happy;
	else
		return a.bh < b.bh;
}

bool cmp(Person a, Person b) {
	int a_mx_happy = a.c[a.zt].happy, b_mx_happy = b.c[b.zt].happy;
	int a_se_happy = a.c[a.zt + 1].happy, b_se_happy = b.c[b.zt + 1].happy;


	if (a_mx_happy - a_se_happy != b_mx_happy - b_se_happy)
		return a_mx_happy - a_se_happy > b_mx_happy - b_se_happy;
	else
		return a_mx_happy > b_mx_happy;
}
int t, n;
Person p[MAXN];
int cnt_a, cnt_b, cnt_c;
int res;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cnt_a = 0, cnt_b = 0, cnt_c = 0;
		res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].c[1].happy >> p[i].c[2].happy >> p[i].c[3].happy;
			p[i].zt = 1;
			p[i].c[1].bh = 1;
			p[i].c[2].bh = 2;
			p[i].c[3].bh = 3;
			sort(p[i].c + 1, p[i].c + 4, cmp_Club_happy);
		}

		vector<Person> a, b, c;
		for (int i = 1; i <= n; i++) {
			if (p[i].c[1].bh == 1)
				a.push_back(p[i]);
			else if (p[i].c[1].bh == 2)
				b.push_back(p[i]);
			else
				c.push_back(p[i]);
		}

		sort(a.begin(), a.end(), cmp);
		while (cnt_a < a.size() && cnt_a < n / 2) {
			int zt = a[cnt_a].zt;
			res += a[cnt_a].c[zt].happy;
			cnt_a++;
		}
		while (cnt_a < a.size()) {
			a[cnt_a].zt = 2;
			int next = a[cnt_a].c[2].bh;
			if (next == 2)
				b.push_back(a[cnt_a]);
			else
				c.push_back(a[cnt_a]);
			cnt_a++;
		}
		a.clear();

		sort(b.begin(), b.end(), cmp);
		while (cnt_b < b.size() && cnt_b < n / 2) {
			int zt = b[cnt_b].zt;
			res += b[cnt_b].c[zt].happy;
			cnt_b++;
		}
		while (cnt_b < b.size()) {
			b[cnt_b].zt = 2;
			int next = b[cnt_b].c[2].bh;
			if (next == 1)
				a.push_back(b[cnt_b]);
			else
				c.push_back(b[cnt_b]);
			cnt_b++;
		}
		b.clear();

		sort(c.begin(), c.end(), cmp);
		while (cnt_c < c.size() && cnt_c < n / 2) {
			int zt = c[cnt_c].zt;
			res += c[cnt_c].c[zt].happy;
			cnt_c++;
		}
		while (cnt_c < c.size()) {
			c[cnt_c].zt = 2;
			int next = c[cnt_c].c[2].bh;
			if (next == 1)
				a.push_back(c[cnt_c]);
			else
				b.push_back(c[cnt_c]);
			cnt_c++;
		}

		sort(a.begin(), a.end(), cmp);
		cnt_a = 0;
		while (cnt_a < a.size()) {
			int zt = a[cnt_a].zt;
			res += a[cnt_a].c[zt].happy;
			cnt_a++;
		}
		sort(b.begin(), b.end(), cmp);
		cnt_b = 0;
		while (cnt_b < b.size()) {
			int zt = b[cnt_b].zt;
			res += b[cnt_b].c[zt].happy;
			cnt_b++;
		}

		cout << res << "\n";
	}
	return 0;
}