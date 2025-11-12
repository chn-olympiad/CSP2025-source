#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}a[100005];
int dp[205][205][205];
bool cmp1(node n,node m){
	return n.a>m.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		int n;
		int f=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			if(a[i].b!=0||a[i].c!=0){
				f=1;
			}
		}
		if(!f){
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a;
			}
			cout<<ans<<'\n';
			continue;
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(i+j+k>n){
						break;
					}
					int sum=i+j+k;
					if(i!=0){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[sum].a);
					}
					if(j!=0){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[sum].b);
					}
					if(k!=0){
						dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[sum].c);
					}
					
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
