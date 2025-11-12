#include<iostream>
#include<algorithm>
using namespace std;
int t,n,dp[101][101][101],ans;
bool b;
struct mem{
	int x1,x2,x3;
}m[100000];
bool cmp(mem m1,mem m2){
	return m1.x1-m1.x2<m2.x1-m2.x2;
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
	    scanf("%d",&n),b=1;
	    for(int i=0;i<n;i++){
		    scanf("%d%d%d",&m[i].x1,&m[i].x2,&m[i].x3);
		    b&=(!m[i].x3);
	    }if(n<=200){
	    	ans=0;
		    for(int i=0;i<=(n>>1);i++){
			    for(int j=0;j<=(n>>1);j++){
				    for(int k=0;k<=min(n>>1,n-i-j);k++){
				    	dp[i][j][k]=0;
					    if(i)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+m[i+j+k-1].x1);
					    if(j)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+m[i+j+k-1].x2);
					    if(k)dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+m[i+j+k-1].x3);
				    }ans=max(ans,dp[i][j][n-i-j]);
			    }
		    }
	    }if(b){
	    	ans=0;
		    sort(m,m+n,cmp);
		    for(int i=0;i<(n>>1);i++)ans+=m[i].x2;
		    for(int i=(n>>1);i<n;i++)ans+=m[i].x1;
	    }printf("%d\n",ans);
	}return 0;
}
