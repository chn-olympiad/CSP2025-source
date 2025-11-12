#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N1=205,N2=1e6+5;
int n,t,w[N2][4],ans;
void dfs(int k,int val,int a,int b,int c){
	if(k==n){
		ans=max(ans,val);
		return;
	}
	if(a<n/2)dfs(k+1,val+w[k+1][1],a+1,b,c);
	if(b<n/2)dfs(k+1,val+w[k+1][2],a,b+1,c);
	if(c<n/2)dfs(k+1,val+w[k+1][3],a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=-1;
		for(int i=1;i<=n;i++)scanf("%d%d%d",&w[i][1],&w[i][2],&w[i][3]);
		dfs(0,0,0,0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
dp[i][j]=max(dp[i][j],dp[i-1][j]+w[id][1],dp[i][j-1]+w[id][2],dp[i-1][j-1]+w[id][3])
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
