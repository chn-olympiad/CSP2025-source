#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, kk, a[500005], dp[500005], sum;//1:Y, 0:N
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> kk;
	for(ll i=1; i<=n; i++)cin >> a[i];
	bool flag=0;
	for(ll i=1; i<=n; i++){
		flag|=a[i];
	}
	if(flag==0&&kk>0)return cout<<0, 0;
	for(ll i=1; i<=n; i++)dp[i]=dp[i-1]^a[i];
//	for(ll i=1; i<=n; i++)cout<<dp[i]<<' ';cout<<'\n';
	for(ll i=1, j=1; i<=n; i++){
		for(ll k=j; k<=i; k++){
//			cout<<k<<'~'<<i<<':'<<(dp[i]^dp[k-1])<<'\n';
			if( (dp[i]^dp[k-1]) == kk){
				sum++, j=i+1;
				break;
			}
		}
	}
	cout<<sum;
	return 0;
}

