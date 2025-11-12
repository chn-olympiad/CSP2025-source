#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005],b[100005],c[100005];
bool cnt(ll a,ll b){
	return a>b;
}
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;cin>>T;
	while(T--){
		ll n,sum=0;cin>>n;
		bool h=1;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(b[i]!=0||c[i]!=0){
				h=0;
			}
		}
		if(h){
			sort(a+1,a+1+n);
			for(ll i=1;i<=n/2;i++){
				sum+=a[i];
			}
			cout<<sum;
		}else{
			for(ll i=1;i<=n;i++){
				ll x=max(a[i],max(b[i],c[i]));
				sum+=x;
			}
			cout<<sum;
		}
		cout<<endl;
	}
	
	return 0;
}
