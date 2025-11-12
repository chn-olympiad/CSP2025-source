#include<bits/stdc++.h>
using namespace std;
int n,k;
//int a[10050];
int p[500500];
int f[500500];
int dp[500500];
int main(){
	freopen("xor.out","w",stdout);
	freopen("xor.in","r",stdin);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		p[i]=p[i-1]^x;
		//a[i]=x;
	}for(int i=1;i<=n;i++){
		int l=1e9;
		for(int j=i;j<=n;j++){
			if((p[i-1]^p[j])==k){
				l=min(l,j);
			}//cout<<i<<" "<<j<<endl;
		}
		if(l!=1e9)f[l]=max(f[l],i);
	}//cout<<1;
	/*for(int i=1;i<=n;i++){
		cout<<f[i];
	}*/
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i]);
		if(f[i]!=0){
			dp[i]=max(dp[i],dp[f[i]]+1);
		}
	}cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}