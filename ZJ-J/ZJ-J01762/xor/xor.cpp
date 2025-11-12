#include<bits/stdc++.h>
using namespace std;
int a[500010];
int dp[1010][1010];
int dpp[1010][1010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	int n,k;
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
		if(a[i]==k){
			dpp[i][i]=1;
		}
		if(a[i]>1){
			f=0;
		}
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int e=j+i-1;
			dp[j][e]=dp[j][e-1]^a[e];
			if(dp[j][e]==k){
				dpp[j][e]=1;
			}
			for(int h=j;h<e;h++){
				dpp[j][e]=max(dpp[j][h]+dpp[h+1][e],dpp[j][e]);
			}
		}
	}
	cout<<dpp[1][n];
	return 0;
}
