#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[2][25000005];
int a[500005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m+=a[i];
	}
	//m++;
	sort(a+1,a+n+1);
	dp[0][0]=1;
	int ans=0;
	int ls=0;
	int now=0;
	for(int i=1;i<=n;i++){
		now^=1;
		dp[now][0]=1;
		for(int j=1;j<=m;j++){
			dp[now][j]=dp[ls][j];
			if(j-a[i]>=0)dp[now][j]+=dp[ls][j-a[i]];
			dp[now][j]%=998244353;
		}
		for(int j=a[i]+1;j<=m;j++){
			ans+=dp[ls][j];
			ans%=998244353;
		}
		ls=now;
	}
	cout<<ans<<endl;
}
