#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;
int n,t;
int a[100005][5],m[5][100005],s1,s2,s3,ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(m,0,sizeof(m));
		cin>>n;
		ans=0,s1=0,s2=0,s3=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ma=0;
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				ma=a[i][1];
				m[i][1]=1;
				s1++;
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
			{
				ma=a[i][2];
				m[i][2]=1;
				s2++;
			}
			else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1])
			{
				ma=a[i][3];
				m[i][3]=1;
				s3++;
			}
			ans+=ma;
		}
		if(s1<=(n/2)&&s2<=(n/2)&&s3<=(n/2))
		{
			cout<<ans<<endl;
		}
		else
		{
			while(s1>(n/2))
			{
				if(s2<(n/2)&&s3<(n/2))
				{
					int b=1e9,id=0,bm=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][2]==0&&m[i][1]==1&&m[i][2]-m[i][1]<b)
						{
							b=m[i][2]-m[i][1];
							id=i,bm=2;
						}
						if(m[i][3]==0&&m[i][1]==1&&m[i][3]-m[i][1]<b)
						{
							b=m[i][3]-m[i][1];
							id=i,bm=3;
						}
					}
					if(bm==2) s2++,m[id][2]=1;
					if(bm==3) s3++,m[id][3]=1;
					ans+=b;
					s1--;
					m[id][1]=0;
				}
				else if(s2<(n/2)&&s3>=(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][2]==0&&m[i][1]==1&&m[i][2]-m[i][1]<b)
						{
							b=m[i][2]-m[i][1];
							id=i;
						}
					}
					ans+=b;
					s1--;
					s2++;
					m[id][1]=0;
					m[id][2]=1;
				}
				else if(s2>=(n/2)&&s3<(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][3]==0&&m[i][1]==1&&m[i][3]-m[i][1]<b)
						{
							b=m[i][3]-m[i][1];
							id=i;
						}
					}
					ans+=b;
					s1--;
					s3++;
					m[id][1]=0;
					m[id][3]=1;
				}
			}
			while(s2>(n/2))
			{
				if(s1<(n/2)&&s3<(n/2))
				{
					int b=1e9,id=0,bm=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][1]==0&&m[i][2]==1&&m[i][1]-m[i][2]<b)
						{
							b=m[i][1]-m[i][2];
							id=i,bm=1;
						}
						if(m[i][3]==0&&m[i][2]==1&&m[i][3]-m[i][2]<b)
						{
							b=m[i][3]-m[i][2];
							id=i,bm=3;
						}
					}
					if(bm==1) s1++,m[id][1]=1;
					if(bm==3) s3++,m[id][3]=1;
					ans+=b;
					s2--;
					m[id][2]=0;
				}
				else if(s1<(n/2)&&s3>=(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][1]==0&&m[i][2]==1&&m[i][1]-m[i][2]<b)
						{
							b=m[i][1]-m[i][2];
							id=i;
						}
					}
					ans+=b;
					s2--;
					s1++;
					m[id][2]=0;
					m[id][1]=1;
				}
				else if(s1>=(n/2)&&s3<(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][3]==0&&m[i][2]==1&&m[i][3]-m[i][2]<b)
						{
							b=m[i][3]-m[i][2];
							id=i;
						}
					}
					ans+=b;
					s2--;
					s3++;
					m[id][2]=0;
					m[id][3]=1;
				}
			}
			while(s3>(n/2))
			{
				if(s2<(n/2)&&s1<(n/2))
				{
					int b=1e9,id=0,bm=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][2]==0&&m[i][3]==1&&m[i][2]-m[i][3]<b)
						{
							b=m[i][2]-m[i][3];
							id=i,bm=2;
						}
						if(m[i][1]==0&&m[i][3]==1&&m[i][1]-m[i][3]<b)
						{
							b=m[i][1]-m[i][3];
							id=i,bm=1;
						}
					}
					if(bm==2) s2++,m[id][2]=1;
					if(bm==1) s1++,m[id][1]=1;
					ans+=b;
					s3--;
					m[id][3]=0;
				}
				else if(s2<(n/2)&&s1>=(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][2]==0&&m[i][3]==1&&m[i][2]-m[i][3]<b)
						{
							b=m[i][2]-m[i][3];
							id=i;
						}
					}
					ans+=b;
					s3--;
					s2++;
					m[id][3]=0;
					m[id][2]=1;
				}
				else if(s2>=(n/2)&&s1<(n/2))
				{
					int b=1e9,id=0;
					for(int i=1;i<=n;i++)
					{
						if(m[i][1]==0&&m[i][3]==1&&m[i][1]-m[i][3]<b)
						{
							b=m[i][1]-m[i][3];
							id=i;
						}
					}
					ans+=b;
					s3--;
					s1++;
					m[id][3]=0;
					m[id][1]=1;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
