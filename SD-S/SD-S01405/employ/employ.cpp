#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ll n,m,sum=0,sumn=1;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>m;
	}
	for(ll i=1;i<=n;i++){
		cin>>m;
		if(m==0)sum++;
	}
	for(ll i=n;i>=1+sum;i--){
		sumn*=i;
	}
	cout<<sumn;
	
	return 0;
}
