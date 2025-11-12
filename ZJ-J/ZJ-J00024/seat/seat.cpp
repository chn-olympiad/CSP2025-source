#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
			cin>>a[i];
	}
	ll g=a[1];
	ll w=1;
	for(ll i=1;i<=n*m;i++){
			if(g<a[i]){
				w++;
			}
	}
	if(w%n==0){
		cout<<w/n<<" ";
		if((w/n)%2==1){
			cout<<n;
		}else{
				cout<<"1";
		}
		
	}else{
		 cout<<w/n+1<<" ";
		 if((w/n+1)%2==0){
				cout<<n-w%n+1;
		}else{
				cout<<w%n;
		}
	}
	return 0;
}
