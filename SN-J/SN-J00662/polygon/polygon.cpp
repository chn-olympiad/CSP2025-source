#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int main() {

freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
	}
	
	if(n < 3) cout << 0;
	if(n >= 3) {
		int maxn = -1e8, count = 0;
		for(int i = 1; i <= n;i++) {
			maxn = max(maxn, a[i]);
			count += a[i];
		}
		if(count > 2 * maxn) cout << 1;
		else cout << 0;
	}
	
	return 0;
}

