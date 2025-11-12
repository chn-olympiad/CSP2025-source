#include<bits/stdc++.h>
using namespace std;
struct cub{
	long long cl1,cl2,cl3;
}a[100010];
long long t,n,dp[100010][4],max1,max2,max3;
bool cmp(cub a,cub b){
	return a.cl1>b.cl1;
}
bool cmp1(cub a,cub b){
	return a.cl2>b.cl2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].cl1>>a[i].cl2>>a[i].cl3;
			max3=max(max3,a[i].cl3);
			max2=max(max2,a[i].cl2);
			max1=max(max1,a[i].cl1);
			
		}
		if(max3==0){
			if(max2==0){
				long long ans=0;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].cl1;
				}
				cout<<ans;
				return 0;
			}else{
				long long ans=0,ans1=0;
				sort(a+1,a+n+1,cmp);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].cl1;
				}for(int i=n/2+1;i<=n;i++){
					ans+=a[i].cl2;
				}
				sort(a+1,a+n+1,cmp1);
				for(int i=1;i<=n/2;i++){
					ans1+=a[i].cl2;
				}for(int i=n/2+1;i<=n;i++){
					ans1+=a[i].cl1;
				}
				ans=max(ans,ans1);
				cout<<ans;
				return 0;
			}
		}
		memset(dp,0,sizeof(dp));
		dp[1][1]=a[1].cl1;
		dp[1][2]=a[1].cl2;
		dp[1][3]=a[1].cl3;
		for(int i=2;i<=n;i++){
			if(i<=n/2){
				for(int j=1;j<=3;j++){
					if(j==1){
						dp[i][j]=max(dp[i-1][2],max(dp[i-1][1],dp[i-1][3]))+a[i].cl1;
					}else if(j==2){
						dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i].cl2;
					}else{
						dp[i][j]=max(dp[i-1][2],max(dp[i-1][3],dp[i-1][1]))+a[i].cl3;
					}
				}
			}else{
				for(int j=1;j<=3;j++){
					for(int k=2;k<=i-1;k++){
						if(j==1){
							dp[i][j]=max(dp[i-1][2],max(dp[i-k][1],max(dp[i-1][3],dp[i][j])))+a[i].cl1;
						}else if(j==2){
							dp[i][j]=max(dp[i-1][1],max(dp[i-k][2],max(dp[i-1][3],dp[i][j])))+a[i].cl2;
						}else{
							dp[i][j]=max(dp[i-1][2],max(dp[i-k][3],max(dp[i-1][1],dp[i][j])))+a[i].cl3;
						}
					}
				}
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
	}
	return 0;
}