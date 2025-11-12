#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int n,a[5001],maxn;
long long ans,dp[5001][5001],s[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<a[1];i++)dp[1][i]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<=maxn;j++){
			dp[i][j]=dp[i-1][j];
			dp[i][j]%=P;
			if(j-a[i]==0)dp[i][j]+=dp[i-1][0];
			if(j-a[i]<0)dp[i][j]+=dp[i-1][0]+1;
			if(j-a[i]>0)dp[i][j]+=dp[i-1][j-a[i]];
			dp[i][j]%=P;
		}
	}
	for(int i=3;i<=n;i++){
		if(s[i-1]<=a[i])continue;
		int k=s[i-1]-a[i];
		if(dp[i-1][0]-dp[i-1][k]<0)ans+=((dp[i-1][0]-dp[i-1][k]+P)%P);
		else ans+=dp[i-1][0]-dp[i-1][k];ans%=P;
		ans++;
		ans%=P;
	}
	cout<<ans%P;
	return 0;
}
