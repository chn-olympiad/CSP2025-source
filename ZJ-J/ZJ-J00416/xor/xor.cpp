#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool f1, f2, qyx;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	if(a[i] != 1)f1 = true;
    	if(a[i] > 1)f2 = true;
	}
	if(!f1) {
		if(k == 1) {
			cout << n << '\n';
			return 0;
		}
		if(k == 0) {
			cout << n / 2 << '\n';
			return 0; 
		}
		cout << 0 << '\n';
		return 0;
	}
	if(!f2) {
		int ans = 0;
		if(k == 0) {
		    int i = 1;
		    while(i < n) {
				if(a[i] == 0) ans++, i++;
				else if(a[i + 1] == 1) ans++, i += 2;
			}
			cout << ans << '\n';
			return 0;
		}
		else if(k == 1) {
			for(int i = 1; i <= n; i++) {
				if(a[i] == 1) ans++;
			}
			cout << ans << '\n';
			return 0;
		}else {
			cout << 0 << '\n';
			return 0;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) ans++;
	}
	cout << ans << '\n';
    return 0;
}
//rp++
