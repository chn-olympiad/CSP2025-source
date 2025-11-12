#include<bits/stdc++.h>
using namespace std;
int yh(int a,int b){
	return (a|b)-(a&b);
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie();
	int n,m;
	cin>>n>>m;
	long long ans=0;
	vector<int>dp(n+2);
	vector<int>yhh;
	yhh.push_back(0);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	
		yhh.push_back(yh(yhh[i-1],k));
	}

	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(yh(yhh[i],yhh[j])==m){
				dp[j]=max(dp[i]+1,dp[j]);
			}
			dp[j]=max(dp[j],dp[j-1]);
		}
	}
	cout<<dp[n]<<endl;
}
