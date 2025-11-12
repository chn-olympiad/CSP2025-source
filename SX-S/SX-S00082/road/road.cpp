#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int road[100][100],n,m,k,c[11],cou[11][100];
	cin>>n>>m>>k;
	memset(road,-1,sizeof(road));
	for(int i=1;i<=n;i++)
		road[i][i]=0;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		cin>>road[a][b];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>cou[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int q=1;q<=n;q++){
				if(road[j][q]=-1&&(road[j][q]>c[i]+cou[i][j]+cou[i][q]))
					road[j][q]=c[i]+cou[i][j]+cou[i][q];
			}
		}
	}
	int sum=0,dp[100][100];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j-1<0)
				dp[i][j]=dp[i-1][n]+road[i][j];
			else
				dp[i][j]=dp[i-1][j-1]+road[i][j];
		}
	}
	for(int i=2;i<n;i++){
		if(dp[n][i]<dp[n][1])
			dp[n][1]=dp[n][i];
	}
	cout<<dp[n][1];
	return 0;
}