#include <bits/stdc++.h>
using namespace std;

struct want {
	int a, b, c, ab, ac, bc, choose, next_choose;
};
vector<want> wants(1000);
vector<int> wanta;
vector<int> wantb;
vector<int> wantc;

bool cmp(want x, want y) {
	if (x.next_choose == 1) {
		return x.a > y.a;
	}
	if (x.next_choose == 2) {
		return x.b > y.b;
	}
	if (x.next_choose == 3) {
		return x.c > y.c;
	}
}

bool cmp1(want x, want y) {
	return x.a > y.a;
}

void chooses(int i) {
	if (abs(wants[i].ab) > abs(wants[i].ac)) {
		if (abs(wants[i].ab) > abs(wants[i].bc)) {
			if (wants[i].a > wants[i].b) {
				wants[i].choose = 1;
				wants[i].next_choose = 2;
			} else {
				wants[i].choose = 2;
				wants[i].next_choose = 1;
			}
		} else {
			if (wants[i].b > wants[i].c) {
				wants[i].choose = 2;
				wants[i].next_choose = 3;
			} else {
				wants[i].choose = 3;
				wants[i].next_choose = 2;
			}
		}
	} else {
		if (abs(wants[i].ab) > abs(wants[i].bc)) {
			if (wants[i].a > wants[i].c) {
				wants[i].choose = 1;
				wants[i].next_choose = 3;
			} else {
				wants[i].choose = 3;
				wants[i].next_choose = 1;
			}
		} else {
			if ((wants[i].ac) > abs(wants[i].bc)) {
				if (wants[i].a > wants[i].c) {
					wants[i].choose = 1;
					wants[i].next_choose = 3;
				} else {
					wants[i].choose = 3;
					wants[i].next_choose = 1;
				}
			} else {
				if (wants[i].b > wants[i].c) {
					wants[i].choose = 2;
					wants[i].next_choose = 3;
				} else {
					wants[i].choose = 3;
					wants[i].next_choose = 2;
				}
			}

		}
	}
	switch (wants[i].choose) {
		case 1:
			wanta.push_back(i);
			break;
		case 2:
			wantb.push_back(i);
			break;
		case 3:
			wantc.push_back(i);
			break;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	bool isA = true;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> wants[i].a;
			cin >> wants[i].b;
			cin >> wants[i].c;
			wants[i].ab = wants[i].a - wants[i].b;
			wants[i].ac = wants[i].a - wants[i].c;
			wants[i].bc = wants[i].b - wants[i].c;
			if (!(wants[i].b == 0 && wants[i].c == 0)) {
				isA = false;
			}
		}
		if (isA) {
			sort(wants.begin() + 1, wants.begin() + n + 1, cmp1);
			for (int i = 0; i <= n >> 1; i++) {
				ans += wants[i].a;
			}
			cout << ans;
		} else {
			for (int i = 1; i <= n; i++) {
				chooses(i);
			}
			sort(wants.begin() + 1, wants.begin() + n + 1, cmp);

			cout << ans;
		}
	}

	return 0;
}
