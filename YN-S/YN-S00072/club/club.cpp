#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001], c[100001];



struct nl {
	int a, b, c;
	int flag;
};
nl x[100001];

int cmp(nl x, nl y) {
	return x.a > y.a;
}

int cmp1(nl a, nl b) {
	return a.b > b.b;
}

int cmp2(nl m, nl n) {
	return m.c > n.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		long long n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
			x[i].flag = 1;
		}
		sort(x + 1, x + n + 1, cmp);
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (x[i].a >= x[i].b && x[i].a >= x[i].c && cnt < n / 2) {
				ans += x[i].a;
				cnt++;
				x[i].flag = 0;
			}
		}
		sort(x + 1, x + n + 1, cmp1);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (x[i].b >= x[i].a && x[i].b >= x[i].c && cnt < n / 2 && x[i].flag == 1) {
				ans += x[i].b;
				cnt++;
				x[i].flag = 0;
			}
		}
		sort(x + 1, x + n + 1, cmp2);
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (x[i].c >= x[i].a && x[i].c >= x[i].b && cnt < n / 2 && x[i].flag == 1) {
				ans += x[i].c;
				cnt++;
			}
		}
		cout << ans << endl;
	}
//拼尽全力无法战胜
	return 0;
}