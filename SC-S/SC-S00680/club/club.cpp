#include<bits/stdc++.h>
using namespace std;

int t,dp[100001][4],dp2[100001][4][4];
struct student{
	int a1,a2,a3;
}stu[100001];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(dp,0,sizeof(dp));
		memset(dp2,0,sizeof(dp2));
		for(int i=1;i<=n;i++){
			cin>>stu[i].a1>>stu[i].a2>>stu[i].a3;
			int d1=0,d2=0,d3=0;
			if(dp2[i-1][1][1]==n/2){
				if(dp2[i-1][2][1]==n/2){
					if(dp2[i-1][3][1]==n/2){
						//do nothing
					}else{
						dp[i][1]=max(dp[i][1],dp[i-1][3]+stu[i].a1);
						if(dp[i][1]<=dp[i-1][3]+stu[i].a1){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][1]=max(dp[i][1],dp[i-1][2]+stu[i].a1);
					if(dp[i][1]<=dp[i-1][2]+stu[i].a1){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][1]==n/2){
						//do nothing
					}else{
						dp[i][1]=max(dp[i][1],dp[i-1][3]+stu[i].a1);
						if(dp[i][1]<=dp[i-1][3]+stu[i].a1){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}else{
				dp[i][1]=max(dp[i][1],dp[i-1][1]+stu[i].a1);
				if(dp[i][1]<=dp[i-1][1]+stu[i].a1){
					d1=dp2[i-1][1][1];
					d2=dp2[i-1][1][2];
					d3=dp2[i-1][1][3];
				}
				if(dp2[i-1][2][1]==n/2){
					if(dp2[i-1][3][1]==n/2){
						//do nothing
					}else{
						dp[i][1]=max(dp[i][1],dp[i-1][3]+stu[i].a1);
						if(dp[i][1]<=dp[i-1][3]+stu[i].a1){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][1]=max(dp[i][1],dp[i-1][2]+stu[i].a1);
					if(dp[i][1]<=dp[i-1][2]+stu[i].a1){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][1]==n/2){
						//do nothing
					}else{
						dp[i][1]=max(dp[i][1],dp[i-1][3]+stu[i].a1);
						if(dp[i][1]<=dp[i-1][3]+stu[i].a1){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}if(dp[i][1]!=0){
				dp2[i][1][1]=d1+1;
				dp2[i][1][2]=d2;
				dp2[i][1][3]=d3;
			}if(dp2[i-1][1][2]==n/2){
				if(dp2[i-1][2][2]==n/2){
					if(dp2[i-1][3][2]==n/2){
						//do nothing
					}else{
						dp[i][2]=max(dp[i][2],dp[i-1][3]+stu[i].a2);
						if(dp[i][2]<=dp[i-1][3]+stu[i].a2){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][2]=max(dp[i][2],dp[i-1][2]+stu[i].a2);
					if(dp[i][2]<=dp[i-1][2]+stu[i].a2){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][2]==n/2){
						//do nothing
					}else{
						dp[i][2]=max(dp[i][2],dp[i-1][3]+stu[i].a2);
						if(dp[i][2]<=dp[i-1][3]+stu[i].a2){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}else{
				dp[i][2]=max(dp[i][2],dp[i-1][1]+stu[i].a2);
				if(dp[i][2]<=dp[i-1][1]+stu[i].a2){
					d1=dp2[i-1][1][1];
					d2=dp2[i-1][1][2];
					d3=dp2[i-1][1][3];
				}
				if(dp2[i-1][2][2]==n/2){
					if(dp2[i-1][3][2]==n/2){
						//do nothing
					}else{
						dp[i][2]=max(dp[i][2],dp[i-1][3]+stu[i].a2);
						if(dp[i][2]<=dp[i-1][3]+stu[i].a2){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][2]=max(dp[i][2],dp[i-1][2]+stu[i].a2);
					if(dp[i][2]<=dp[i-1][2]+stu[i].a2){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][2]==n/2){
						//do nothing
					}else{
						dp[i][2]=max(dp[i][2],dp[i-1][3]+stu[i].a2);
						if(dp[i][2]<=dp[i-1][3]+stu[i].a2){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}if(dp[i][2]!=0){
				dp2[i][2][1]=d1;
				dp2[i][2][2]=d2+1;
				dp2[i][2][3]=d3;
			}if(dp2[i-1][1][3]==n/2){
				if(dp2[i-1][2][3]==n/2){
					if(dp2[i-1][3][3]==n/2){
						//do nothing
					}else{
						dp[i][3]=max(dp[i][3],dp[i-1][3]+stu[i].a3);
						if(dp[i][3]<=dp[i-1][3]+stu[i].a3){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][3]=max(dp[i][3],dp[i-1][2]+stu[i].a3);
					if(dp[i][3]<=dp[i-1][2]+stu[i].a3){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][3]==n/2){
						//do nothing
					}else{
						dp[i][3]=max(dp[i][3],dp[i-1][3]+stu[i].a3);
						if(dp[i][3]<=dp[i-1][3]+stu[i].a3){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}else{
				dp[i][3]=max(dp[i][3],dp[i-1][1]+stu[i].a3);
				if(dp[i][3]<=dp[i-1][1]+stu[i].a3){
					d1=dp2[i-1][1][1];
					d2=dp2[i-1][1][2];
					d3=dp2[i-1][1][3];
				}
				if(dp2[i-1][2][3]==n/2){
					if(dp2[i-1][3][3]==n/2){
						//do nothing
					}else{
						dp[i][3]=max(dp[i][3],dp[i-1][3]+stu[i].a3);
						if(dp[i][3]<=dp[i-1][3]+stu[i].a3){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}else{
					dp[i][3]=max(dp[i][3],dp[i-1][2]+stu[i].a3);
					if(dp[i][3]<=dp[i-1][2]+stu[i].a3){
						d1=dp2[i-1][2][1];
						d2=dp2[i-1][2][2];
						d3=dp2[i-1][2][3];
					}
					if(dp2[i-1][3][3]==n/2){
						//do nothing
					}else{
						dp[i][3]=max(dp[i][3],dp[i-1][3]+stu[i].a3);
						if(dp[i][3]<=dp[i-1][3]+stu[i].a3){
							d1=dp2[i-1][3][1];
							d2=dp2[i-1][3][2];
							d3=dp2[i-1][3][3];
						}
					}
				}
			}if(dp[i][3]!=0){
				dp2[i][3][1]=d1;
				dp2[i][3][2]=d2;
				dp2[i][3][3]=d3+1;
			}
		}cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	}
    return 0;
}