#include <bits/stdc++.h>
using namespace std;

struct stu {
	int a, b, c;
	int maxx, xx;
	int midd, dd;
	int minn, nn;
} s[100001];

bool cmpa(stu x, stu y) {
	if (x.a < y.a)
		return x.a > y.a;
	if (x.a == y.a) {
		return x.b < y.b;
		if (x.b == y.b)
			return x.c < y.c;
	}
}

bool cmpb(stu x, stu y) {
	if (x.b < y.b)
		return x.b > y.b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i].a >> s[i].b >> s[i].c;
		if (n == 2) {
			int maxx = 0;
			maxx = max(maxx, s[1].a + s[2].b);
			maxx = max(maxx, s[1].a + s[2].c);
			maxx = max(maxx, s[1].b + s[2].c);
			maxx = max(maxx, s[1].b + s[2].a);
			maxx = max(maxx, s[1].c + s[2].a);
			maxx = max(maxx, s[1].c + s[2].b);
			cout << maxx << endl;
		} else if (n == 4) {
			int maax = 0;
			int as[10] = {s[1].a, s[2].a, s[3].a, s[4].a};
			int bs[10] = {s[1].b, s[2].b, s[3].b, s[4].b};
			int cs[10] = {s[1].c, s[2].c, s[3].c, s[4].c};
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						for (int q = 0; q < 3; q++) {
							maax = max(as[i] + bs[j] + cs[k], maax);
						}
					}
				}
			}
			cout << maax << endl;
		} else {
			int sum = 0;
			sort(s + 1, s + n + 1, cmpa);
			for (int i = 1; i <= n / 2; i++)
				sum += s[i].a;
			sort(s + 1 + n / 2, s + n + 1, cmpb);
			for (int i = n / 2 + 1; i <= n; i++)
				sum += s[i].b;
			cout << sum << endl;
		}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
