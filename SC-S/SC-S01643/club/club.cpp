//dzzfjldyqqwsxdhrdhcyxll
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 2e5 + 10;
int T,ans,b[MAXN],n,cnt;
struct Node {
	int x,y,z;
}a[MAXN];
inline void solve() {
	cin >> n; ans = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
	}
	int sumx = 0,sumy = 0,sumz = 0;
	for(int i = 1;i <= n;i++) {
		int mx = max({a[i].x,a[i].y,a[i].z});
		ans += mx;
		if(mx == a[i].x) sumx++;
		else if(mx == a[i].y) sumy++;
		else sumz++;
	}	
	if(max({sumx,sumy,sumz}) <= n / 2) cout << ans << endl;
	else {
		cnt = 0;
		int flag = 0;
		if(max({sumx,sumy,sumz}) == sumx) flag = 1;
		if(max({sumx,sumy,sumz}) == sumy) flag = 2;
		if(max({sumx,sumy,sumz}) == sumz) flag = 3;
		for(int i = 1;i <= n;i++) {
			int mx = max({a[i].x,a[i].y,a[i].z});
			if(mx == a[i].x && flag == 1) b[++cnt] = a[i].x - max(a[i].y,a[i].z);
			else if(mx == a[i].y && flag == 2) b[++cnt] = a[i].y - max(a[i].x,a[i].z);
			else if(mx == a[i].z && flag == 3) b[++cnt] = a[i].z - max(a[i].y,a[i].x);
		}
		sort(b + 1,b + cnt + 1);
		for(int i = 1;i <= max({sumx,sumy,sumz}) - n / 2;i++) ans -= b[i];
		cout << ans << endl;
	}
	return;
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--) solve();
	return 0;
}