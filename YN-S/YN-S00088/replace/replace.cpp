#include <bits/stdc++.h>
using namespace std;
int n, q, cnt;
string s, e;

struct ss {
	string st;
	string en;
} a[200005];

void pd(string ns, string daiti) {
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == ns[0]) {
			for (int j = 0; j < ns.size(); j++) {

				if (s[i + j] != ns[j]) {
					break;
				}
			}

			for (int j = 0; j < ns.size(); j++) {

				s[i] = daiti[i];
				return ;
			}
		}
	}

	return ;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d %d", &n, &q);

	for (int i = 1; i <= n; i++) {

		cin >> a[i].st >> a[i].en;
	}

	for (int i = 1; i <= q; i++) {

		cin >> s >> e;
		cnt = 0;

		for (int i = 1; i <= n; i++) {

			pd(a[i].st, a[i].en);

			if (s == e) {
				cnt++;
				break;
			}
		}

		printf("%d\n", cnt);
	}

	return 0;
}
