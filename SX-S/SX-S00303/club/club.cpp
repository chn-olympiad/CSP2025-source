#include <bits/stdc++.h>
//#define pair<int,int>
using namespace std;

int b[100005], T, x[100005], y[100005], z[100005], n, sum, cnt1, cnt2, cnt3;

int main() {
	freopen("club3.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(x, 0, sizeof x);
		memset(y, 0, sizeof y);
		memset(z, 0, sizeof z);
		memset(b, 0, sizeof b);
		priority_queue<pair<int, int>> q1;
		priority_queue<pair<int, int>> q2;
		priority_queue<pair<int, int>> q3;
		sum = 0;
		cnt1 = cnt2 = cnt3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> x[i] >> y[i] >> z[i];
			q1.push({x[i], i});
			q2.push({y[i], i});
			q3.push({z[i], i});
		}
		for (int i = 1; i <= 3 * n; i++) {
			if (i % 3 == 1 && cnt1 < n / 2) {
				cnt1++;
				pair<int, int> f = q1.top();
				q1.pop();
				if (b[f.second] != 0) {
					if (b[f.second] == 2) {
						if (y[f.second] < f.first) {
							b[f.second] = 1;
							sum -= y[f.second];

							sum += f.first;
						} else {

							cnt1--;
							continue;
						}
					}
					if (b[f.second] == 3) {
						if (z[f.second] < f.first) {
							b[f.second] = 1;
							sum -= z[f.second];

							sum += f.first;
						} else {

							cnt1--;
							continue;
						}
					}
				} else {
					sum += f.first;
					b[f.second] = 1;
//					cout << "???" << endl;
				}
			} else if (i % 3 == 2 && cnt2 < n / 2) {
				cnt2++;
				pair<int, int> f = q2.top();
				q2.pop();
				if (b[f.second] != 0) {
					if (b[f.second] == 1) {
						if (x[f.second] < f.first) {
							sum -= x[f.second];

							sum += f.first;
						} else {

							cnt2--;
							continue;
						}
					}
					if (b[f.second] == 3) {
						if (z[f.second] < f.first) {
							b[f.second] = 2;
							sum -= z[f.second];

							sum += f.first;
						} else {

							cnt2--;
							continue;
						}
					}
				} else {
					sum += f.first;
					b[f.second] = 2;
				}
			} else if (i % 3 == 0 && cnt3 < n / 2) {
				cnt3++;
				pair<int, int> f = q3.top();
				q3.pop();
				if (b[f.second] != 0) {
					if (b[f.second] == 2) {
						if (y[f.second] < f.first) {
							b[f.second] = 3;
							sum -= y[f.second];

							sum += f.first;
						} else {

							cnt3--;
							continue;
						}
					}
					if (b[f.second] == 1) {
						if (x[f.second] < f.first) {
							b[f.second] = 3;
							sum -= x[f.second];

							sum += f.first;
						} else {

							cnt3--;
							continue;
						}
					}
				} else {
					sum += f.first;
					b[f.second] = 3;
				}
			}
//			cout << "PPP " << i << " " << sum << endl;
		}
		cout << sum << endl;
	}
	return 0;
}