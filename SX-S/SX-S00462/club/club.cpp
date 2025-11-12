#include <bits/stdc++.h>
const int N = 1e5+10;
int a[N], b[N], c[N];
using namespace std;
queue<int>q1;
queue<int>q2;
queue<int>q3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long sum1 = 0, sum2 = 0, sum3 = 0, p1 = 0, p2 = 0, p3 = 0, ka, kb, kc;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) {
			q1.push(a[n - i + 1]);
		}
		ka = q1.front();
		sort(b + 1, b + n + 1);
		for (int i = 1; i <= n; i++) {
			q2.push(b[n - i + 1]);
		}
		kb = q2.front();
		sort(c + 1, c + n + 1);
		for (int i = 1; i <= n; i++) {
			q3.push(c[n - i + 1]);
		}
		kc = q3.front();
		for (int i = 1; i <= n; i++) {
			if (b[i] == 0 && c[i] == 0 && a[i] == q1.front() && n  / 2 >= p1) {
				sum1 += a[i];
				q1.pop();
				p1++;
			} else if (a[i] == 0 && c[i] == 0 && b[i] == q2.front() && n / 2 >= p2) {
				sum2 += b[i];
				q2.pop();
				p2++;
			} else if (a[i] == 0 && b[i] == 0 && c[i] == q3.front() && n / 2 >= p3) {
				sum3 += c[i];
				q3.pop();
				p3++;
			}
		}
		for (int i = 1; i <= 3; i++) {
			if (a[i] == 0 && b[i] != 0 && c[i] != 0) {
				if (b[i] > c[i] && n / 2 >= p2) {
					sum2 += b[i];
					if (b[i] == q2.front()) {
						q2.pop();
					}
					p2++;
				}
				if (b[i] < c[i] && n / 2 >= p3) {
					sum3 += c[i];
					if (c[i] == q3.front()) {
						q3.pop();
					}
					p3++;
				}
			} else if (b[i] == 0 && a[i] != 0 && c[i] != 0) {
				if (a[i] > c[i] && n / 2 >= p1) {
					sum1 += a[i];
					if (b[i] == q1.front()) {
						q1.pop();
					}
					p1++;
				}
				if (a[i] < c[i] && n / 2 >= p3) {
					sum3 += c[i];
					if (c[i] == q3.front()) {
						q3.pop();
					}
					p3++;
				}
			} else if (c[i] == 0 && b[i] != 0 && a[i] != 0) {
				if (a[i] > b[i] && n / 2 >= p1) {
					sum1 += a[i];
					if (a[i] == q1.front()) {
						q1.pop();
					}
					p1++;
				}
				if (b[i] > a[i] && n / 2 >= p2) {
					sum2 += b[i];
					if (b[i] == q2.front()) {
						q2.pop();
					}
					p2++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] == ka && b[i] == kb && c[i] == kc) {

			}
		}
		cout << sum1 + sum2 + sum3;
		fclose(stdin);
		fclose(stdout);
	}
	return 0;
}