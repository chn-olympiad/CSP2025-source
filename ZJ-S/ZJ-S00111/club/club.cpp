#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n, cnt[3], ans;
struct node {
	pair<int,int>/*a,i*/ a[3];
} s[N];
bool cmp(node x, node y) {
	return x.a[2].first + max(y.a[0].first, y.a[1].first) > 
		   y.a[2].first + max(x.a[0].first, x.a[1].first);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	while(T--) {
		memset(cnt, 0, sizeof cnt); ans = 0;
		cin >> n;
		for(int i=0 ; i<n ; i++) {
			for(int j=0,x ; j<3 ; j++) {
				cin >> x;
				s[i].a[j] = {x, j};
			} sort(s[i].a, s[i].a + 3);
		} sort(s, s+n, cmp);
		for(int i=0 ; i<n ; i++) {
			for(int j=2 ; j>=0 ; j--) {
				if(cnt[s[i].a[j].second] < n/2) {
					cnt[s[i].a[j].second] ++;
					ans += s[i].a[j].first;
					break;
				}
			}
		} printf("%d\n", ans);
	}
	return 0;
}
