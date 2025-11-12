#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int a[n+5];
	a[0] = 0;
	bool f[n+5];
	memset(f, true, sizeof f);
	int l = 0, y = 0, c = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] == 0) l++;
		if(a[i]==1) y++;
		if(a[i] == 1 && a[i-1] == 1 && f[i-1] != false){
			c++;
			f[i] = false;
		}
	}
	if(k==0) {
		cout << l + c << "\n";
	} else if (k == 1) {
		cout << y << "\n";
	}
	return 0;
}
