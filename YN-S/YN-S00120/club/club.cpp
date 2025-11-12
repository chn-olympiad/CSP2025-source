#include <bits/stdc++.h>
using namespace std;

struct node {
	int ans1, ans2, ans3;
} a[10001];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int k;
	cin >> k;
	int n;
	cin >> n;
	long long sum = 0, num = 0;
	long long d1 = 0, d2 = 0, d3 = 0;

	while (k--) {
		for (int i = 1; i <= n; i++) {

			cin >> a[i].ans1 >> a[i].ans2 >> a[i].ans3;
			num = max(a[i].ans1, max(a[i].ans2, a[i].ans3));

			if (num == a[i].ans1) {
				d1++;
				sum += num;
			} else if (num == a[i].ans2) {
				d2++;
				sum += num;
			} else if (num == a[i].ans3) {
				d3++;
				sum += num;
			}

			if (d1 > n / 2) {
				sum -= num;
				num = max(a[i].ans2, a[i].ans3);
				sum += num;

				if (num == a[i].ans2) {
					d2++;
				} else {
					d3++;
				}
			} else if (d2 > n / 2) {
				sum -= num;
				num = max(a[i].ans1, a[i].ans3);
				sum += num;

				if (num == a[i].ans1) {
					d1++;
				} else {
					d3++;
				}
			} else if (d3 > n / 2) {
				sum -= num;
				num = max(a[i].ans1, a[i].ans2);
				sum += num;

				if (num == a[i].ans1) {
					d1++;
				} else {
					d2++;
				}
			}
		}

		cout << sum;
		sum = 0;
		num = 0;
		d1 = 0;
		d2 = 0;
		d3 = 0;
	}

}