#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,dp[N][3],pan[3],a[N][3];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d",&n);
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		pan[1]=pan[2]=pan[3]=n/2;
		int f=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if((a[i][1]!=0&&a[i][3]!=0)||(a[i][2]!=0&&a[i][1]!=0)||(a[i][2]!=0&&a[i][3]!=0)) f=0;
		}
		if(n==2){
			int maxxx=0;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(i!=j){
						maxxx=max(maxxx,a[i][1]+a[j][2]);
					}
				}
			}
			cout<<maxxx<<endl;
			continue;
		}
		else if(f){
			int b[N],cnt=0;
			for(int i=1;i<=n;i++){
				b[i]=max(max(a[i][1],a[i][2]),a[i][3]);
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				cnt+=b[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(pan[1]==0){
				dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i][1];
			}
			else{
				dp[i][1]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][1];
			}
			if(pan[2]==0){
				dp[i][2]=max(dp[i-1][1],dp[i-1][2])+a[i][2];
			}
			else{
				dp[i][2]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][2];
			}
			if(pan[3]==0){
				dp[i][3]=max(dp[i-1][2],dp[i-1][1])+a[i][3];
			}
			else{
				dp[i][3]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][3];
			}
			if(dp[i][1]>dp[i][2]&&dp[i][1]>dp[i][3]){
				pan[1]--;
			}
			else if(dp[i][2]>dp[i][1]&&dp[i][2]>dp[i][3]){
				pan[2]--;
			}
			else if(dp[i][3]>dp[i][2]&&dp[i][3]>dp[i][1]){
				pan[3]--;
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
	return 0;
}
