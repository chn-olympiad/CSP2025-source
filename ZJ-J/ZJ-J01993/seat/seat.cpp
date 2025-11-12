#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k;
ll x,a[1005];
bool cmp(ll x,ll y) {
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n*m;++i) cin>>a[i];
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(ll i=1;i<=n*m;++i) 
	if(x==a[i]){
		k=i;
		break;
	}
	ll p;
	if(k/n*n==k) p=k/n;
	else p=k/n+1;
	cout<<p<<' ';
	if(p&1){
		cout<<k-(p-1)*n;
	}else cout<<n-(k-(p-1)*n)+1;
	return 0;
}
