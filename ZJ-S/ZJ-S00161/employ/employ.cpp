#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,m,c[100],dp[N][20];
char s[20];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++)cin>>s[i];
	for(ll i=1;i<=n;i++)scanf("%lld",&c[i]);
	dp[0][0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=(1ll<<n)-1;j>=0;j--){
			ll sum=0,h=j;
			while(h){
				sum+=h%2;
				h/=2;
			}
			if(sum!=i-1)continue;
			h=1;
			for(h=1;h<=n;h++){
				if(((1ll<<(h-1))&j)==0){
					ll e=(j+((1ll<<(h-1))));
					for(ll z=0;z<=i;z++){
						if(s[i]=='1'&&z<c[h])dp[e][z]+=dp[j][z];
						else dp[e][z+1]+=dp[j][z];
					}
				}
			}
		}
	}
	ll ans=0;
	for(ll i=0;i<=n-m;i++)ans+=dp[(1ll<<n)-1][i];
	printf("%lld",ans);
	return 0;
}
