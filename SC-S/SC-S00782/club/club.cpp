#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][5],b[N];
int dp[N][5]; 
int rs[5];
int n,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		int tota=0,totb=0;//特判 
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][3]==0){
				totb++;
				if(a[i][2]==0) tota++;
			}
		}
		if(tota==n){//性质A 
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			long long ans=0;
			for(int i=1;i<=n/2;i++) ans+=b[i];
			cout<<ans<<"\n";
			continue;
		}
		rs[1]=0,rs[2]=0,rs[3]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				if(rs[j]<n/2){
					dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+a[i][j];
					rs[j]++;
				}
				else {
					if(j==1){
						if(rs[2]>n/2) dp[i][j]=dp[i-1][3]+a[i][j];
						else if(rs[3]>n/2) dp[i][j]=dp[i-1][2]+a[i][j];
						else dp[i][j]=max(dp[i-1][2],dp[i-1][3])+a[i][j];
					}
					if(j==2){
						if(rs[1]>n/2) dp[i][j]=dp[i-1][3]+a[i][j];
						else if(rs[3]>n/2) dp[i][j]=dp[i-1][1]+a[i][j];
						else dp[i][j]=max(dp[i-1][1],dp[i-1][3])+a[i][j];
					}
					if(j==3){
						if(rs[1]>n/2) dp[i][j]=dp[i-1][2]+a[i][j];
						else if(rs[2]>n/2) dp[i][j]=dp[i-1][1]+a[i][j];
						else dp[i][j]=max(dp[i-1][1],dp[i-1][2])+a[i][j];
					}
				}
//				rs[j]++;
			}
		}
//		cout<<rs[1]<<" "<<rs[2]<<" "<<rs[3]<<"\n";
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<"\n";
	}
	return 0;
}