#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll n,m,ans,k;
ll a[N],sum[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]^a[i];
	ll l=1;
	for(ll i=1;i<=n;i++){
		for(ll j=l;j<=i;j++){
			if((a[i]^a[j-1])==k){
				++ans;
				l=i+1;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*

*/
