#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[5050];
ll anss=0;
void num(ll i,ll ans,ll x,ll maxx){
	if(i==n+1&&x>=3&&(ans>(maxx*2))){
		anss++;
		ans%=998244353;
		cout<<i<<" "<<ans<<" "<<x<<" "<<maxx<<"\n";
	}
	if(i>n){
		return;
	}
	num(i+1,ans+a[i],x+1,max(maxx,a[i]));
	num(i+1,ans,x,maxx);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	num(1,0,0,0);
	cout<<(anss%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
