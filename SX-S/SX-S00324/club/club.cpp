#include <bits/stdc++.h>
#define int long long
#define NOI(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

int a[4][100005];
int T;

struct node {
	int id, b1, b2, b3, ls;
	operator <(const node cc)const {
		return ls < cc.ls;
	}
};
priority_queue<pair<int, node> >m[4];

signed main() {
	NOI("club")
	scanf("%d", &T);
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[1][i] >> a[2][i] >> a[3][i];
		}
//		sort(a[1] + 1, a[1] + n + 1, cmp);
//		sort(a[2] + 1, a[2] + n + 1, cmp);
//		sort(a[3] + 1, a[3] + n + 1, cmp);
		int ans = 0, mx = n / 2;
		for (int i = 1; i <= 3; i++) {
			while (m[i].size()) {
				m[i].pop();
			}
		}
		for (int i = 1; i <= n; i++) {
			int b1 = 0, b2 = 0, b3 = 0;
			for (int jj = 1; jj <= 3; jj++)
				if (a[jj][i] >= a[b1][i]) {
					b1 = jj;
					b2 = b1;
					b3 = b2;
				}
			if (m[b1].size() < mx) {
				m[b1].push(make_pair(-a[b1][i], node{i, b1, b2, b3, -a[b1][i]}));
				ans += a[b1][i];
//				cout << "i=" << i << "  部门:" << b1 << "  当前成员:" << m[b1].size() << "  满意度:" << a[b1][i] << " ans=" << ans <<
//				     endl;
			} else if (-m[b1].top().first < a[b1][i]) {
				node hm = m[b1].top().second;
				m[b1].pop();
				m[b1].push(make_pair(-a[b1][i], node{i, b1, b2, b3, -a[hm.b1][i]}));
				ans -= a[b1][hm.id];
				ans += a[b1][i];
				//d2b
				if (m[hm.b2].size() < mx) {
					m[hm.b2].push(make_pair(-a[hm.b2][i], node{i, b1, b2, hm.b3, -a[hm.b2][i]}));
					ans += a[hm.b2][i];
//					cout << "1处理一i=" << i << "  部门:" << hm.b2 << "  当前成员:" << m[hm.b2].size() << "  满意度:" << a[hm.b2][i] <<
//					     " ans=" << ans <<
//					endl;
				} else if (m[hm.b3].size() < mx) {
					m[hm.b3].push(make_pair(-a[hm.b3][i], node{i, b1, b2, b3, -a[hm.b3][i]}));
					ans += a[hm.b3][i];
//					cout << "1处理二i=" << i << "  部门:" << hm.b3 << "  当前成员:" << m[hm.b3].size() << "  满意度:" << a[hm.b3][i] <<
//					     " ans=" << ans << endl;
				}
			} else if (m[b2].size() < mx) {
				m[b2].push(make_pair(-a[b2][i], node{i, b1, b2, b3, -a[b2][i]}));
				ans += a[b2][i];
//				cout << "i=" << i << "  部门:" << b2 << "  当前成员:" << m[b2].size() << "  满意度:" << a[b2][i] << " ans=" << ans <<
//				     endl;
			}
			//处理2
			else if (-m[b2].top().first < a[b2][i]) {
				node hm = m[b2].top().second;
				m[b2].pop();
				m[b2].push(make_pair(-a[b2][i], node{i, b1, b2, b3, -a[hm.b2][i]}));
				ans -= a[b2][hm.id];
				ans += a[b2][i];
				//d2b
				if (m[hm.b3].size() < mx) {
					m[hm.b3].push(make_pair(-a[hm.b3][i], node{i, b1, b2, b3, -a[hm.b3][i]}));
					ans += a[hm.b3][i];
				}
//				cout << "2处理二i=" << i << "  部门:" << hm.b3 << "  当前成员:" << m[hm.b3].size() << "  满意度:" << a[hm.b3][i] <<
//				     " ans=" << ans <<
//				endl;
			} else if (m[b3].size() < mx) {
				m[b3].push(make_pair(-a[b3][i], node{i, b1, b2, b3, -a[b3][i]}));
				ans += a[b3][i];
//				cout << "i=" << i << "  部门:" << b3 << "  当前成员:" << m[b3].size() << "  满意度:" << a[b3][i] << " ans=" << ans <<
//				     endl;
			}
		}
		cout << ans << endl;
//					}
//		for (int i = 1; i <= 3; i++) {
//			for (int k = 1; k <= mx; k++) {
////				for (int j = 1; j <= n; j++) {
////					int id1 = 0;
//				if (!mp.count(a[i][j].id)) {
//					int id1 = 0;
//					int zd = a[i][k];
////				if(dp[i-1][j]+a[j]>dp[j]){
////					id1=a[i].id;
////					dp[i]=max(dp[i-1][j]+a[j],dp[i]);
////				}
////			}
//
//					for (int jj = 1; jj <= 3; jj++) {
//						for (int ii = 1; ii <= n; ii++) {
//							if (a[jj][ii].id == a[jj][kk].id) {
//								if (a[i][j] >= zd) {
//									zd = a[i][j]
//									id1 = ii;
//								}
//								continue;
//							}
//						}
//					}
//					if (!mp.count(a[i][j].id)) {
//						mp[a[i].id] = i;
//					}
//				}
//			}
//		}
	}
	return 0;
}