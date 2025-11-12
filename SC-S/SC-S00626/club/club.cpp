#include<bits/stdc++.h>
using namespace std;
const int o=1e5+1,u=5e4;
int t,n,a[o][4],dp[u],maxnum=0,used[o]={0},sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		for(int j=1;j<=n;++j){
			for(int k=1;k<=3;++k){
				cin>>a[j][k];
			}
		}
		if(n==2){
			int z=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			int y=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			int x=max(a[1][3]+a[2][2],a[1][3]+a[2][1]);
			cout<<max(max(x,y),z);
		}
		else{
			for(int k=1;k<=3;++k)
			{
				for(int l=1;l<=n;++l){
					for(int m=n/2;m>=1;--m)
						dp[m]=max(dp[m],dp[m-1]+a[l][k]);
				}
			}
			cout<<dp[n/2];
		}
		
		
		
	}
}