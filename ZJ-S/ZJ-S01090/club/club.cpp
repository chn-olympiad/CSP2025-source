#include<bits/stdc++.h>
using namespace std;
const int MAXN=100050;
int n,t;
struct node{
	int a,b,c;
}data[MAXN];
struct e{
	int a,b,c;
	int sum;
}dp[MAXN][5];
bool cmp(node x,node y){
	return (x.a+x.b+x.c)>(y.a+y.b+y.c);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>data[i].a>>data[i].b>>data[i].c;
		dp[i][1].sum=dp[i][2].sum=dp[i][3].sum=0;
		dp[i][1].a=dp[i][2].a=dp[i][3].a=0;
		dp[i][1].b=dp[i][2].b=dp[i][3].b=0;
		dp[i][1].c=dp[i][2].c=dp[i][3].c=0;
	}
	sort(data+1,data+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(dp[i-1][j].a<n/2&&dp[i-1][j].sum+data[i].a>dp[i][1].sum){
				dp[i][1].sum=dp[i-1][j].sum+data[i].a;
				dp[i][1].a=dp[i-1][j].a+1;
				dp[i][1].b=dp[i-1][j].b;
				dp[i][1].c=dp[i-1][j].c;
			}
		}
		for(int j=1;j<=3;j++){
			if(dp[i-1][j].b<n/2&&dp[i-1][j].sum+data[i].b>dp[i][2].sum){
				dp[i][2].sum=dp[i-1][j].sum+data[i].b;
				dp[i][2].a=dp[i-1][j].a;
				dp[i][2].b=dp[i-1][j].b+1;
				dp[i][2].c=dp[i-1][j].c;
			}
		}
		for(int j=1;j<=3;j++){
			if(dp[i-1][j].c<n/2&&dp[i-1][j].sum+data[i].c>dp[i][1].sum){
				dp[i][1].sum=dp[i-1][j].sum+data[i].c;
				dp[i][1].a=dp[i-1][j].a;
				dp[i][1].b=dp[i-1][j].b;
				dp[i][1].c=dp[i-1][j].c+1;
			}
		}
		
	}
	cout<<max(dp[n][1].sum,max(dp[n][2].sum,dp[n][3].sum))<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		solve();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}