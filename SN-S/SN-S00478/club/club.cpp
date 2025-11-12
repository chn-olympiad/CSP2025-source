#include<bits/stdc++.h>
#define ll int
using namespace std;
ll T;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		ll n=999;
		cin>>n;
		ll a[100050],b,c;
		for(ll i=1;i<=n;i++){
			cin>>a[i]>>b>>c;
		}
		sort(a+1,a+n+1,cmp);
		ll ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
