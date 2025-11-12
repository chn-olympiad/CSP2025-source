#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const ll md=998244353;
ll dp[5005][10005];
ll a[5005],b[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++)dp[i][j]=dp[i-1][j];
		for(int j=a[i];j<=10000;j++)dp[i][j]=(dp[i-1][j]+dp[i-1][j-a[i]])%md;
	}
	b[1]=1;
	for(int i=2;i<=10000;i++){
		b[i]=(2*b[i-1])%md;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll s=0;
		for(int j=0;j<=a[i];j++){
			s=(s+dp[i-1][j])%md;
		}
		b[i]=((b[i]-s+md)%md+md)%md;
		ans+=b[i];
		ans%=md;
	}
	printf("%lld",ans);
	return 0;
}
