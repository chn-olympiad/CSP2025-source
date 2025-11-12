#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int a[N][5];
int q1[N], q2[N], q3[N], s5;
void dfs(int now, int s1, int s2, int s3, int s4, int n) {
	if(s1 > n / 2) return ;
	if(s2 > n / 2) return ;
	if(s3 > n / 2) return ;
	if(now == n + 1) {
		s5 = max(s5, s4);
		return ;
	}
	dfs(now + 1, s1 + 1, s2, s3, s4 + a[now][1], n);
	dfs(now + 1, s1, s2 + 1, s3, s4 + a[now][2], n);
	dfs(now + 1, s1, s2, s3 + 1, s4 + a[now][3], n);
}
int read() {
	int f = 1, s = 0;char ch = getchar();
	while(! isdigit(ch)) {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return f * s;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while(T --) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; i ++) {
			a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
			if(a[i][1] > a[i][2] && a[i][1] > a[i][3]) a[i][4] = 1;
			if(a[i][2] > a[i][1] && a[i][2] > a[i][3]) a[i][4] = 2;
			if(a[i][3] > a[i][2] && a[i][3] > a[i][1]) a[i][4] = 3;
		}
		if(n <= 10) {
			s5 = -1;
			dfs(0, 0, 0, 0, 0, n);
			cout << s5 << endl;
			continue;
		}
		memset(q1, 0, sizeof q1);
		memset(q2, 0, sizeof q2);
		memset(q3, 0, sizeof q3);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for(int i = 1; i <= n; i ++) {
			if(a[i][4] == 1 && cnt1 < n / 2) q1[++ cnt1] = i;
			else {
				int ma = -1, pos = -1;
				if(cnt1 >= n / 2) {
					for(int j = 1; j <= cnt1; j ++) {
						int x = a[i][1] + max(a[q1[j]][2], a[q1[j]][3]), y = a[q1[j]][1] + max(a[i][2], a[i][3]);
						if(x > y) {
							if(x - y > ma) {
								ma = x - y;
								pos = j;
							}
						}
					}
					if(ma == -1) continue;
					if(a[q1[pos]][2] > a[q1[pos]][3]) q2[++ cnt2] = q1[pos];
					else q3[++ cnt3] = q1[pos];
					q1[pos] = i;
				}
			}
			if(a[i][4] == 2 && cnt2 < n / 2) q2[++ cnt2] = i;
			else {
				int ma = -1, pos = -1;
				if(cnt2 >= n / 2) {
					for(int j = 1; j <= cnt2; j ++) {
						int x = a[i][2] + max(a[q2[j]][1], a[q2[j]][3]), y = a[q2[j]][2] + max(a[i][1], a[i][3]);
						if(x > y) {
							if(x - y > ma) {
								ma = x - y;
								pos = j;
							}
						}
					}
					if(ma == -1) continue;
					if(a[q2[pos]][1] > a[q2[pos]][3]) q1[++ cnt1] = q2[pos];
					else q3[++ cnt3] = q2[pos];
					q2[pos] = i;
				}
			}
			if(a[i][4] == 3 && cnt3 < n / 2) q3[++ cnt3] = i;
			else {
				int ma = -1, pos = -1;
				if(cnt3 >= n / 2) {
					for(int j = 1; j <= cnt2; j ++) {
						int x = a[i][3] + max(a[q3[j]][1], a[q3[j]][2]), y = a[q3[j]][3] + max(a[i][1], a[i][2]);
						if(x > y) {
							if(x - y > ma) {
								ma = x - y;
								pos = j;
							}
						}
					}
					if(ma == -1) continue;
					if(a[q3[pos]][1] > a[q3[pos]][2]) q1[++ cnt1] = q3[pos];
					else q2[++ cnt2] = q3[pos];
					q3[pos] = i;
				}
			}
		}
		int ans = 0;
		for(int i = 1; i <= cnt1; i ++) ans += a[q1[i]][1];
		for(int i = 1; i <= cnt2; i ++) ans += a[q2[i]][2];
		for(int i = 1; i <= cnt3; i ++) ans += a[q3[i]][3];
		cout << ans << endl;
	}
	return 0;
}
