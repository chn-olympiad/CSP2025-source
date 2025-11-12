#include<bits/stdc++.h>
using namespace std;
struct Pos{
	int x;
	int y;
	int z;
}a[100010];
int n;
bool cmp(Pos a,Pos b){
	return a.x+b.y>a.y+b.x;
}
bool cmp1(Pos a,Pos b){
	return a.x>b.x;
}
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i].y!=0||a[i].z!=0)return false;
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i].z!=0)return false;
	}
	return true;
}
int dp[210][210][210];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){	
		cin>>n;
		int ac=0,bc=0,cc=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(check1()){
			sort(a+1,a+1+n,cmp1);
			long long ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].x;
			cout<<ans<<endl;
		}
		else if(check2()){
			sort(a+1,a+1+n,cmp);
			long long ans=0;
			for(int i=1;i<=n;i++){
				if(i<=n/2)ans+=a[i].x;
				else ans+=a[i].y;
			}
			cout<<ans<<endl;
		}
		else{
			sort(a+1,a+1+n,cmp);
			int ans=0;	
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int j=n/2;j>=0;j--){
					for(int k=n/2;k>=0;k--){
						for(int l=min(n/2,i-j-k);l>=0;l--){
							if(j>=1)dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].z);						
							if(k>=1)dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].x);					
							if(l>=1)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].y);
							ans=max(ans,dp[j][k][l]);
						}						
					}					
				}				
			}
			cout<<ans<<endl;
		}
			
	}
	return 0;
}
