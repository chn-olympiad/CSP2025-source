#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, ans = 0;
		cin >> n;
		int a[N], b[N], c[N], flagA = 0, flagB = 0, flagC = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] != 0) flagA = 1;
			if (b[i] != 0) flagB = 1;
			if (c[i] != 0) flagC = 1;
		}
		int mid = n / 2;
		if (!flagB && !flagC) {
			sort(a, a + n + 1);
			for (int i = n; i > mid; i--)ans += a[i];
			cout << ans << endl;
			continue;
		} else if (!flagB && !flagA) {
			sort(c, c + n + 1);
			for (int i = n; i > mid; i--)ans += c[i];
			cout << ans << endl;
			continue;
		} else if (!flagA && !flagC) {
			sort(b, b + n + 1);
			for (int i = n; i > mid; i--)ans += b[i];
			cout << ans << endl;
			continue;
		}
		if (flagB && !flagC) {
			int tot = 0, tot2 = 0;
			int zhen[N], fu[N];
			for (int i = 1; i <= n; i++) {
				ans += max(a[i], b[i]);
				if (a[i] >= b[i]) {
					zhen[tot] = a[i] - b[i];
					tot++;
				}else {
					fu[tot2] = b[i] - a[i];
					tot2++;
				}
			}
			sort(zhen, zhen + tot);
			sort(fu, fu + tot2);
//			for(int i=0;i<tot2;i++){
//				cout << fu[i] << " ";
//			}
//			cout << tot << " " << ans<<""<<endl;
//			cout << endl;
			int st = abs(mid - tot);
			if (tot == mid) {
				cout << ans;
				continue;
			}
			if (tot > mid) {
				for (int i = 0; i < st; i++) {
					ans -= zhen[i];
				}
			} else if (tot < mid) {
				for (int i = 0; i < st; i++) {
					ans -= fu[i];
				}
			}
			cout << ans << endl;
			continue;
		}
		if (n == 2) {
			ans = max(ans, max(a[1] + b[2], a[1] + c[2]));
			ans = max(ans, max(b[1] + a[2], b[1] + c[2]));
			ans = max(ans, max(c[1] + a[2], c[1] + b[2]));
			cout << ans << endl;
		}else{
			for(int i=1;i<=n;i++){
				ans+=max(a[i],max(b[i],c[i]));
			}
			cout << ans << endl;
			
		}
	}
	return 0;
}