#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n,k,arr[500005];
ll sum[500005];
ll dp1[1005][1005];
ll dp2[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	ll maxN = -1e9;
	for(ll i = 1 ; i <= n ; ++i){
		cin >> arr[i];
		sum[i] = sum[i-1] ^ arr[i];
	}
	for(ll i = 1 ; i <= n ; ++i){
		dp2[i] = dp2[i-1]+(arr[i] == k);
		for(ll j = 0 ; j <= i-1 ; ++j){
			dp1[i][j] = max(dp1[i][j],dp2[j]+((sum[i]^sum[j]) == k));
			dp2[i] = max(dp2[i],dp1[i][j]);
		}
	}
	cout << dp2[n] << endl;
	return 0;
}
