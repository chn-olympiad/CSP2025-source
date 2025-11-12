#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,dp[N][N][N];
struct sut{
	int a,b,c;
	int vis;
}s[N];
int p[4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(s,0,sizeof s);
		memset(dp,0,sizeof dp);
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
		}
	for(int i=1;i<=n;i++){
		for(int j1=n/2;j1>=0;j1--){
			for(int j2=n/2;j2>=0;j2--){
				for(int j3=n/2;j3>=0;j3--){
					int maxm=0;
					if(j1>0)maxm=max(maxm,dp[j1-1][j2][j3]+s[i].a);
					if(j2>0)maxm=max(maxm,dp[j1][j2-1][j3]+s[i].b);
					if(j3>0)maxm=max(maxm,dp[j1][j2][j3-1]+s[i].c);
					dp[j1][j2][j3]=max(dp[j1][j2][j3],maxm);
				}
				
			}
		}
	}
	cout<<dp[n/2][n/2][n/2]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}