#include<bits/stdc++.h>
using namespace std;
const long long N=5e3+5,P=998244353;long long n,a[N],maxx,dp[N][2],num=0,f,sum[N],ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+n+1);maxx=a[n],dp[0][0]=dp[0][1]=sum[0]=1;for(int i=1;i<=maxx;i++) sum[i]=1;
	for(int i=1;i<=n;i++){
		ans=(ans+((sum[maxx]+f-sum[a[i]])%P+P)%P)%P;
		f=f*2%P;num^=1;
		for(int j=0;j<=maxx;j++) f=(j<a[i]?(f+dp[maxx-j][num^1])%P:f),sum[j]=((j?sum[j-1]:0)+(dp[j][num]=(j>=a[i]?(dp[j][num^1]+dp[j-a[i]][num^1])%P:dp[j][num^1])))%P;
	}
	cout<<ans;
	return 0;
}
//9:37  shenminga,qingzaijuanguwoyici

