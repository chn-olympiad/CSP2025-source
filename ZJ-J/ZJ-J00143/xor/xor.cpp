#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
ll n,k,ans,d;
ll num[500005];
ll f[500005];
map<ll,bool> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>num[i];
		num[i]=num[i-1]^num[i];
	}
	
	for(ll i=1;i<=n;++i){
		ll sum=d,l=i;
		for(ll j=i;j<=n;++j){
			ll t=num[j]^num[l-1];
			if(t==k){
				sum++;
				f[j]=max(f[j],sum);
				l=j+1;
			}
		}
		d=max(d,f[i]);
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
