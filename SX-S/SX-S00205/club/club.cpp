#include<bits/stdc++.h>
using namespace std;
int t,n,ar[6][100005],dp[205][205][205],ans;
bool A;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		A=1;
		for(int i=1;i<=n;i++){
			cin>>ar[1][i]>>ar[2][i]>>ar[3][i];
			if(ar[2][i]!=0||ar[3][i]!=0) A=0;
		}ans=0;
		if(A){
			sort(ar[1]+1,ar[1]+1+n);
			for(int i=1;i<=(n>>1);i++) ans+=ar[1][i];
			cout<<ans<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			int m=min(n/2,i);
			for(int a=0;a<=m;a++){
				for(int b=0;b<=m;b++){
					if(a>=1) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a-1][b]+ar[1][i]);
					if(b>=1) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a][b-1]+ar[2][i]);
	  if(i-a-b>=1&&i-a-b<=m) dp[i][a][b]=max(dp[i][a][b],dp[i-1][a]  [b]+ar[3][i]);
					ans=max(dp[n][a][b],ans);
//					printf("dp[%d][%d][%d]==%d\n",i,a,b,dp[i][a][b]);
				}
			}
		}
//		cout<<"£Á£î£ó£÷£å£ò¡¡£É£ó£º";
		cout<<ans<<endl;
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