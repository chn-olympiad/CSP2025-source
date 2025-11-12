#include<bits/stdc++.h>
using namespace std;
int n, k, a[500001], ans, r;
void dp(int rp, int res){
	if(rp==n+1){
		return;
	}
	int r=res;
	for(int i=rp;i<=n;i++){
		r=r^a[i];
		if(r==k){
			ans++;
			dp(i+1, 0);
			return;
		}
	}
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
 	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dp(1, 0);
	cout << ans;
	return 0;
}