#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn=5e3+7;
const int maxm=5e2+7;
const int mod=998244353;
int a[maxn];
ll dfs(int x,int sum,int mx,int num){
	//cout<<x<<" "<<mx<<" "<<sum<<" "<<num<<endl;
	if(x>n){
		if(2*mx<sum && num>=3)
			return 1;
		return 0;
	}
	ll ans=0;
	ans=(ans+dfs(x+1,sum+a[x],a[x],num+1))%mod;
	ans=(ans+dfs(x+1,sum,mx,num))%mod;
	return ans;
}
ll fastmi(int x,int y){
	ll ans=1,now=x;
	while(y){
		if(y&1) ans=ans*now%mod;
		now=now*now%mod;
		y>>=1;
	}
	return ans;
}
ll q[maxn],lq[maxn];
ll dp[maxm][maxm*maxm];
ll num[maxm*maxm];
void sol(){
	int sum=0;
	ll ans=0;
	for(int i=0;i<=n;i++) dp[i][0]=1;
	num[0]=1;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		for(int j=sum;j>=a[i];j--){
			dp[i][j]=num[j-a[i]];
			num[j]=(num[j]+num[j-a[i]])%mod;
		}
	}
	for(int i=3;i<=n;i++){
		for(int j=0;j<=sum;j++)
			if(a[i]*2<j && dp[i][j]) ans=(ans+dp[i][j])%mod;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[n]==1){
		ll ans=0;
		q[0]=1;
		for(int i=1;i<=n;i++)
			q[i]=q[i-1]*i%mod;
		lq[n]=fastmi(q[n],mod-2);
		for(int i=n;i>0;i--) lq[i-1]=lq[i]*i%mod;;
		for(int i=3;i<=n;i++) ans=(ans+q[n]*lq[n-i]%mod*lq[i]%mod)%mod;
		cout<<ans<<endl;
	}else if(n>20){
		sol();
	}else cout<<dfs(1,0,0,0)<<endl;
	return 0;
}
