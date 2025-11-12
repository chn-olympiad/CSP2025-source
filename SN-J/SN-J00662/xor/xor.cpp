#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int counto = 0, countl = 0, ans = 0;
int main() {

freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);

ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

	int n;
	int k;

	cin >> n;
	cin >> k;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];
		if(a[i] == 0) counto++;
		if(a[i] == 1) countl++;
	}
	
	if(k == 0) {
		for(int i = 1;i <= n ;i++) {
			if(a[i] == 0) {
				ans++;
				a[i] = -1;
			}
		}
		for(int i = 1;i < n;i++) {
			if(a[i] == a[i + 1] and a[i] == 1) {
				ans++;
				a[i] = a[i + 1] = -1;
			}
		}
		cout << ans;
	}
	
	if(k == 1) {
		ans = countl;
		cout << ans;
	}
	
	if(k == 255) {
		for(int i = 1;i <= n ;i++) {
			if(a[i] == 255) {
				ans++;
				a[i] = -1;
			}
		}
		for(int i = 1;i < n ;i++) {
			if((a[i] == 254 and a[i + 1] == 1) or (a[i] == 1 and a[i + 1] == 254)) {
				ans++;
				a[i] = a[i + 1] = -1;
			}
		}
		cout << ans;
	}
	return 0;
}

