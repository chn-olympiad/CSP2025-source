#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int vis[N];
int a[N];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	int ans = 0;

	for(int i=1; i<=n; i++) cin >> a[i];
	
//	if(k == 0){
//		cout << n/2;
//		return 0;
//	}
//	if(k==1){
//		for(int i = 1; i<n; i++){
//			if(a[i]^a[i+1]){
//				ans ++;
//				i++;
//			}
//		}
//		cout << ans;
//		return 0;
//	}
//	
	
	for(int i = 1; i<=n; i++){
		for(int j=1; j<=n-i+1; j++){
			int sum = 0;
			bool f = false;
			for(int o = j; o < j+i; o++){
				sum ^= a[o];
				if (vis[o]){
					f = true;
					break;
				}
			}
			if(f) continue;
			if(sum == k){
				ans ++;
				for(int o = j; o < j+i; o++){
					vis[o]++;
				}
			}
		}
	}
	
	cout << ans;
	
	return 0;
}
