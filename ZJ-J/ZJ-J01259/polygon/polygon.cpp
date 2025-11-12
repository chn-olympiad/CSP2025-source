#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,a[100005];
	cin>>n;
	for(ll i=0;i<n;i++)cin>>a[i];
	if(n==3){
		ll tmp=0;
		for(ll i=0;i<3;i++)tmp+=a[i];
		for(ll i=0;i<3;i++){
			if(tmp<=a[i]*2){
				cout<<0<<endl;
				return 0;
			}
		}
		cout<<1<<endl;
		return 0;
	}else{
	
	}
}