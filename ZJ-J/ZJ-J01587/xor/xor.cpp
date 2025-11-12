#include<bits/stdc++.h>
using namespace std;
int s[500001]={};
	int n,k;
	int maxx=0;
	int dp[500001]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		int a;
		cin>>a;
		s[i]=(s[i-1] xor a); 
	}
	if(s[1]==k) dp[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=i;j>0;--j){
			if((s[i] xor s[j-1])==k){
				dp[i]=max(dp[i],dp[j-1]+1);
				break;
			}
			else dp[i]=max(dp[i-1],dp[i]);
		}
	}
	
	cout<<dp[n];
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}

