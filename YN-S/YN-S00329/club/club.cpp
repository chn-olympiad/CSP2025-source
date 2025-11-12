#include <bits/stdc++.h>
using namespace std;
int t, n, maxnn = 0;
bool flag = false;

struct o {
	int b, c, a;
} s[100000];

bool cmp1(o x, o y) {
	return x.a > y.a ;
}

bool cmp2(o x, o y) {
	return x.b > y.b ;
}

bool cmp3(o x, o y) {
	return x.c > y.c ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	while (t--) {
		flag = false;
		cin >> n;
		maxnn = 0;

		for (int i = 0; i < n; i++) {

			cin >> s[i].a >> s[i].b >> s[i].c ;
		}

		sort(s, s + n, cmp1);

		for (int i = 1; i < n; i++)

			if (s[i].b != 0 || s[i].c != 0) {
				flag = true;
				break;
			}

		if (!flag) {
			maxnn += max(s[0].b, s[0].c );
			s[0].a = 0;

			for (int i = 0; i < ((n / 2) + 1); i++)

				maxnn += s[i].a ;
		} else {
			for (int i = 0; i < (n / 2); i++) {

				if (s[i].a != 0 && s[i].a >= s[i].b && s[i].a >= s[i].c ) {
					maxnn += s[i].a ;
					s[i].b = 0;
					s[i].c = 0;
				}
			}

			sort(s, s + n, cmp2);

			for (int i = 0; i < (n / 2); i++) {

				if (s[i].b != 0 && s[i].b >= s[i].c && s[i].b >= s[i].a ) {
					maxnn += s[i].b ;
					s[i].a = 0;
					s[i].c = 0;
				}
			}

			sort(s, s + n, cmp3);

			for (int i = 0; i < (n / 2); i++) {

				if (s[i].c != 0 && s[i].c >= s[i].b && s[i].c >= s[i].a ) {
					maxnn += s[i].c ;
					s[i].b = 0;
					s[i].a = 0;
				}
			}
		}

		cout << maxnn << endl;
	}

	return 0;
}