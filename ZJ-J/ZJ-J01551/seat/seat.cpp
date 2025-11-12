#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=100+10;
ll n,m;
ll a[N];
ll p,idx;
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=1;i<=n*m;i++){
		if(a[i]==p){
			idx=i;
			break;
		}
	}
//	cout<<idx;
	ll h=(idx+n-1)/n,l;
	if(h%2==1){
		if(idx%n==0)l=n;
		else l=idx%n;
	}
	else{
		if(idx%n==0)l=1;
		else l=n-(idx%n)+1;
	}
	cout<<h<<" "<<l;
	return 0;
}
