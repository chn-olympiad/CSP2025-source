//刘益铭 SN-S00080 西安高新第一中学
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = 105;

int T,n,ans,f[M][M][M];

bool ff1 = true;

struct node {
	int a1,a2,a3;
};

node a[N];

bool cmp(node x,node y) {
	return x.a1 > y.a1;
}

void solve() {
	cin >> n;
	ans = 0;
	memset(f,0,sizeof(f));
	for(int i = 1;i<=n;i++) {
		cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		if(a[i].a1 != 0 || a[i].a2 != 0) ff1 = false;
	}
	if(ff1) {
		sort(a+1,a+1+n,cmp);
		for(int i = 1;i<=n/2;i++) ans += a[i].a1;
		cout << ans << '\n';
		return;
	}
	if(n > 200) {
		for(int i = 1;i<=n;i++) ans += max(a[i].a1,max(a[i].a2,a[i].a3));
		cout << ans << '\n';
		return;
	}
	for(int i = 0;i<=n/2;i++) {
		for(int j = 0;j<=n/2;j++) {
			for(int k = 0;k<=n/2;k++) {
				if(i + j + k > n) break;
				if(i != 0) f[i][j][k] = max(f[i][j][k],f[i-1][j][k] + a[i+j+k].a1);
				if(j != 0) f[i][j][k] = max(f[i][j][k],f[i][j-1][k] + a[i+j+k].a2);
				if(k != 0) f[i][j][k] = max(f[i][j][k],f[i][j][k-1] + a[i+j+k].a3);
				ans = max(ans,f[i][j][k]);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--) solve();
	return 0;
} 
