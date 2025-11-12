#include<bits/stdc++.h>
using namespace std;
int n,k,a[50005],c[50005],dp[5005];
int sxor(int x,int y){
	int sum=0;
	for(int i=y;i<=x;i++){
		sum^=a[i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(sxor(i,j)==k){
				dp[i]=max(dp[i-(i-j+1)]+1,dp[i]);
			}else{
				dp[i]=max(dp[i-(i-j+1)],dp[i]);
			}
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		mx=max(mx,dp[i]);
	}
	cout<<mx;
	return 0;
}