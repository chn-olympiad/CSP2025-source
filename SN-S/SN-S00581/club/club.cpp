#include<bits/stdc++.h>
using namespace std;
int t=0;
int n=0;
int a[10][10];
long long b[100005];
int flag[10][10];
int flag1[10];
long long maxx=INT_MIN;
void dfs(int x,long long sum,int a1,int a2,int a3)
{
	if(x>t)
	{
		maxx=max(maxx,sum);
		return;
	}
	else
	{
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(t==2)
				{
					if(j==1)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a1<n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1+1,a2,a3);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
					else if(j==2)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a2<n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1,a2+1,a3);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
					else if(j==3)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a3<n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1,a2,a3+1);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
				}
				else
				{
					if(j==1)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a1<=n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1+1,a2,a3);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
					else if(j==2)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a2<=n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1,a2+1,a3);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
					else if(j==3)
					{
						if(flag1[i]==0 and flag[i][j]==0 and a3<=n/2)
						{
							flag[i][j]=1;
							flag1[i]=1;
							dfs(x+1,sum+a[i][j],a1,a2,a3+1);
							flag[i][j]=0;
							flag1[i]=0;
						}
					}
				}				
			}
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long sum=0;
		cin>>t;
		for(int j=1;j<=t;j++)
		{
			for(int k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
		dfs(1,0,0,0,0);
		b[i]=maxx;
		maxx=INT_MIN;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[i]<<endl;
	}
	return 0;
}
