#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int N=1e5;
int n,t;
struct qwe
{
	int d[4]={0,0,0,0};
	bool bj[4]={0,0,0,0};
}a[N+1];
int dp[N+1][4];
bool cmp1(qwe a,qwe b)
{
	return a.d[1]>b.d[1];
}
bool cmp2(qwe a,qwe b)
{
	return a.d[2]>b.d[2];
}
bool cmp3(qwe a,qwe b)
{
	return a.d[1]-max(a.d[2],a.d[3])<b.d[1]-max(b.d[2],b.d[3]);
}
bool cmp4(qwe a,qwe b)
{
	return a.d[2]-max(a.d[1],a.d[3])<b.d[2]-max(b.d[1],b.d[3]);
}
bool cmp5(qwe a,qwe b)
{
	return a.d[3]-max(a.d[2],a.d[1])<b.d[3]-max(b.d[2],b.d[1]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		int maxx=(n>>1);
		for(int i=1;i<=n;i++)
		{
			a[i].d[1]=read();
			a[i].d[2]=read();
			a[i].d[3]=read();
			a[i].bj[1]=a[i].bj[2]=a[i].bj[3]=0;
			dp[i][1]=dp[i][2]=dp[i][3]=0;
		}
		sort(a+1,a+1+n,cmp2);
		sort(a+1,a+1+n,cmp1);
		/*
		cout<<"\n";
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<a[i].d[j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		*/
		int s[4]={0,0,0,0};
		for(int i=1;i<=n;i++)
		{
			int choo=0;
			for(int j=1;j<=3;j++)
			{
				if(dp[i][j-1]<dp[i-1][j]+a[i].d[j])
				{
					s[choo]--;
					a[i].bj[choo]=0;
					choo=j;
					s[choo]++;
					a[i].bj[choo]=1;
				}
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]+a[i].d[j]);
			}
		}
		/*
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<a[i].bj[j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		for(int i=1;i<=3;i++)
		{
			cout<<s[i]<<" ";
		}
		*/
		
		int ans=dp[n][3];
		if(s[1]<=maxx&&s[2]<=maxx&&s[3]<=maxx)
		{
			//cout<<"TTT";
			cout<<ans<<"\n";
		}
		else
		{
			if(s[1]>maxx)
			{
				sort(a+1,a+1+n,cmp3);
				for(int i=1;i<=n;i++)
				{
					if(s[1]<=maxx)
					{
						break;
					}
					if(a[i].bj[1]==1)
					{
						ans-=a[i].d[1];
						if(a[i].d[2]>a[i].d[3])
						{
							if(s[2]+1<=maxx)
							{
								s[1]--;
								s[2]++;
								ans+=a[i].d[2];
							}
							else
							{
								s[1]--;
								s[3]++;
								ans+=a[i].d[3];
							}
						}
						else
						{
							if(s[3]+1<=maxx)
							{
								s[1]--;
								s[3]++;
								ans+=a[i].d[3];
							}
							else
							{
								s[1]--;
								s[2]++;
								ans+=a[i].d[2];
							}
						}
						
					}
				}
			}
			if(s[2]>maxx)
			{
				sort(a+1,a+1+n,cmp4);
				for(int i=1;i<=n;i++)
				{
					if(s[2]<=maxx)
					{
						break;
					}
					if(a[i].bj[2]==1)
					{
						ans-=a[i].d[2];
						if(a[i].d[1]>a[i].d[3])
						{
							if(s[1]+1<=maxx)
							{
								s[2]--;
								s[1]++;
								ans+=a[i].d[1];
							}
							else
							{
								s[2]--;
								s[3]++;
								ans+=a[i].d[3];
							}
						}
						else
						{
							if(s[3]+1<=maxx)
							{
								s[2]--;
								s[3]++;
								ans+=a[i].d[3];
							}
							else
							{
								s[2]--;
								s[1]++;
								ans+=a[i].d[1];
							}
						}
					}
				}
			}
			if(s[3]>maxx)
			{
				
				sort(a+1,a+1+n,cmp5);
				for(int i=1;i<=n;i++)
				{
					if(s[3]<=maxx)
					{
						break;
					}
					if(a[i].bj[3]==1)
					{
						ans-=a[i].d[3];
						if(a[i].d[1]>a[i].d[2])
						{
							if(s[1]+1<=maxx)
							{
								s[3]--;
								s[1]++;
								ans+=a[i].d[1];
							}
							else
							{
								s[3]--;
								s[2]++;
								ans+=a[i].d[2];
							}
						}
						else
						{
							if(s[2]+1<=maxx)
							{
								s[3]--;
								s[2]++;
								ans+=a[i].d[2];
							}
							else
							{
								s[3]--;
								s[1]++;
								ans+=a[i].d[1];
							}
						}
						
					}
				}
			}
			cout<<ans<<"\n";
		}
		
	}
	
	return 0;
}
