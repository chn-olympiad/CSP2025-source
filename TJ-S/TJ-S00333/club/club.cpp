#include <bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],maxn,dp[100005][4],s[100005][4][4];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
//		for(int i=1;i<=n;i++){
//			cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<"\n";
//		}
		memset(dp,0,sizeof(dp));
		maxn=0;
		memset(s,0,sizeof(s));
//		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=3;k++){
					int t;
					for(int l=1;l<=3;l++){
						if(s[j-1][l][k]==n/2){continue;}
						if(dp[j][k]<dp[j-1][l]+a[j][k]){
							dp[j][k]=dp[j-1][l]+a[j][k];
							t=l;
						}
					}
					for(int i=1;i<=3;i++)
					{
						if(i==k)s[j][k][k]=s[j-1][t][k]+1;
						else s[j][k][i]=s[j-1][t][i];
					}
				}
			}
//	}
//		for(int k=1;k<=n/2;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					maxn=max(maxn,dp[i][j]);
				}
			}
//		}
		cout<<maxn<<"\n";
	}
	
	return 0;
} 
