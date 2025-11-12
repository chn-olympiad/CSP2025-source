//SN-J101007  贾章泽 西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,a[5005],dp[25005][3],s,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=s;i>=a[j];i--){
			if(i==a[j]) dp[i][0]++;
			if(i>a[j]) dp[i][1]=(dp[i][1]+dp[i-a[j]][0])%mo;
			if(i>a[j]*2) dp[i][2]=(dp[i][2]+dp[i-a[j]][1]+dp[i-a[j]][2])%mo;
		}
	}
	for(int i=1;i<=s;i++) cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl,ans+=dp[i][2];
	cout<<ans;
	return 0;
}
