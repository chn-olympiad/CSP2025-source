#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int b1,b2,b3;
}a[100010];
int n,T,dp[210][210][210],ans,maxn;
vector<int> cc;
signed main(){
	freopen("club1.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
//		int ii,jj,kk;
		memset(dp,0,sizeof(dp));
		ans=-10010;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].b1>>a[i].b2>>a[i].b3;
			maxn+=max({a[i].b1,a[i].b2,a[i].b3});
		}
		for(int c=1;c<=n;c++){
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						if(i+j+k>c) continue;
						if(i>0&&j>0&&k>0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k]+a[c].b1,dp[i][j-1][k]+a[c].b2,dp[i][j][k-1]+a[c].b3});
						else if(i==0&&j>0&&k>0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max({dp[i][j][k],dp[i][j-1][k]+a[c].b2,dp[i][j][k-1]+a[c].b3});
						else if(i>0&&j==0&&k>0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k]+a[c].b1,dp[i][j][k-1]+a[c].b3});
						else if(i>0&&j>0&&k==0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k]+a[c].b1,dp[i][j-1][k]+a[c].b2});
						else if(i>0&&j==0&&k==0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[c].b1);
						else if(i==0&&j>0&&k==0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[c].b2);
						else if(i==0&&j==0&&k>0&&binary_search(cc.begin(),cc.end(),c)) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[c].b3);\
						cc.push_back(c);
						if(i+j+k==n&&dp[i][j][k]<=maxn){
							ans=max(ans,dp[i][j][k]);
//							if(ans<dp[i][j][k]){
//								ans=dp[i][j][k];
//								ii=i;
//								jj=j;
//								kk=k;
//							}
						}
						//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
					}
				}
			}
		}
		//cout<<ii<<" "<<jj<<" "<<kk<<" ";
		cout<<ans<<endl;
	}
	return 0;
}