#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[500001];
int ans = 0;

bool vis[500001];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		if (vis[i]) continue;
		if(x == k) {
			ans++;
			vis[i] = true;
		}
		for (int j = i + 1; j <= n; j++) {
			if (vis[j]) break;
			x = x | a[j];
			if (x == k){
				ans++;
				
				for (int z = i; z <= j; z++) vis[z] = true;
				break;
			} 
		}
	}
	cout << ans;
	return 0;
}

