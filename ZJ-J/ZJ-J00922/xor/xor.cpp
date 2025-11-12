#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[500005],dp[500005],cnt1,cnt2,flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)flag=1;
		if(a[i]==0)cnt1++;
		if(a[i]==1)cnt2++;
		s[i]=s[i-1]^a[i];
	}
	if(!flag&&k<=1){
		if(k==0)cout<<cnt1;
		else cout<<cnt2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		for(int j=0;j<i;j++){
			if((s[i]^s[j])==k){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
	}
	cout<<dp[n];
	return 0;
}
