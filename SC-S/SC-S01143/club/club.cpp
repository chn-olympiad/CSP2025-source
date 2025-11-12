#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000010][5],ans,maxn,t01=1,t02=1,t03=1,b[1000010];
int n;
struct cm{
	int v,r1,r2,r3;
}dp[1000010][4];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		t01=t02=t03=1;
		for(int i=1;i<=n;i++){
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]!=0)t01=0;
			if(a[i][2]!=0)t02=0;
			if(a[i][3]!=0)t03=0;
		}
		if((t02==1&&t03==1)||(t01==1&&t02==1)||(t01==1&&t03==1)){
			if(t02==1&&t03==1)for(int i=1;i<=n;i++)b[i]=a[i][1];
			if(t01==1&&t03==1)for(int i=1;i<=n;i++)b[i]=a[i][2];
			if(t02==1&&t01==1)for(int i=1;i<=n;i++)b[i]=a[i][3];
			sort(b+1,b+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=b[i];
			}
			cout<<sum<<'\n';
		}
		else{
			dp[1][0]={a[1][1],1,0,0};
			dp[1][1]={a[1][2],0,1,0};
			dp[1][2]={a[1][3],0,0,1};
			for(int i=2;i<=n;i++){
				for(int j=0;j<3;j++){
					if(j==0){
						int x=0;
						for(int k=0;k<3;k++){
							if(dp[i-1][k].v+a[i][1]>x&&dp[i-1][k].r1<n/2){
								x=max(x,dp[i-1][k].v+a[i][1]);
								dp[i][j].r1=dp[i-1][k].r1+1;
								dp[i][j].r2=dp[i-1][k].r2;
								dp[i][j].r3=dp[i-1][k].r3;
                            }
						}
						dp[i][j].v=x;
					}
					if(j==1){
						int x=0;
						for(int k=0;k<3;k++){
							if(dp[i-1][k].v+a[i][2]>x&&dp[i-1][k].r2<n/2){
								x=max(x,dp[i-1][k].v+a[i][2]);
								dp[i][j].r1=dp[i-1][k].r1;
								dp[i][j].r2=dp[i-1][k].r2+1;
								dp[i][j].r3=dp[i-1][k].r3;
							}
						}
						dp[i][j].v=x;
					}
					if(j==2){
						int x=0;
						for(int k=0;k<3;k++){
							if(dp[i-1][k].v+a[i][3]>x&&dp[i-1][k].r3<n/2){
								x=max(dp[i-1][k].v+a[i][3],x);
								dp[i][j].r1=dp[i-1][k].r1;
								dp[i][j].r2=dp[i-1][k].r2;
								dp[i][j].r3=dp[i-1][k].r3+1;
                            }
						}
						dp[i][j].v=x;
					}
					maxn=max(maxn,dp[i][j].v);
				}
				dp[i-1][1]=dp[i-1][0]=dp[i-1][2]={0,0,0,0};
			}
			cout<<maxn<<"\n";
			maxn=0;
			dp[n][0]=dp[n][1]=dp[n][2]={0,0,0,0};
		}
	}
	return 0;
}