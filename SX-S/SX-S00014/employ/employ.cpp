#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, m, nx[maxn], nd[maxn], nt, fq;
char a;
long long ans = 1;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("&c", a); //'0'=48;
		nd[i] = a;
		scanf("%d", &nx[i]);
	}
	if (m == 1) {
		for (int i = 1; i <= n; i++) {
			ans = ans * i;
		}
		for (int i = 1; i <= n; i++) {
			if (nd[i] == 49) {
				nt++;
			}
			/*if(nd[i]==48){
				break;
			}*/
		}
		if (nt == n) {
			cout << 0 % 998244353;
			return 0;
		}
		if (nt <= n - 1)
			for (int i = 1; i <= n; i++) {
				if (nx[i] < nt) {
					ans--;
				}
			}
		cout << ans % 998244353;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (nd[i] == 49) {
			nt++;
		}
	}
	if (nt == n) {
		cout << 0 % 998244353;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		ans = ans * i;
	}
	cout << ans % 998244353;
	return 0;
}
