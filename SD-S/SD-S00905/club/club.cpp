#include<bits/stdc++.h>
using namespace std;
int T,n,ans,flg=1,num[100005][4][4],dp[100005][5];
struct node{
	int pa[5];
}a[100005];
bool cmp1(node x,node y){
	return x.pa[1]>y.pa[1];
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		flg=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].pa[1]>>a[i].pa[2]>>a[i].pa[3];
			if(a[i].pa[2]!=0){
				if(a[i].pa[3]!=0) flg=3;
				else if(a[i].pa[3]==0) flg=2;
			}
		}
		if(flg==1){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].pa[1];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(flg==2){
			int x,y,num1,num2;
			for(int i=1;i<=n;i++){
				ans+=max(a[i].pa[1],a[i].pa[2]);
			}
			cout<<ans<<"\n";
			continue;
		}
		dp[1][1]=a[1].pa[1];
		dp[1][2]=a[1].pa[2];
		dp[1][3]=a[1].pa[3];
		num[1][1][1]=1;
		num[1][2][1]=1;
		num[1][3][1]=1;
		
		num[2][1][2]=1;
		num[2][2][2]=1;
		num[2][3][2]=1;
		
		num[3][1][3]=1;
		num[3][2][3]=1;
		num[3][3][3]=1;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x,y,z,fllg=0;
				
				x=dp[i-1][1]+a[i].pa[j];
				for(int k=1;k<=3;k++){
					if(num[i-1][1][k]>=(n/2)) {
						x=max(dp[i-1][2],dp[i-1][3])+a[i].pa[j];
						fllg=1;
						break;
					}
				}
				if(fllg==0) num[1][j][j]++;
				fllg=0;
				
				y=dp[i-1][2]+a[i].pa[j];
				for(int k=1;k<=3;k++){
					if(num[i-1][2][k]>=(n/2)) {
						y=max(dp[i-1][1],dp[i-1][3])+a[i].pa[j];
						fllg=1;
						break;
					}
				}
				if(fllg==0) num[2][j][j]++;
				fllg=0;
				
				z=dp[i-1][3]+a[i].pa[j];
				for(int k=1;k<=3;k++){
					if(num[i-1][3][k]>=(n/2)) {
						z=max(dp[i-1][2],dp[i-1][1])+a[i].pa[j];
						fllg=1;
						break;
					}
				}
				if(fllg==0) num[3][j][j]++;
				fllg=0;
				
				
				dp[i][j]=max(x,max(y,z));
			}
		}
		ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cout<<ans<<"\n";
	}
	return 0;
}
//T1 jiu bao diao le..... 
//T2 3 buhui...
//T4 10tps...
//wuaaaaaaaaaaaa
//nan yi jie shi le a
//ying gai ye jiu 20...
//OI bye bye QAQ
//2025.11.1
