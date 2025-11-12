#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("seat.in","r",stdin);`
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int anss = n * m;
	int hh,ans = 1;
	cin >> hh;
	for(int i = 2; i <= anss; i ++) {
		int t;
		cin >> t;
		if(t > hh) ans ++;
	}
	int uu = ans / n;
	if(uu % 2 == 1) {
		int yy = m - ans % n + 1;
		if(ans % n != 0) cout << uu + 1 << " " << yy;
		else cout << uu << " " << m;
	} else {
		int yy = ans % n;
		if(ans % n != 0) cout << uu + 1 << " " << yy;
		else cout << uu << " " << 1;
	}
	return 0;
}
