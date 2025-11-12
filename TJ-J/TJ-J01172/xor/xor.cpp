#include <bits/stdc++.h>
using namespace std;

int a[500005];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	int maxn=-1;
	int fast=2, slow=1;
	int cnt=a[1];
	int ans=0;
	while(fast<=n){
		if(a[fast]==k){
			slow=fast;
			ans++;
			cnt=a[slow];
		}
		if(cnt==k){
			slow=fast;
			cnt = a[slow];
			ans++;
		}
		fast++;
		cnt^=a[fast];
	}
	cout << ans;
		
	return 0;
}
