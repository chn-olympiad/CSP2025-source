#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e5+10;
struct node{
	int u;
	int v;
	int w;
};
node a[M];
int n;
int dp[205][205][205];
bool cmp(node x,node y)
{
	return x.u>y.u;
}
priority_queue<pair<int,int> > q;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
    	memset(dp,0,sizeof(dp));
    cin>>n;
    bool flaga=1;
    bool flagb=1;
    bool flagc=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].u>>a[i].v>>a[i].w;
    	if(a[i].v!=0||a[i].w!=0)
    	flaga=0;
    	if(a[i].w!=0)
    	flagb=0;
	}
	if(flaga==1)
	{
		int ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		ans+=a[i].u;
		cout<<ans;
	    continue; 
	}
	if(flagb)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].u>a[i].v)
			q.push({abs(a[i].u-a[i].v),i});
			else
			q.push({abs(a[i].u-a[i].v),i});
		}
		int num1=0;
		int num2=0;
		while(q.size())
		{
			int opt=q.top().second;
			q.pop();
			if(a[opt].u>a[opt].v&&num1==n/2)
			{
				ans+=a[opt].v;
				num2++;
			}
			if(a[opt].u<=a[opt].v&&num2==n/2)
			{
				ans+=a[opt].u;
				num1++;
			}
			if(a[opt].u>a[opt].v&&num1<n/2)
			{
				ans+=a[opt].u;
				num1++;
			}
			if(a[opt].u<=a[opt].v&&num2<n/2)
			{
				ans+=a[opt].v;
				num2++;
			}
		}
		cout<<ans<<endl;
		continue;
	 } 
	dp[1][1][0]=a[1].u;
	dp[1][0][1]=a[1].v;
	dp[1][0][0]=a[1].w;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n/2;j++)
		{
			for(int k=0;k<=n/2;k++)
	        {
//	        	if(n-j-k>n/2)
//	        	continue;
	        	if(j>=1)
				dp[i][j][k]=max(dp[i-1][j-1][k]+a[i].u,dp[i][j][k]);
				if(k>=1)
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i].v);
				if(i-j-k>=1)
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i].w);
			}
		}
	}
	int ans=0;
	for(int j=0;j<=n/2;j++)
	{
	  for(int k=0;k<=min(n-j,n/2);k++)
	  {
	  	if(n-j-k>n/2)
	  	continue;
//	  	cout<<"!!!!"<<j<<" "<<k<<" "<<dp[n][j][k]<<endl;
         ans=max(ans,dp[n][j][k]);
	  }
	}
	cout<<ans<<endl;
 }
 
	return 0;
} 
//Ren5Jie4Di4Ling5%
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926



1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
