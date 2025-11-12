#include<bits/stdc++.h>
using namespace std;
//xor  相同取0，不同取1 
int n,k,ans;
int a[500020],dp[10000][10000];
bool pd[1000];
bool check(int x,int y){
	for(int i=x;i<=y;i++){
		if(pd[i]==1){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i][i]=a[i];
	}
	for(int l=1;l<=n;l++){
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			dp[i][j]=dp[i][j-1] xor dp[j][j];
			if(dp[i][j]==k&&check(i,j)){
				for(int x=i;x<=j;x++){
					pd[i]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
}
