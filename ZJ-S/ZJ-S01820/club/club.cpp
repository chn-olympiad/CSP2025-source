#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,num[5];
long long a[N][5],ans,b[N],dp[10000][5][500];
void dfs(int x,long long sum)
{//cout<<x<<" "<<sum<<endl;
	if(x==n+1)
	{
		ans=max(ans,sum);
		return ;
	}
	for(int i=1;i<=3;i++)
	{
		if(num[i]<=n/2-1)
		{
			num[i]++;
			dfs(x+1,sum+a[x][i]);
			num[i]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		int ha=0,hb=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][3]!=0)ha=hb=1;
			if(a[i][2]!=0)ha=1;
		}
		if(ha==0)
		{
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+1+n,greater<long long>());
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=b[i];
			printf("%lld\n",ans);
		}
		if(n<=10)
		{
			ans=0;
			dfs(1,0);
			printf("%lld\n",ans);
			continue;
		}
		for(int i=0;i<=n;i++)
		{
			for(int k=0;k<=n/2;k++)
				dp[i][1][k]=dp[i][2][k]=0;
		}
		dp[1][1][0]=a[1][1],dp[1][2][0]=a[1][2];
		for(int i=1;i<=n;i++)
		{
			for(int k=1;k<=n/2+1;k++)
			{
				if(k!=n/2+1)dp[i][1][k]=max(dp[i-1][1][k-1],dp[i-1][2][k-2])+a[i][1];
				dp[i][2][k-1]=max(dp[i-1][2][k-1],dp[i-1][2][k-1])+a[i][2];
			}
		}
		ans=0;
		for(int i=0;i<=n/2+1;i++)ans=max(dp[n][1][i],dp[n][2][i]);
		printf("%lld\n",ans);
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

a[i][j]<=2e4
*/