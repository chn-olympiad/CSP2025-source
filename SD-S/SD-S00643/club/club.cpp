#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int T;
int n;
int _cnt1,_cnt2,_cnt3,tot;
long long ans = 0;
long long b[N];
struct Node {
	int id;
	long long data;
	bool operator < (const Node x) const {
		return data > x.data;
	}
}a[N][5];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while (T --) {
		_cnt1 = 0,_cnt2 = 0,_cnt3 = 0;
		tot = 0,ans = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n;i ++) {
			for (int j = 1;j <= 3;j ++) {
				scanf("%lld",&a[i][j].data);
				a[i][j].id = j;
			}
			stable_sort(a[i]+1,a[i]+1+3);
		}
		for (int i = 1;i <= n;i ++) {
			ans += a[i][1].data;
			if (a[i][1].id == 1)
				_cnt1 ++;
			else if (a[i][1].id == 2) 
				_cnt2 ++;
			else 
				_cnt3 ++;
		}
		if (_cnt1 > (n/2)) {
			for (int i = 1;i <= n;i ++) {
				if (a[i][1].id == 1) {
					b[++ tot] = a[i][1].data - a[i][2].data;
				}
			}
			stable_sort(b+1,b+1+tot);
			for (int i = 1;i <= _cnt1-(n/2);i ++) {
				ans -= b[i];
			}
		}
		else if (_cnt2 > (n/2)) {
			for (int i = 1;i <= n;i ++) {
				if (a[i][1].id == 2) {
					b[++ tot] = a[i][1].data - a[i][2].data;
				}
			}
			stable_sort(b+1,b+1+tot);
			for (int i = 1;i <= _cnt2-(n/2);i ++) {
				ans -= b[i];
			}
		}
		else if (_cnt3 > (n/2)) {
			for (int i = 1;i <= n;i ++) {
				if (a[i][1].id == 3) {
					b[++ tot] = a[i][1].data - a[i][2].data;
				}
			}
			stable_sort(b+1,b+1+tot);
			for (int i = 1;i <= _cnt3-(n/2);i ++) {
				ans -= b[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
