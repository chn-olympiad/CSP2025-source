#include <bits/stdc++.h>
using namespace std;

struct cpl {
	int n1, n2, m1, m2;
};

bool cmp(cpl a, cpl b) {
	if (a.m1 != b.m1)
		return a.m1 > b.m1;
	else
		return a.m2 > b.m2;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, sum = 0;
		cpl s[100000];
		cin >> n;
		for (int j = 1; j <= n; j++) {
			int a_1, a_2, a_3;
			cin >> a_1 >> a_2 >> a_3;
			int mn = max(max(a_1, a_2), a_3);
			s[j].m1 = mn;
			if (a_1 == mn) {
				s[j].n1 = 1;
				if (max(a_2, a_3) == a_2) {
					s[j].m2 = a_2;
					s[j].n2 = 2;
				} else {
					s[j].m2 = a_3;
					s[j].n2 = 3;
				}
			}
			if (a_2 == mn) {
				s[j].n1 = 2;
				if (max(a_1, a_3) == a_1) {
					s[j].m2 = a_1;
					s[j].n2 = 1;
				} else {
					s[j].m2 = a_3;
					s[j].n2 = 3;
				}
			}
			if (a_3 == mn) {
				s[j].n1 = 3;
				if (max(a_2, a_1) == a_2) {
					s[j].m2 = a_2;
					s[j].n2 = 2;
				} else {
					s[j].m2 = a_1;
					s[j].n2 = 1;
				}
			}
		}
		sort(s + 1, s + n + 1, cmp);
		int nn[4];
		for (int j = 1; j <= n; j++) {
			if (nn[s[j].n1] <= n / 2) {
				nn[s[j].n1]++;
				sum += s[j].m1;
			} else {
				nn[s[j].n2]++;
				sum += s[j].m2;
			}
		}
		cout << sum << endl;
	}
	return 0;
}