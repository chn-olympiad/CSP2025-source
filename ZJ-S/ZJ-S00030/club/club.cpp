#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,arr[10001][3];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	int cnt0=0,cnt1=0,cnt2=0;
	int mx=n/2;
	int dp[10001][3];//dp[i][0/1/2]第i个学生选0/1/2时的最大值 
	dp[0][0]=arr[0][0];
	dp[0][1]=arr[0][1];
	dp[0][2]=arr[0][2];
	for(int i=1;i<n;i++){
		if(max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})==dp[i-1][0]&&cnt0+1<=mx) cnt0++;
		if(max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})==dp[i-1][1]&&cnt1+1<=mx) cnt1++;
		if(max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})==dp[i-1][2]&&cnt2+1<=mx) cnt2++;
		if(cnt0+1<=mx)dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+arr[i][0];
		else dp[i][0]=dp[i-1][0];
		if(cnt1+1<=mx)dp[i][1]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+arr[i][1];
		else dp[i][1]=dp[i-1][1];
		if(cnt2+1<=mx)dp[i][2]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+arr[i][2];
		else dp[i][2]=dp[i-1][2];
	}
	cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<"\n";
}
int main(){
	int _;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>_;
	while(_--){
		solve();
	}
}
