#include<bits/stdc++.h>
using namespace std;
int const N=100001;
int sum[3],vis[N];
int T,n;
struct node{
	int id,zl,x,y;
}a[4*N];	
struct node1{
	int zl,x;
};
int b[N][3],c[N];
int dp[205][205][205];
bool cmp(node t1,node t2)
{
	return t1.x>t2.x;
}	
bool cmp1(int t1,int t2)
{
	return t1>t2;
}	
int flagA,flagB;
void pts_A()
{
	for(int i=1;i<=n;i++)
		c[i]=b[i][1];
	sort(c+1,c+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++)
		ans+=c[i];
	cout<<ans<<'\n';
	return ;
}
void pts_B()
{
	sum[1]=0,sum[2]=0,sum[3]=0;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	int js=0;
	for(int i=1;i<=n;i++)
	{
		a[++js]={i,1,b[i][1]-b[i][2]};
		a[++js]={i,2,b[i][2]-b[i][1]};
	}
	sort(a+1,a+2*n+1,cmp);
	int ans=0;
	for(int i=1;i<=2*n;i++)
	{
		int id=a[i].id,zl=a[i].zl,x=a[i].x;
		if(sum[zl]+1>n/2 || vis[id]>0)
			continue;
		ans+=b[id][zl];
		sum[zl]++;
		vis[id]=1;
	}	
	cout<<ans<<'\n';
	return ;
}	
void pts_1()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)	
				dp[i][j][k]=0;
	for(int i=0;i<=n-1;i++)
		for(int j=0;j<=min(i,n/2);j++)
			for(int k=0;k<=min(i,n/2);k++)
			{
				if(i-j-k>n/2 || i-j-k<0)
					continue;
				if(j+1<=n/2)
					dp[i+1][j+1][k]=max(dp[i+1][j+1][k],dp[i][j][k]+b[i+1][1]);
				if(k+1<=n/2)
				{
					dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]+b[i+1][2]);
				}
				if(i-j-k+1<=n/2)
				{
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+b[i+1][3]);
				}
			}
	int ans=0;
	for(int i=1;i<=n/2;i++)
		for(int j=1;j<=n/2;j++)
			if(n-i-j<=n/2)
				ans=max(ans,dp[n][i][j]);
	/*for(int i=1;i<=n;i++)
		for(int j=0;j<=n/2;j++)
			for(int k=0;k<=n/2;k++)
				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<'\n';*/
	cout<<ans<<'\n';
	return ;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int TT=1;TT<=T;TT++)
	{
		cin>>n;
		flagA=0,flagB=0;
		for(int i=1;i<=n;i++)	
		{
			cin>>b[i][1]>>b[i][2]>>b[i][3];
			if(b[i][2]!=0)
				flagA=1;
			if(b[i][3]!=0)
				flagB=1;
		}
		//for(int i=1;i<=n;i++)
		//	cout<<vis[i]<<'\n';
		if(flagA==0)
			pts_A();
		else if(flagB==0)
			pts_B();
		else
			pts_1();
	}
	
}
