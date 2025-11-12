#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,nm;
ll c,r;
ll ans[1000];
bool cmp(int a,int b){
	return (a>b?true:false);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	nm=n*m;
	for(int i=1;i<=nm;i++)cin>>ans[i];
	ll x=ans[1],k;
	sort(ans+1,ans+nm+1,cmp);
	for(int i=1;i<=nm;i++)if(ans[i]==x)k=i;
	c=2*(k/(2*n))+ceil(k%(2*n)*1.0/n);
	if(k%(2*n)<=n)r=k%(2*n);
	else r=2*n-k%(2*n)+1;
	cout<<c<<" "<<r;
	return 0;
}
