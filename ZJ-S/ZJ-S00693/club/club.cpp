#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int T,n,i,j,k,l,s,ma,ans,a1,a2,a3,maB,x[N],y[N],z[N],q[N],
f[35][35][35][35],dp[N][2];
void dfs(int t,int s1,int s2,int s3,int s){
	if(s1>n/2) return ;
	if(s2>n/2) return ;
	if(s3>n/2) return ;
	if(t==n+1){
		ma=max(ma,s);
		return ;
	}
	dfs(t+1,s1+1,s2,s3,s+x[t]);
	dfs(t+1,s1,s2+1,s3,s+y[t]);
	dfs(t+1,s1,s2,s3+1,s+z[t]);
}
int maxn(int a1,int a2,int a3){return max(a1,max(a2,a3));}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ma=0;maB=-2e9;
		for(i=1;i<=n;i++)
			cin>>x[i]>>y[i]>>z[i],maB=max(maB,y[i]);
		for(i=n;i>=1;i--) q[i]=max(x[i],max(y[i],z[i]))+q[i+1];
		if(n<=10){
			dfs(1,0,0,0,0);
			cout<<ma<<"\n";
		}
		else if(n<=30){
			ans=0;memset(f,0,sizeof(f));
			for(i=1;i<=n;i++)
				for(j=0;j<=n;j++)
					for(k=0;k<=n;k++)
						for(l=0;l<=n;l++){
							if(j+k+l!=i) continue;
							if(j>0) a1=f[i-1][j-1][k][l]+x[i];
							if(k>0) a2=f[i-1][j][k-1][l]+y[i];
							if(l>0) a3=f[i-1][j][k][l-1]+z[i];
							f[i][j][k][l]=maxn(a1,a2,a3);
						}
			for(j=0;j<=n;j++)
				for(k=0;k<=n;k++)
					for(l=0;l<=n;l++){
						if(j+k+l!=n) continue;
						if(j>n/2) continue;
						if(k>n/2) continue;
						if(l>n/2) continue;
						ans=max(ans,f[n][j][k][l]);
					}
			cout<<ans<<"\n";
		}
		else if(maB==0){
			sort(x+1,x+n+1);s=0;
			for(i=n;i>=n/2+1;i--) s=s+x[i];
			cout<<s<<"\n";
		}
		else{
			for(i=1;i<=n;i++)
				dp[i][0]=max(dp[i-1][0],dp[i-1][1])+x[i],
				dp[i][1]=max(dp[i-1][0],dp[i-1][1])+y[i];
			cout<<max(dp[n][0],dp[n][1])<<"\n";
		}
	}
	return 0;
}
//20