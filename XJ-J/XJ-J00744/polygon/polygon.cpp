#include<bits/stdc++.h>
using namespace std;
long long a[5010];
long long dp[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i]; 
	}
	dp[1]=0;
	for(int i=1;i<=n;i++) {
		for(int j=a[n];j>=i;j--) {
			dp[i]+=a[i-1]+dp[j-1];
		} 
	}
	cout<<((dp[n]+1)/3+1)/10;
	
} 
/*
#Shang4Shan3Ruo6Shui4
*/ 
