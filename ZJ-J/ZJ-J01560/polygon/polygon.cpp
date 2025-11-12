#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int P=998244353;
ll n,a[5050],ct;
//Ì«ÄÑÁË£¡×öî¿°í:( 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		ll mmax=-2e9;
		mmax=max(mmax,max(a[1],max(a[2],a[3])));
		if((a[1]+a[2]+a[3])>mmax*2){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(ll i=1;i<=n-3;i++){
		ll k=a[i]+a[i+1],maxx=max(a[i],a[i+1]);
		for(ll j=i+2;j<=n;j++){
			k+=a[j],maxx=max(maxx,a[j]);
			if(k>maxx*2){
				//cout<<i<<" "<<j<<" "<<k<<"\n";
				ct++;
				ct%=P;
			}
		}
	}
	cout<<ct;
	return 0;
}
