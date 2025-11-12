#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int t,n;
int a[N][4],w[N][4][4];
struct node {
	int wei,idx,xu;
};
bool fA = true,fB = true;
bool cmp(node x,node y) {
	return x.wei > y.wei;
}
void solveA() {
	ll adv = 0, ans = 0;
	for (int i = 1; i <= n; i++) adv += a[i][1];
	adv = adv / n;
	for (int i = 1; i <= n; i++) {
		if (a[i][1] - adv > 0) ans += a[i][1];
	}
	cout << ans << endl;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("clun.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][2]) fA = false;
			if (a[i][3]) fB = false;
		}
		if (fA) {
			solveA();
			return 0;
		}
		if (n < 1e4) {
			int cnt = 0;
			node x[3*n+1];
			bool f[n];
			int num[4] = {0,0,0,0};
			for (int i = 1; i <= n; i++) {
				f[i] = 0;
				x[++cnt].wei  = 2*a[i][1]-a[i][2]-a[i][3],x[cnt].idx = 1,x[cnt].xu = i;
				x[++cnt].wei  = 2*a[i][2]-a[i][1]-a[i][3],x[cnt].idx = 2,x[cnt].xu = i;
				x[++cnt].wei  = 2*a[i][3]-a[i][1]-a[i][2],x[cnt].idx = 3,x[cnt].xu = i;
			}
			sort(x+1,x+1+3*n,cmp);
			ll ans = 0;
			cnt = 0;
			for (int i = 1; cnt < n && i <= 3*n; i++) {
				if (num[x[i].idx] < n/2 && f[x[i].xu] == 0) {
					ans += a[x[i].xu][x[i].idx];
					num[x[i].idx]++;
					f[x[i].xu] = true;
					cnt++;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}

