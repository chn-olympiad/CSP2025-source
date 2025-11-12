#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k,sum,a[1003],dp[1003][1003];
int main(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(j>=i)sum^=a[j];
			if(j>=i&&sum==k)dp[i][j]=max(dp[i-1][j],dp[i][i-1]+1);	
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}cout<<dp[n][n];
			
}
//[1 1 4 5 1 4 1] 9 1 9 8 1 0 k=5
//1 2 4 8 16 k=31
