#include<bits/stdc++.h>
using namespace std;
int T,n;
struct s{
	int a[4];
	int b[4];
}stu[100100];
struct node{
	int val,num[4];
}dp[100100][4];
bool cmp(s x,s y){
	if(x.b[1]==y.b[1]){
		if(x.b[2]==y.b[2])return x.b[3]>y.b[3];
		return x.b[2]>y.b[2];
	}
	return x.b[1]>y.b[1];
}
int ans;
void dfs(int sum,int x,int y,int z,int cur){
	if(cur==n+1){
		ans=max(ans,sum);
		return ;	
	}
	for(int i=1;i<=3;i++){
		if(i==1&&x+1<=n/2)dfs(sum+stu[cur].a[i],x+1,y,z,cur+1);
		if(i==2&&y+1<=n/2)dfs(sum+stu[cur].a[i],x,y+1,z,cur+1);
		if(i==3&&z+1<=n/2)dfs(sum+stu[cur].a[i],x,y,z+1,cur+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		bool A=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			stu[i].b[1]=stu[i].b[2]=stu[i].b[3]=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&stu[i].a[j]);
				dp[i][j].val=INT_MIN;
				dp[i][j].num[1]=dp[i][j].num[2]=dp[i][j].num[3]=0;
			}
			if(stu[i].a[2]||stu[i].a[3])A=0;
			stu[i].b[1]=max(max(stu[i].a[1],stu[i].a[2]),stu[i].a[3]);
			stu[i].b[3]=min(min(stu[i].a[1],stu[i].a[2]),stu[i].a[3]);
			stu[i].b[2]=stu[i].a[1]+stu[i].a[2]+stu[i].a[3]-(stu[i].b[1]+stu[i].b[3]);
		}
		sort(stu+1,stu+n+1,cmp);
		if(A){
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=stu[i].a[1];
		}
		else{
			if(n>10){
				for(int i=1;i<=n;i++){
					for(int j=1;j<=3;j++){
						for(int k=1;k<=3;k++){
							if(dp[i-1][k].num[j]+1<=n/2){
								if(dp[i-1][k].val+stu[i].a[j]>=dp[i][j].val){
									dp[i][j].val=dp[i-1][k].val+stu[i].a[j];
									dp[i][j].num[1]=dp[i-1][k].num[1];
									dp[i][j].num[2]=dp[i-1][k].num[2];
									dp[i][j].num[3]=dp[i-1][k].num[3];
									dp[i][j].num[j]++;
								}
							}
						}
					}
				}
				ans=max(max(dp[n][1].val,dp[n][2].val),dp[n][3].val);
			}
			else{
				ans=0;
				dfs(0,0,0,0,1);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
