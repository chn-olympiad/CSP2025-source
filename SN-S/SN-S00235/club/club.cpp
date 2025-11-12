//SN-S00235 张正轩 西安高新第一中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int w, d;
	bool operator < (const node &x) const {
		return d > x.d;
	} 
};
priority_queue<node>q;
int a[100005], b[100005], c[100005];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int z, n, ans = 0;
	cin >> z;
	while (z--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(b, 0, sizeof(b));
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
		int m1 = 0, m2 = 0, m3 = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] > b[i] && a[i] > c[i]) {
				m1++;
			} 
			if (b[i] > a[i] && b[i] > c[i]) {
				m2++;
			} 
			if (c[i] > a[i] && c[i] > b[i]) {
				m3++;
			}
			cnt += max(max(a[i], b[i]), c[i]);
		}
		if (m1 <= n / 2 && m2 <= n / 2 && m3 <= n / 2) {
			cout << cnt << endl;
		}else if (m1 > n / 2){
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] > b[i] && a[i] > c[i]) {
					if ((long long)q.size() < n / 2) {
						ans += a[i];
						q.push((node){i, a[i] - max(b[i], c[i])});
					}else {
						if (a[q.top().w] + max(b[i], c[i]) < a[i] + max(b[q.top().w], c[q.top().w])) {
							ans = ans - a[q.top().w] + max(b[q.top().w], c[q.top().w]) + a[i];
							q.pop();
							q.push((node){i, a[i] - max(b[i], c[i])});
						}else {
							ans += max(b[i], c[i]);
						}
					}
				}else {
					ans += max(b[i], c[i]);
				}
			}
			cout << ans << endl;
		}else if (m2 > n / 2){
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (b[i] > a[i] && b[i] > c[i]) {
					if ((long long)q.size() < n / 2) {
						ans += b[i];
						q.push((node){i, b[i] - max(a[i], c[i])});
					}else {
						if (b[q.top().w] + max(a[i], c[i]) < b[i] + max(a[q.top().w], c[q.top().w])) {
							ans = ans - b[q.top().w] + max(a[q.top().w], c[q.top().w]) + b[i];
							q.pop();
							q.push((node){i, b[i] - max(a[i], c[i])});
						}else {
							ans += max(a[i], c[i]);
						}
					}
				}else {
					ans += max(a[i], c[i]);
				}
			}
			cout << ans << endl;
		}else if (m3 > n / 2){
			int ans = 0;
			for (int i = 1; i <= n; i++) {
				if (c[i] > a[i] && c[i] > b[i]) {
					if ((long long)q.size() < n / 2) {
						ans += c[i];
						q.push((node){i, c[i] - max(a[i], b[i])});
					}else {
						if (c[q.top().w] + max(a[i], b[i]) < c[i] + max(a[q.top().w], b[q.top().w])) {
							ans = ans - c[q.top().w] + max(a[q.top().w], b[q.top().w]) + c[i];
							q.pop();
							q.push((node){i, c[i] - max(a[i], b[i])});
						}else {
							ans += max(a[i], b[i]);
						}
					}
				}else {
					ans += max(a[i], b[i]);
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
} 

