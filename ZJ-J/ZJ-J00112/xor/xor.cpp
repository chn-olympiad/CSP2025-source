#include<bits/stdc++.h>
using namespace std;
bool flag[5010][5010],tepan=1;
int dp[888888],arr[888888],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]>1)tepan=false;
	}
	if(tepan){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++)if(arr[i]==1)cnt++;
			cout<<cnt;
		}else{
			int len=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(arr[i]==0){
					cnt++;
					cnt+=floor(len/2);
					len=0;
				}else len++;
			}
			cnt+=len/2;
			cout<<cnt;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)arr[i]^=arr[i-1];
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int x=arr[r]^arr[l-1];
			if(x==k)flag[l][r]=1;
		}
	}
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int tag=0;
		for(int j=i;j>=1;j--){
			if(flag[j][i]){
				tag=j;
				break;
			}
		}
		if(tag)dp[i]=max(dp[tag-1]+1,dp[i-1]);
		else dp[i]=dp[i-1];
	}
	cout<<dp[n];
}