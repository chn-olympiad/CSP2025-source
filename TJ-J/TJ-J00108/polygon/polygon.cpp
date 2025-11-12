#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5005];
const int p=998244353;
ll ans=0;
ll j(int x){
	ll r=1;
	for(int i=2;i<=n;i++){
		r*=i;
	}
	return r;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	
	for(int i=3;i<=n;i++){
		ans+=j(n)/j(n-i)/j(i)%p;
	}
	printf("%lld",ans);
    return 0;
}

