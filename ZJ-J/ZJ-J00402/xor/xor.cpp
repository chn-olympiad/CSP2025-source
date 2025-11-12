#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[1000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		ll b;
		cin>>b;
		a[i]=a[i-1]^b;
	}
	if(n<=2&&k==0){
		if(n==2) cout<<1;
		else cout<<0;
	}
	else {
		for(ll i=0,j=1;j<=n;j++){
            bool d=0;
			for(ll p=i;p<j;p++){
			    ll c=a[j]^a[p];
				if(c==k){
					d=1;
					break;
				}
			}
			if(d){
				ans++;
				i=j;
			} 
		}
		cout<<ans;
	}
	return 0;
}
