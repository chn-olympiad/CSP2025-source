#include<bits/stdc++.h>
using namespace std;
int n,t,dp[210][110][110],a,b,c,ans,a1[100010],b1[100010],c1[100010],d1[100010],f1,f2,f3,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n;
		if(n<=200){
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a,&b,&c);
				for(int j=0;j<=min(n/2,i);j++)
					for(int k=0;k<=min(n/2,i);k++){
						if(i-j-k>n/2) continue;
						if(j!=0)
							dp[i][j][k]=max(dp[i-1][j-1][k]+a,dp[i][j][k]);
						if(k!=0)
							dp[i][j][k]=max(dp[i-1][j][k-1]+b,dp[i][j][k]);
						if(i-j-k!=0)
							dp[i][j][k]=max(dp[i-1][j][k]+c,dp[i][j][k]);
					}				
			}
			for(int j=1;j<=n/2;j++)
				for(int k=1;k<=n/2;k++){
					if(n-j-k>n/2) continue;
					ans=max(ans,dp[n][j][k]);
				}	
			cout<<ans<<"\n";
		}
		else{
			sum=0,f1=0,f2=0,f3=0;
			for(int i=1;i<=n;i++){
				scanf("%d%d%d",&a1[i],&b1[i],&c1[i]);
				if(a1[i]!=0) f1=1;
				if(b1[i]!=0) f2=1;
				if(c1[i]!=0) f3=1;
			}
			if(f2==0&&f3==0){
				sort(c1+1,c1+n+1);
				for(int i=n;i>n/2;i--)
					sum+=c1[i];
				cout<<sum<<"\n";
			}
			else{
				for(int i=1;i<=n;i++)
					d1[i]=b1[i]-a1[i],sum+=b1[i];
				sort(d1+1,d1+n+1);
				for(int i=1;i<=n/2;i++)
					sum-=d1[i];
				cout<<sum<<"\n";				
			}
		}
	}
}