#include<bits/stdc++.h>
using namespace std;
#define int long long
 const int N=998244353;
 int n,m,ans=0;
 int a[510];
 int dp[300010][20];
 bool ss[510];
int lowbit(int x){return x&-x;}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		ss[i]=c-'0';
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n>=20){
		cout<<0;
		return 0;
	}
	dp[0][0]=1;
	for(int i=0;i<(1<<n)-1;i++){
		int as=0;
		for(int j=i;j;j-=lowbit(j))as++;
		for(int j=0;j<=as;j++){
			for(int k=1;k<=n;k++){
				if(i&(1<<k-1))continue;
				if(as-j>=a[k]||!ss[as+1])dp[i|(1<<k-1)][j]=(dp[i|(1<<k-1)][j]+dp[i][j])%N;
				else dp[i|(1<<k-1)][j+1]=(dp[i|(1<<k-1)][j+1]+dp[i][j])%N;
			}
		}
	}
	for(int i=m;i<=n;i++)ans=(ans+dp[(1<<n)-1][i])%N;
	cout<<ans;
	return 0;
}
