#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int n,i,ans,j,sum,a[5010],dp[1000010];
bool cmp(int a,int b){
	return a>b;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
//	cout<<"\n";
//	ans=0;
	dp[0]=1;
	for(i=n;i>=1;i--){
		sum=sum+a[i];
		for(j=sum;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];dp[j]%=mod;
			if(j>=a[i]*2+1)ans+=dp[j-a[i]],ans%=mod;
		}
//		for(j=1;j<=21;j++)cout<<dp[j]<<" ";
//		cout<<"\n";
	}
	cout<<ans;
	return 0;
}
/*

6
1 2 3 4 5 6

20
75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1


*/
