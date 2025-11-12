#include <bits/stdc++.h>
using namespace std;
int t, n, ans;

struct node {
	int s1, s2, s3;
	int mx;
} a[100001];

struct nodets2 {
	int c;
	int num;
};

bool cmp1(int x, int y) {
	return x > y;
}

bool cmpp1(nodets2 x, nodets2 y) {
	return x.c > y.c;
}

bool cmpp2(nodets2 x, nodets2 y) {
	return x.c < y.c;
}

void exchange(node x, node y) {
	if (x.s1 > y.s1)
		swap(x, y);
	else if (x.s1 == y.s1) {
		if (x.s2 > y.s2)
			swap(x, y);
		else if (x.s2 == y.s2 && x.s3 > y.s3)
			swap(x, y);
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		bool tsa = true, tsb = true;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].s1 >> a[i].s2 >> a[i].s3;
			a[i].mx = max(a[i].s1, max(a[i].s2, a[i].s3));
			if (a[i].s2 != 0)
				tsa = false;
			else if (a[i].s3 != 0)
				tsa = false, tsb = false;
		}
		if (tsa == true) {	//льепA
			int b[n + 1];
			for (int i = 1; i <= n; i++)
				b[i] = a[i].s1;
			sort(b + 1, b + n + 1, cmp1);
			for (int i = 1; i <= n / 2; i++)
				ans += b[i];
			cout << ans << endl;
			continue;
		}
		if (tsb == true) {	//льепB
			nodets2 b[n + 1];
			for (int i = 1; i <= n; i++) {
				b[i].c = a[i].s1 - a[i].s2;
				b[i].num = i;
			}
			sort(b + 1, b + n + 1, cmpp1);
			for (int i = 1; i <= n / 2; i++)
				ans += a[b[i].num].s1;
			sort(b + 1, b + n + 1, cmpp2);
			for (int i = 1; i <= n / 2; i++)
				ans += a[b[i].num].s2;
			cout << ans << endl;
			continue;
		}
		//Ё╒йт
		for (int i = 1; i < n; i++) {
			exchange(a[i], a[i + 1]);
		}
		int num1 = 0, num2 = 0, num3 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i].mx == a[i].s1) {
				if (num1 >= n / 2) {
					if (a[i].s2 > a[i].s3 && num2 < n / 2) {
						ans += a[i].s2;
						num2++;
					} else {
						ans += a[i].s3;
						num3++;
					}
				} else {
					ans += a[i].s1;
					num1++;
				}
			} else if (a[i].mx == a[i].s2) {
				if (num2 >= n / 2) {
					if (a[i].s1 > a[i].s3 && num1 < n / 2) {
						ans += a[i].s1;
						num1++;
					} else {
						ans += a[i].s3;
						num3++;
					}
				} else {
					ans += a[i].s2;
					num2++;
				}
			} else {
				if (num3 >= n / 2) {
					if (a[i].s1 > a[i].s2 && num1 < n / 2) {
						ans += a[i].s1;
						num1++;
					} else {
						ans += a[i].s2;
						num2++;
					}
				} else {
					ans += a[i].s3;
					num3++;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}