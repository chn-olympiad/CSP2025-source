#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 2e6+5;
int n, k;
int a[N];
int sum[N];
bitset<M> vis;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	int ans = 0;
	vis[0] = 1;
	int qum = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i]^qum;
		if(vis[sum[i]^k]){
			qum ^= sum[i];
			ans++;
			vis = 0;
			vis[0] = 1;
		}
		else{
			vis[sum[i]] = 1;
		}
	}
	cout << ans;
	return 0;
}
