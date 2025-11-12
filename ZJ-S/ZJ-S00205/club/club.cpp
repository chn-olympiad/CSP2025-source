#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;
int n,t,ans;
int a[N][4];
int k[N],f[2][N/2+5];
int dp[2][N/2+5][N/2+5];
void work(){
	int ans;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=min(i,n/2);j++){
		int t=i%2;
		f[t][j]=max(f[1-t][j-1]+a[i][1],f[1-t][j]+a[i][2]);
		if(i==n) ans=max(ans,f[t][j]);
	}
	printf("%d\n",ans);
}
void solv(){
	ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=3;j++)
		scanf("%d",&a[i][j]);
	bool flag=true;
	for(int i=1;i<=n;i++)
	for(int j=2;j<=3;j++)
		if(a[i][j]) flag=false;
	if(flag){
		for(int i=1;i<=n;i++)
			k[i]=a[i][1];
		sort(k+1,k+n+1);
		for(int i=n;i>=n/2+1;i--)
			ans+=k[i];
		printf("%d\n",ans);
		return ;
	}
	flag=true;
	for(int i=1;i<=n;i++)
		if(a[i][3]) flag=false;
	if(flag){
		work();
		return ;
	}
	for(int i=0;i<=n/2;i++)
	for(int j=0;j<=n/2;j++)
	for(int k=0;k<=1;k++)
		dp[k][i][j]=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=min(i,n/2);j++)
	for(int k=0;k<=min(i-j,n/2);k++){
		int t=i%2,maxx=INT_MIN;
		if(j>=1) maxx=max(maxx,dp[1-t][j-1][k]+a[i][1]);
		if(k>=1) maxx=max(maxx,dp[1-t][j][k-1]+a[i][2]);
		if(i>j+k) maxx=max(maxx,dp[1-t][j][k]+a[i][3]);
		dp[t][j][k]=maxx;
		if(i==n) ans=max(ans,maxx);
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solv();
	return 0;
}
