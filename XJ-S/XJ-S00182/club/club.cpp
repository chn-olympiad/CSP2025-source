#include <bits/stdc++.h>
using namespace std;
int maxn(int a,int b,int c) {

	if(a > b) {
		if(a > c) {
			return 1;
		} else {
			return 3;
		}
	} else if(a > c) {
		if(a > b) {
			return 1;
		} else {
			return 2;
		}
	} else if(b > c) {
		if(b > a) {
			return 2;
		} else {
			return 1;
		}
	}
}
struct anx {
	int val[1000001],siz[1000001];
} ans1[5];

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int l;
	cin >> l;
	for(int i = 1; i <= l; i++) {
		int ans = 0;
		int n;
		cin >> n;
		int a[100001][5];
		int t1[10];
		memset(t1,0,sizeof(t1));
		memset(a,0,sizeof(a));
		for(int j = 1; j <= n; j++) {
			int x,y,z;
			cin >> x >> y >> z;
			a[j][1] = x;
			a[j][2] = y;
			a[j][3] = z;
		}
		for(int j = 1; j <= n; j++) {
			int tmp = maxn(a[j][1],a[j][2],a[j][3]);
			if(t1[tmp] < n / 2) {
				t1[tmp]++;
				ans1[tmp].siz[t1[tmp]] = j;
				ans1[tmp].val[t1[tmp]] = max(a[j][1],max(a[j][2],a[j][3]));
				
			} else {
				int minx = 1e9 + 7;
				int siz1 = 0;
				for(int k = 1; k <= t1[tmp]; k++) {
					if(ans1[tmp].val[k] < minx) {
						minx = ans1[tmp].val[k];
						siz1 = k;
					}
				}
				if(a[j][tmp] > minx) {
					ans1[tmp].val[siz1] = max(a[j][1],max(a[j][2],a[j][3]));
					ans1[tmp].siz[siz1] = j;
				}
			}

		}
		for(int j = 1; j <= 3; j++) {
			for(int x = 1; x <= t1[j]; x++) {
				ans += ans1[j].val[x];
			}
		}
		/*for(int j = 1; j <= 3; j++) {
			for(int x = 1; x <= t1[j]; x++) {
				cout << j << ":"<< ans1[j].siz[x] << ":"  <<ans1[j].val[x] << " ";
			}
			cout << endl;
		}*/
		cout << ans <<endl;
	}
	return 0;
}
