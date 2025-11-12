#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[5009];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int dp[5009]={0};
	dp[0]=1;
	int mod=998244353;
	int sum=0;
	int u=1;
	for(int i=0;i<n;i++){
		sum+=u;
		sum%=mod;
	    for(int j=0;j<=a[i];j++){
	    	sum+=mod;
			sum-=dp[j];
			sum%=mod;
		}
		for(int j=5008;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=mod;
		}
		u*=2;
		u%=mod;
	}
	cout<<sum;
	return 0;
}
