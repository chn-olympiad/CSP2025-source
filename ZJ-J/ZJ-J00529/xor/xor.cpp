#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,k,dp[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int ik=0;
			if((a[i]^a[j-1])==k)ik=1;
			//cout<<i<<' '<<j<<' '<<(a[i]^a[j-1])<<endl;
			dp[i]=max(dp[i],dp[j-1]+ik);
		}
	}
	//for(int i=1;i<=n;i++)cout<<dp[i]<<' ';
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


