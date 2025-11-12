/*防伪标识：十年OI一场空，不开long long见祖宗*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,M=5010;
int t,n,a[N][5],dp[M][M],dpnew[M][M],f[M],fnew[M];
vector<int> vc;
void solveA()
{
	vc.clear();
	for(int i=1;i<=n;i++) vc.push_back(a[i][1]);
	sort(vc.begin(),vc.end());
	int ans=0;
	for(int i=n-1;i>=n/2;i--)
	{
		ans+=vc[i];
	}
	printf("%d\n",ans);
	return ;
}
void solveB()
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		for(int j=max(0,i-n/2);j<=min(i,n/2);j++)
		{
			fnew[j]=f[j];
			if(j>0) fnew[j]=max(fnew[j],f[j-1]+a[i][1]);
			if(i-j>0) fnew[j]=max(fnew[j],f[j]+a[i][2]);
		}
		for(int j=max(0,i-n/2);j<=min(i,n/2);j++)
		{
			f[j]=fnew[j];
		}
	}
	printf("%d\n",f[n/2]);
	return ;
}
void solve()
{
	memset(a,0,sizeof(a));
	memset(dp,0,sizeof(dp));
	memset(dpnew,0,sizeof(dpnew));
	scanf("%d",&n);
	bool flA=1,flB=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][2]!=0||a[i][3]!=0) flA=0;
			if(a[i][3]!=0) flB=0;
		}
	}
	if(flA)
	{
		solveA();
		return ;
	}
	if(flB)
	{
		solveB();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i,n/2);j++)
		{
			for(int k=max(0,i-j-n/2);k<=min(n/2,i-j);k++)//
			{
				//cout<<i<<" "<<j<<" "<<k<<" "<<i-j-k<<"\n";
				dpnew[j][k]=dp[j][k];
				if(j>0) dpnew[j][k]=max(dpnew[j][k],dp[j-1][k]+a[i][1]);
				if(k>0) dpnew[j][k]=max(dpnew[j][k],dp[j][k-1]+a[i][2]);
				if(i-j-k>0) dpnew[j][k]=max(dpnew[j][k],dp[j][k]+a[i][3]);
			}
		}
		for(int j=0;j<=min(i,n/2);j++)
		{
			for(int k=max(0,i-j-n/2);k<=min(n/2,i-j);k++)
			{
				dp[j][k]=dpnew[j][k];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			if(n-i-j>n/2) continue;
			//cout<<"////"<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return ;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
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

1
6
5 0 0
8 0 0
4 0 0
1 0 0
2 0 0
3 0 0

1
4
5 1 0
8 5 0
4 9 0
1 4 0

*/
