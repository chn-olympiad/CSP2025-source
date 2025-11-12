#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353,num=5*1e3+5;
ll n,a[num],ans;
void sc(ll sy_step,ll maxx,ll sum,ll px){
	if(sy_step==0){
		if(maxx*2<sum)
			++ans;
		ans%=MOD;
		return;
	}
	if(px==n)
		return;
	ll maxxx=max(maxx,a[px]);
	sc(sy_step-1,maxxx,sum+a[px],px+1);
	sc(sy_step,maxx,sum,px+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0;i<n;++i)
		scanf("%lld",&a[i]);
	for(ll i=3;i<=n;++i){
		sc(i,LONG_LONG_MIN,0,0);
		ans%=MOD;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}