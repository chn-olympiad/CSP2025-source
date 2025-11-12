#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans=0;
ll a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		ll cnt=0;
		ll l=i;
		while(l<=n){
			if(a[l]==k){
				l+=1;
				cnt++;
				continue;
			}
			ll p=a[l];
			bool man=true;
			for(ll j=l+1;j<=n;j++){
				p^=a[j];
				if(p==k){
					l=j+1;
					cnt++;
					man=false;
					break;
				}
			}
			if(man==false) continue;
			else break;
			
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
