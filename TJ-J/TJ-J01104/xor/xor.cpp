#include<bits/stdc++.h>
using namespace std;
const int MAXS=100005;
int n,u;
int m[MAXS];
int dp[MAXS][MAXS];
int newdp[MAXS][MAXS];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>u;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=m[i];
	}
	for(int i=1;i<n;i++){
		for(int k=1;k<=n-i;k++){
			int j=i+k;
			dp[i][j]=dp[i][j-1]^m[j];
		}
	}
	for(int i=1;i<n;i++){
		for(int k=0;k<=n-i;k++){
			int j=i+k;
			for(int v=i;v<=j;v++){
				newdp[i][j]=max(newdp[i][j],newdp[i][v]+newdp[v][j]);
			}
			if(dp[i][j]==k)newdp[i][j]++;
		}
	}
	cout<<newdp[1][n]<<endl;
	return 0;
}
