#include<bits/stdc++.h>
#define ll long long
#define N 1001001
using namespace std;
ll a[N];
ll cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll n,m,ra,ri;
	cin>>n>>m;
	for(ll i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ra=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(ll i=n*m;i>=1;i--){
	//	cout<<i<<" "<<a[i]<<" "<<ra<<"\n";
		if(a[i]==ra){
			ri=i;
			break;
		}
	}
	//cout<<ri<<" ";
	cout<<(ri-1)/n+1<<" ";
	if(((ri-1)/n+1)%2==1){
		cout<<(ri-1)%n+1;
	}else{
		cout<<n-((ri-1)%n);
	}
	return 0;
}
