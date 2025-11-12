#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50000005];
ll b[50000005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ll n,k,ans=0;
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(ll i=1;i<=n;i++){	
    	if(b[i-1]==a[i])b[i]=a[i];
    	else b[i]=b[i-1]^a[i];
	}
	int l=0;
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			if(b[j]==a[i])l=b[j];
			else l=b[j]^a[i];
			if(l==k){
				ans++;
				i=j;
			}
		}
	}
	cout<<ans;
	return 0;
}
