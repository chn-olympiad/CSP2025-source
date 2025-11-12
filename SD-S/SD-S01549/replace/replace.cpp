#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n,c;
struct aaa{
	int x,y,z,ans;
};
aaa a[N];
aaa dp[N][4];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);	
	cin>>T;
	while(T--){
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		cin>>n;
		c=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		for(int i=1;i<=n;i++){
			if(dp[i-1][1].z+1<=c){
				dp[i][3].z=dp[i-1][1].z+1;
				dp[i][3].ans=dp[i-1][1].ans+a[i].z;
			}
			else{
				dp[i][3].z=dp[i-1][1].z;
				dp[i][3].ans=dp[i-1][1].ans;
			}
			dp[i][3].y=dp[i-1][1].y;
			dp[i][3].x=dp[i-1][2].x;
			
			if(dp[i-1][1].y+1<=c){
				dp[i][2].y=dp[i-1][1].y+1;
				dp[i][2].ans=dp[i-1][1].ans+a[i].y;
			}
			else{
				dp[i][2].y=dp[i-1][1].y;
				dp[i][2].ans=dp[i-1][1].ans;
			}
			dp[i][2].x=dp[i-1][3].x;
			dp[i][2].z=dp[i-1][1].z;
			
			if(dp[i-1][2].x+1<=c){
				dp[i][1].x=dp[i-1][2].x+1;
				dp[i][1].ans=dp[i-1][2].ans+a[i].x;
			}
			else{
				dp[i][1].x=dp[i-1][2].x;
				dp[i][1].ans=dp[i-1][2].ans;
			}
			dp[i][1].y=dp[i-1][3].y;
			dp[i][1].z=dp[i-1][2].z;
		}
		for(int i=1;i<=n;i++){
			cout<<dp[i][3].ans<<" "<<dp[i][2].ans<<" "<<dp[i][1].ans<<endl;
		}
		int anss=0;
		anss=max(anss,dp[n][3].ans);
		anss=max(anss,dp[n][2].ans);
		anss=max(anss,dp[n][1].ans);
		cout<<anss;		
		cout<<endl;
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

18
4
13

*/
