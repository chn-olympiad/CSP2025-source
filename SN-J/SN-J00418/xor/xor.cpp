#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], ans;
bool f = 1;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		ans += a[i];
		if (a[i] != 1){
			f = 0;
		}
	}
	if (k == 0 && f){
		cout << n / 2;
	}
	cout << ans;
	return 0;
}
