#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int t, n;
int d[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			int m1, m2, m3;
			scanf("%d%d%d", &m1, &m2, &m3);
			d[i] = m1;
		}
		sort(d + 1, d + 1 + n);
		long long f = 0;
		for(int i = n; i > n / 2 + 1; i--) {
			f += d[i];
		}
		cout << f << endl;
	}
	return 0;
}
