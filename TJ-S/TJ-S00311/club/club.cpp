#include<bits/stdc++.h>
using namespace std;
int t,n;
struct myd{
	int sum,cnt[3];
}dp[100009][3];
struct cy{
	int a[3],d,z,x,cz1;
}c[100009];
bool cmp(cy p,cy q){
	return p.cz1>q.cz1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int a[3];
		for(int i=1;i<=n;i++){
			c[i].a[0]=c[i].a[1]=c[i].a[2]=c[i].cz1=c[i].d=0;
		}
		for(int i=1;i<=n;i++){
			cin>>c[i].a[0]>>c[i].a[1]>>c[i].a[2];
			c[i].d=max(c[i].a[0],max(c[i].a[1],c[i].a[2]));
			c[i].x=min(c[i].a[0],min(c[i].a[1],c[i].a[2]));
			c[i].cz1=c[i].d-(c[i].a[0]+c[i].a[1]+c[i].a[2]-c[i].d-c[i].x);
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<3;j++){
				dp[i][j].sum=0;
				for(int k=0;k<3;k++){
					dp[i][j].cnt[k]=0;
				}
			}
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(dp[i-1][k].cnt[j]<n/2&&dp[i-1][k].sum+c[i].a[j]>dp[i][j].sum){
						dp[i][j].sum=dp[i-1][k].sum+c[i].a[j];
						dp[i][j].cnt[0]=dp[i-1][k].cnt[0];
						dp[i][j].cnt[1]=dp[i-1][k].cnt[1];
						dp[i][j].cnt[2]=dp[i-1][k].cnt[2];
						dp[i][j].cnt[j]++;
					}
				}
				//cout<<c[i].a[j]<<" ";
			}
			//cout<<c[i].cz1<<"\n";
			//cout<<"\n";
		}
		cout<<max(dp[n][0].sum,max(dp[n][1].sum,dp[n][2].sum));
		cout<<"\n";
	}
	return 0;
}
