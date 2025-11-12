#include<bits/stdc++.h>
using namespace std;
int t,n;
struct member{
	int a1,a2,a3;
}a[100005];
int dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof dp);
		scanf("%d",&n);
		int t1=0,t2=0,t3=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			t1=max(t1,a[i].a1);
			t2=max(t2,a[i].a2);
			t3=max(t3,a[i].a3);
		}if(t2==0&&t3==0){
			priority_queue<int>pq;
			for(int i=1;i<=n;i++){
				pq.push(a[i].a1);
			}int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=pq.top();
				pq.pop();
			}printf("%d\n",ans);
		}else{
			for(int i=1;i<=n;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						int l=i-j-k;
						if(l>n/2)continue;
						if(l<0)continue;
						dp[i][j][k]=max({(j!=0)?dp[i-1][j-1][k]+a[i].a1:0,(k!=0)?dp[i-1][j][k-1]+a[i].a2:0,(l!=0)?dp[i-1][j][k]+a[i].a3:0});
					}
				}
			}int ans=0;
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					int k=n-i-j;
					if(k<=n/2&&k>=0){
						ans=max(ans,dp[n][i][j]);
					}
				}
			}printf("%d\n",ans);
		}
		
	}
	return 0;
}