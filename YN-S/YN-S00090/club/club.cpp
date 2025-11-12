#include <bits/stdc++.h>
using namespace std;
int sj, b[100005][4], maxn[100005];
int cha[100005];
int n[100005];
int m[100005][4];
int t1, t2, a, o = 1;
int ans = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> sj;
	for (int i = 1; i <= sj; i++) {
		cin >> n[i];
		for (int j = 1; j <= n[i]; j++) {
			cin >> m[j][1];
			cin >> m[j][2];
			cin >> m[j][3];
			if (m[j][1] > m[j][2]) {
				if (m[j][2] > m[j][3]) {
					b[j][1] = 1;
					b[j][2] = 2;
					b[j][3] = 3;
					maxn[j] = m[j][1];
					cha[j] = m[j][1] - m[j][2];
				}
			}
			if (m[j][1] > m[j][2]) {
				if (m[j][3] > m[j][1]) {
					b[j][1] = 3;
					b[j][2] = 1;
					b[j][3] = 2;
					maxn[j] = m[j][3];
					cha[j] = m[j][3] - m[j][1];
				}
			}
			if (m[j][2] > m[j][1]) {
				if (m[j][1] > m[j][3]) {
					b[j][1] = 2;
					b[j][2] = 1;
					b[j][3] = 3;
					maxn[j] = m[j][2];
					cha[j] = m[j][2] - m[j][1];
				}
			}
			if (m[j][2] > m[j][1]) {
				if (m[j][3] > m[j][2]) {
					b[j][1] = 3;
					b[j][2] = 2;
					b[j][3] = 1;
					maxn[j] = m[j][3];
					cha[j] = m[j][3] - m[j][2];
				}
			}
			if (m[j][1] > m[j][3]) {
				if (m[j][3] > m[j][2]) {
					b[j][1] = 1;
					b[j][2] = 3;
					b[j][3] = 2;
					maxn[j] = m[j][1];
					cha[j] = m[j][1] - m[j][3];
				}
			}
			if (m[j][3] > m[j][1]) {
				if (m[j][2] > m[j][3]) {
					b[j][1] = 2;
					b[j][2] = 3;
					b[j][3] = 1;
					maxn[j] = m[j][2];
					cha[j] = m[j][2] - m[j][3];
				}
			}
		}
		maxn[0] = 0;
		int r[5] = {0};
		for (int j = 1; j <= n[i]; j++) {
			r[b[j][1]]++;
			if (r[b[j][1]] > n[i] / 2) {
				for (int t = o; t <= n[i]; t++) {
					if (o == t)
						continue;
					r[b[j][1]]--;
					ans = ans + maxn[j]  - cha[t];
					o = t;
					break;
					cout << ans << endl;
				}
			} else {
				ans = ans + maxn[j];
				cout << ans << endl;
			}
		}
	}
	cout << ans;
}