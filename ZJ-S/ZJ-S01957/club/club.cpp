#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, a[N][4], dt[N], cnt1, cnt2, cnt3, fr[N], ans;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		cnt1 = cnt2 = cnt3 = ans = 0;
		while(!q.empty()) q.pop();
		for(int i = 1;i <= n;i++) {
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				cnt1++; fr[i] = 1; ans += a[i][1];
				if(a[i][2] >= a[i][3]) dt[i] = a[i][1] - a[i][2];
				else dt[i] = a[i][1] - a[i][3];
			} else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				cnt2++; fr[i] = 2; ans += a[i][2];
				if(a[i][1] >= a[i][3]) dt[i] = a[i][2] - a[i][1];
				else dt[i] = a[i][2] - a[i][3];
			} else {
				cnt3++; fr[i] = 3; ans += a[i][3];
				if(a[i][1] >= a[i][2]) dt[i] = a[i][3] - a[i][1];
				else dt[i] = a[i][3] - a[i][2];
			}
		}
		if(cnt1 > n / 2) {
			for(int i = 1;i <= n;i++) {
				if(fr[i] == 1) q.push(dt[i]);
			}
			while(cnt1 > n / 2) {
				int x = q.top(); q.pop();
				ans -= x; cnt1--;
			}
		} else if(cnt2 > n / 2) {
			for(int i = 1;i <= n;i++) {
				if(fr[i] == 2) q.push(dt[i]);
			}
			while(cnt2 > n / 2) {
				int x = q.top(); q.pop();
				ans -= x; cnt2--;
			}
		} else if(cnt3 > n / 2) {
			for(int i = 1;i <= n;i++) {
				if(fr[i] == 3) q.push(dt[i]);
			}
			while(cnt3 > n / 2) {
				int x = q.top(); q.pop();
				ans -= x; cnt3--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
