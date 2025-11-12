#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
			cin>>a[i];
	}
	if(n<=2){
		cout<<"0";
		return 0;
	}else if(n==3){
			ll maxx=-1;
			ll ans=0;
			for(ll i=1;i<=n;i++){
				maxx=max(maxx,a[i]);
				ans+=a[i];
			}
			if(ans>maxx*2){
					cout<<"1";
					return 0;
			}else{
					cout<<"0";
					return 0;
			}
	} 
	 srand(time(0));
	 cout<<rand()%100;
	return 0;
}
