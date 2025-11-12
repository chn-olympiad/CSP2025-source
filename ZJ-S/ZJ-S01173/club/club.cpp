#include<bits/stdc++.h>
using namespace std;
int t;
int a[100007][3];
int o[1007];
int dp[207][107][107];
int num,k;
void dfs(int u,int x,int ans){
	
	if(u==x+1){
		num=max(ans,num);
		k++;
		if(x>=50&&k==1000000){
			cout<<num;
			num=0;
			k=0;
			return;
		}
		//cout<<num<<endl;
	}
	if(o[0]<x/2){
		o[0]++;
		dfs(u+1,x,ans+a[u][0]);
		o[0]--;
	}
	if(o[1]<x/2){
		o[1]++;
		dfs(u+1,x,ans+a[u][1]);
		o[1]--;
	}
	if(o[2]<x/2){
		o[2]++;
		dfs(u+1,x,ans+a[u][2]);
		o[2]--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int x;
		int ans=0;
		cin>>x;
		if(x<=30){
			for(int i=1;i<=x;i++){
				scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			}
			dfs(1,x,0);
			cout<<num<<endl;
			num=0;
		}
		else if(x<=200){
			for(int i=1;i<=x;i++){
				scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			}
			for(int h=1;h<=x;h++)
				for(int i=0;i<=min(h,x/2);i++){
					dp[i][0][0]=max(dp[i][0][0],a[h][0]);
					for(int j=0;j<=min(h-i,x/2);j++){
						if(i-1>=0&&j-1>=0)dp[i][j][h-i-j]=max(dp[i-1][j][h-i-j]+a[h][0],dp[i][j-1][h-i-j]+a[h][1]);
						else if(i-1>=0&&h-i-j-1>=0)dp[i][j][h-i-j]=max(dp[i-1][j][h-i-j]+a[h][0],dp[i][j][h-i-j-1]+a[h][2]);
						else if(j-1>=0&&h-i-j-1>=0)dp[i][j][h-i-j]=max(dp[i][j-1][h-i-j]+a[h][1],dp[i][j][h-i-j-1]+a[h][2]);
						//cout<<h<<" "<<i<<" "<<j<<" "<<h-i-j<<" "<<dp[i][j][h-i-j]<<endl;
						ans=max(dp[i][j][h-i-j],ans);
					}
				}
				cout<<ans<<endl;
				for(int i=0;i<=200;i++){
					for(int j=0;j<=100;j++){
						for(int k=0;k<=100;k++){
							dp[i][j][k]=0;
						}
					}
				}
				//cout<<ans;
			}
			else{
				int flag=1;
				int y[100007];
				int m=0;
				for(int i=1;i<=x;i++){
					scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
					y[i]=a[i][0];
					if(a[i][1]!=0||a[i][2]!=0){
						flag=0;
					}
				}
				if(flag==1){
					sort(y+1,y+x+1);
					for(int i=x;i>=x/2;i--){
						ans+=y[i];
					}
					cout<<ans<<endl;
				}	
				else{
					dfs(1,x,0);
				}
			}
		}
	}
