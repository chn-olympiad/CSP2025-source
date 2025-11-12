#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdio>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<vector>
#include<stack>
using namespace std;
int mem[100005][4];
long long dp[100005][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=100005;i++){
			for(int j=1;j<=3;j++){
				mem[i][j]=0;
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>mem[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			int c1=mem[i][1];
			int c2=mem[i][2];
			int c3=mem[i][3];
			int Max=max(c1,max(c2,c3));
			for(int j=1;j<=3;j++){
				dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]))+mem[i][j];
			}
		}
		cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
	} 
	return 0;
}

