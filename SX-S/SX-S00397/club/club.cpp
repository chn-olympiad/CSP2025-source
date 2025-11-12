#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5+20;

int n;

struct person {
	int a, b, c, id;
} p[N];

int get_bm_delta(person tar, int bm) {
	switch (bm) {
		case 1:
			return tar.a - max(tar.b, tar.c);
		case 2:
			return tar.b - max(tar.c, tar.a);
	}
	return tar.c - max(tar.a, tar.b);
}

char second_choice(int i) {
	if ((p[i].a >= p[i].c || p[i].a >= p[i].b) && (p[i].a <= p[i].c || p[i].a <= p[i].b))
		return 'a';
	if ((p[i].b >= p[i].c || p[i].b >= p[i].a) && (p[i].b <= p[i].c || p[i].b <= p[i].a))
		return 'b';
	return 'c';
}

int now_check = 1;

bool cmp(person a, person b) {
	return get_bm_delta(a, now_check) > get_bm_delta(b, now_check);
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int na = 0, nb = 0, nc = 0;
		int ans = 0;
		memset(p, 0, sizeof p);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> p[i].a >> p[i].b >> p[i].c;


			p[i].id = i;
		}
		int i = 1;
		now_check = 1;

		sort(p + i, p + n + 1, cmp);
		for (; na < n / 2 && i <= n; i++, na++) {
			if (get_bm_delta(p[i], 1) >= 0) {
				ans += p[i].a;
			} else
				break;
		}
		//首次排序

		now_check = 2;
		sort(p + i, p + n + 1, cmp);
		for (; nb < n / 2 && i <= n; i++, nb++) {
			if (get_bm_delta(p[i], 2) >= 0) {
				ans += p[i].b;
			} else
				break;
		}
		//再次排序


		now_check = 3;
		sort(p + i, p + n + 1, cmp);
		for (; nc < n / 2 && i <= n;  i++, nc++) {
			if (get_bm_delta(p[i], 3) >= 0) {
				ans += p[i].c;
			} else {
				break;
			}
		}
		//C完全接纳首先愿意来C的

		for (; i <= n; i++) {
			switch (second_choice(i)) {
				case 'a':
					ans += p[i].a;
					na++;
					break;
				case 'b':
					ans += p[i].b;
					nb++;
					break;
				case 'c':
					ans += p[i].c;
					nc++;
					break;
			}
		}
		//剩余人数重新分配给次选
		cout << ans << "\n";
	}


	return 0;
}
