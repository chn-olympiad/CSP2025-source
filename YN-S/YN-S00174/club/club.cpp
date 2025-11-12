#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct club {
	int fo, fz;
	int so, sz;
	int to, tz;
} a[N];

struct person {
	int sum;
	int x;
	operator <(const person &p) const {
		return x > p.x;
	}

} k[3];

void get_in(int i) {
	k[0].sum = 1;
	cin >> k[0].x;
	k[1].sum = 2;
	cin >> k[1].x;
	k[2].sum = 3;
	cin >> k[2].x;
	sort(k, k + 3);
	a[i].fo = k[0].sum;
	a[i].fz = k[0].x;
	a[i].so = k[1].sum;
	a[i].sz = k[1].x;
	a[i].to = k[2].sum;
	a[i].tz = k[2].x;
}

bool cmp(club n, club m) {
	if (n.fz == m.fz && m.sz == n.sz) {
		return n.tz > n.tz;
	} else if (n.fz == m.fz) {
		return n.sz > n.sz;
	}

	return n.fz > m.fz;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;
		long long int ans = 0;

		for (int i = 0; i < n; i++) {

			get_in(i);
		}

		sort(a, a + n, cmp);
		queue<person>yi;
		queue<person>er;
		queue<person>san;

		for (int i = 0; i < n; i++) {

			if (a[i].fo == 1) {
				if (yi.size() + 1 <= n / 2) {
					yi.push({i, a[i].fz});
					ans += a[i].fz;
				} else if (yi.size() + 1 > n / 2) {
					if (a[i].fz >= a[yi.front().sum].fz - a[yi.front().sum].sz) {
						auto r1 = yi.front();
						yi.pop();

						if (a[r1.sum].so == 2)
							er.push(r1);
						else if (a[r1.sum].so == 3)
							san.push(r1);
						yi.push({i, a[i].fz});
						ans += a[i].fz - (a[r1.sum].fz - a[r1.sum].sz);
					} else {
						if (a[i].so == 2) {
							er.push({i, a[i].sz});
							ans += a[i].sz;
						} else if (a[i].so == 3) {
							san.push({i, a[i].sz});
							ans += a[i].sz;
						}
					}
				}
			} else if (a[i].fo == 2) {
				if (er.size() + 1 <= n / 2) {
					er.push({i, a[i].fz});
					ans += a[i].fz;
				} else if (er.size() + 1 > n / 2) {
					if (a[i].fz >= a[er.front().sum].fz - a[er.front().sum].sz) {
						auto r2 = er.front();
						er.pop();

						if (a[r2.sum].so == 1)
							yi.push(r2);
						else if (a[r2.sum].so == 3)
							san.push(r2);
						er.push({i, a[i].fz});
						ans += a[i].fz - (a[r2.sum].fz - a[r2.sum].sz);
					} else {
						if (a[i].so == 1) {
							yi.push({i, a[i].sz});
							ans += a[i].sz;
						} else if (a[i].so == 3) {
							san.push({i, a[i].sz});
							ans += a[i].sz;
						}
					}
				}
			} else if (a[i].fo == 3) {
				if (san.size() + 1 <= n / 2) {
					san.push({i, a[i].fz});
					ans += a[i].fz;
				} else if (san.size() + 1 > n / 2) {
					if (a[i].fz >= a[san.front().sum].fz - a[san.front().sum].sz) {
						auto r3 = er.front();
						san.pop();

						if (a[r3.sum].so == 2)
							er.push(r3);
						else if (a[r3.sum].so == 1)
							yi.push(r3);
						san.push({i, a[i].fz});
						ans += a[i].fz - (a[r3.sum].fz - a[r3.sum].sz);
					} else {
						if (a[i].so == 1) {
							yi.push({i, a[i].sz});
							ans += a[i].sz;
						} else if (a[i].so == 2) {
							er.push({i, a[i].sz});
							ans += a[i].sz;
						}
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}