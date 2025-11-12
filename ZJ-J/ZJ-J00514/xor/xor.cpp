#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int dp[N],qz[N],a,n,k;
int mp[N*3];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		qz[i]=qz[i-1]^a;
	}
	dp[0]=0,dp[1]=(qz[1]==k);
	mp[qz[1]]=1;
	for(int i=2;i<=n;i++){
		mp[qz[i]]=i;
		int kcnt;
		if(mp[qz[i]^k]){
			kcnt=mp[qz[i]^k]+1;
			dp[i]=dp[kcnt-1]+1;
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}