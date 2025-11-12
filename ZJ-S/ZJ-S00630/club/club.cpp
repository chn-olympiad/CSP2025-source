#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5+5;

int read();

void clr();

int t,n;
int a[MAXN][5]={};
int tmp[MAXN]={};

int dp[205][205][205]={},dp2[MAXN];

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		bool a_2_equals_0=true;
		bool a_3_equals_0=true;
		for(int i=1; i<=n; i++)
		{
			a[i][1]=read();
			a[i][2]=read();
			a[i][3]=read();
			if(a[i][2] != 0)
			{
				a_2_equals_0=false;
			}
			if(a[i][3] != 0)
			{
				a_3_equals_0=false;
			}
		}
		if(n <= 200)
		{
			clr();
			for(int i=1; i<=n; i++)
			{
				for(int c_1=0; c_1<=n>>1; c_1++)
				{
					for(int c_2=0; c_2<=n>>1; c_2++)
					{
						if(c_1 == 0)
						{
							if(c_2 == 0)
							{
								dp[i][c_1][c_2]=dp[i-1][c_1][c_2]+a[i][3];
							}
							else if(i-c_1-c_2 == 0)
							{
								dp[i][c_1][c_2]=dp[i-1][c_1][c_2-1]+a[i][2];
							}
							else
							{
								dp[i][c_1][c_2]=max(dp[i-1][c_1][c_2-1]+a[i][2],dp[i-1][c_1][c_2]+a[i][3]);	
							}
						}
						else if(c_2 == 0)
						{
							if(i-c_1-c_2 == 0)
							{
								dp[i][c_1][c_2]=dp[i-1][c_1-1][c_2]+a[i][1];
							}
							else
							{
								dp[i][c_1][c_2]=max(dp[i-1][c_1-1][c_2]+a[i][1],dp[i-1][c_1][c_2]+a[i][3]);
							}
						}
						else if(i-c_1-c_2 == 0)
						{
								dp[i][c_1][c_2]=max(dp[i-1][c_1-1][c_2]+a[i][1],dp[i-1][c_1][c_2-1]+a[i][2]);
						}
						else
						{
							dp[i][c_1][c_2]=max(max(dp[i-1][c_1-1][c_2]+a[i][1],dp[i-1][c_1][c_2-1]+a[i][2]),max(dp[i-1][c_1][c_2]+a[i][3],dp[i][c_1][c_2]));
						}
					}
				}
			}
			int maxn=-1;
			for(int i=0; i<=n>>1; i++)
			{
				for(int j=0; j<=n>>1; j++)
				{
					maxn=max(maxn,dp[n][i][j]);
				}
			}
			cout<<maxn<<endl;
		}
		else
		{		
			if(a_2_equals_0 && a_3_equals_0)
			{
				for(int i=1; i<=n; i++)
				{
					tmp[i]=a[i][1];
				}
				sort(tmp+1,tmp+n+1);
				int ans=0;
				for(int i=1; i<=n>>1; i++)
				{
					ans+=tmp[i];
				}
				cout<<ans<<endl;
			}
			else if(a_3_equals_0)
			{
				for(int i=0; i<=n; i++)
				{
					dp2[i]=0;
				}
				dp2[1]=a[1][1];
				dp2[0]=a[1][2];
				int j=0;
				for(int i=2; i<=n; i++)
				{
					if(dp2[j-1]+a[i][1] > dp2[j]+a[i][2])
					{
						dp2[j]=dp2[j-1]+a[i][1];
						j++;
					}
					else
					{
						dp2[j]=dp2[j]+a[i][2];
					}
				}
				cout<<dp2[j]<<endl;
			}
			else
			{
				int ans=0;
				for(int i=1; i<=n; i++)
				{
					ans+=max(max(a[i][1],a[i][2]),a[i][3]);
				}
				cout<<ans<<endl;
			}
//			int c[3]={};
//			bool f[3]={false,false,false};
//			for(int i=1; i<=n; i++)
//			{
//				f[1]=f[2]=false;
//				if(c[1]+1 <= n>>1)
//				{	
//					f[1]=true;
//					dp[i][1][1]=max(dp[i-1][0][1]+a[i][1],dp[i][1][1]);
//					dp[i][1][0]=max(dp[i-1][0][0]+a[i][1],dp[i][1][0]);
//				}
//				if(c[2]+1 <= n>>1)
//				{
//					f[2]=true;
//					dp[i][1][1]=max(dp[i-1][1][0]+a[i][2],dp[i][1][1]);
//					dp[i][0][1]=max(dp[i-1][0][0]+a[i][2],dp[i][0][1]);
//				}
//				if(i-c[1]-c[2]+1 <= n>>1)
//				{
//					dp[i][1][1]=max(dp[i-1][1][1]+a[i][3],dp[i][1][1]);
//					dp[i][0][0]=max(dp[i-1][0][0]+a[i][3],dp[i][0][0]);
//					dp[i][1][0]=max(dp[i-1][1][0]+a[i][3],dp[i][1][0]);
//					dp[i][0][1]=max(dp[i-1][0][1]+a[i][3],dp[i][0][1]);
//				}
//				if(f[1])
//				{
//					c[1]++;
//				}
//				if(f[2])
//				{
//					c[2]++;
//				}
//			}
//			cout<<dp[n][1][1]<<endl;
		}
	}
	return 0;
}

int read()
{
	int d=0,f=1;
	char c=getchar();
	while(c > '9' || c < '0')
	{
		if(c == '-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c >= '0' && c <= '9')
	{
		d=(d<<3)+(d<<1)+c-'0';
		c=getchar();
	}
	return d*f;
}

void clr()
{
	for(int i=0; i<=204; i++)
	{
		for(int j=0; j<=204; j++)
		{
			for(int k=0; k<=204; k++)
			{
				dp[i][j][k]=0;
			}
		}
	}
	return;
}
