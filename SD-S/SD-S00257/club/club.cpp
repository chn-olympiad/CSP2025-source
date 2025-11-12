#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,maxx=0;
}a[100005];
int cnt[100005][4][4];
long long dp[100005][5];
bool cmp(node x,node y){
	return x.maxx>y.maxx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].z);
			a[i].maxx=max(a[i].x,max(a[i].y,a[i].z));
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				int x=0,y=0,z=0;
				if(j==1){
					if(cnt[i-1][1][1]<n/2){
						x=dp[i-1][1];
					}
					if(cnt[i-1][2][1]<n/2){
						y=dp[i-1][2];
					}
					if(cnt[i-1][3][1]<n/2){
						z=dp[i-1][3];
					}
					if(x>=y&&x>=z){
						dp[i][1]=x+a[i].x;
						cnt[i][1][1]=cnt[i-1][1][1]+1;
						cnt[i][1][2]=cnt[i-1][1][2];
						cnt[i][1][3]=cnt[i-1][1][3];
					}
					else if(y>=x&&y>=z){
						dp[i][1]=y+a[i].x;
						cnt[i][1][1]=cnt[i-1][2][1]+1;
						cnt[i][1][2]=cnt[i-1][2][2];
						cnt[i][1][3]=cnt[i-1][2][3];
					}
					else{
						dp[i][1]=z+a[i].x;
						cnt[i][1][1]=cnt[i-1][3][1]+1;
						cnt[i][1][2]=cnt[i-1][3][2];
						cnt[i][1][3]=cnt[i-1][3][3];
					}
//					printf("%d %d %d\n",cnt[1][1],cnt[2][1],cnt[3][1]);
				}
				if(j==2){
					if(cnt[i-1][1][2]<n/2){
						x=dp[i-1][1];
					}
					if(cnt[i-1][2][2]<n/2){
						y=dp[i-1][2];
					}
					if(cnt[i-1][3][2]<n/2){
						z=dp[i-1][3];
					}
					if(x>=y&&x>=z){
						dp[i][2]=x+a[i].y;
						cnt[i][2][1]=cnt[i-1][1][1];
						cnt[i][2][2]=cnt[i-1][1][2]+1;
						cnt[i][2][3]=cnt[i-1][1][3];
					}
					else if(y>=x&&y>=z){
						dp[i][2]=y+a[i].y;
						cnt[i][2][1]=cnt[i-1][2][1];
						cnt[i][2][2]=cnt[i-1][2][2]+1;
						cnt[i][2][3]=cnt[i-1][2][3];
					}
					else{
						dp[i][2]=z+a[i].y;
						cnt[i][2][1]=cnt[i-1][3][1];
						cnt[i][2][2]=cnt[i-1][3][2]+1;
						cnt[i][2][3]=cnt[i-1][3][3];
					}
//					printf("%d %d %d\n",cnt[1][2],cnt[2][2],cnt[3][2]);
				}
				if(j==3){
					if(cnt[i-1][1][3]<n/2){
						x=dp[i-1][1];
					}
					if(cnt[i-1][2][3]<n/2){
						y=dp[i-1][2];
					}
					if(cnt[i-1][3][3]<n/2){
						z=dp[i-1][3];
					}
					if(x>=y&&x>=z){
						dp[i][3]=x+a[i].z;
						cnt[i][3][1]=cnt[i-1][1][1];
						cnt[i][3][2]=cnt[i-1][1][2];
						cnt[i][3][3]=cnt[i-1][1][3]+1;
					}
					else if(y>=x&&y>=z){
						dp[i][3]=y+a[i].z;
						cnt[i][3][1]=cnt[i-1][2][1];
						cnt[i][3][2]=cnt[i-1][2][2];
						cnt[i][3][3]=cnt[i-1][2][3]+1;
					}
					else{
						dp[i][3]=z+a[i].z;
						cnt[i][3][1]=cnt[i-1][3][1];
						cnt[i][3][2]=cnt[i-1][3][2];
						cnt[i][3][3]=cnt[i-1][3][3]+1;
					}
//					printf("%d %d %d\n",cnt[1][3],cnt[2][3],cnt[3][3]);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=3;j++){
//				printf("%d ",dp[i][j]);
//			}
//			printf("\n");
//		}
		printf("%lld\n",max(dp[n][1],max(dp[n][2],dp[n][3])));
	}
	return 0;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
