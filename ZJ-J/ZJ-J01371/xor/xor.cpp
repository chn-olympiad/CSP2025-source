#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500009];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
   	ll num=0;
	for(ll l=1;l<=n;l++){
   		for(ll r=l;r<=n;r++){ 
			ll ans=0;
			for(ll x=l;x<=r;x++){
				ans^=a[x];
			}
			if(ans==k){
				num++;
				l=r;
				break;
			} 
		}
	}
	cout<<num;
	return 0;
} 

