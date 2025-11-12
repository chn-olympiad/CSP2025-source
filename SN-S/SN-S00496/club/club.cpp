#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
struct l
{
	int x,y,z;
}data[maxn];
bool cmp(l a,l b)
{
	if(a.x!=b.x)
	{
		return a.x>b.x;
	}
	else if(a.y!=b.y)
	{
		return a.y>b.y;
	}
	else
	{
		return a.z>b.z;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			scanf("%d%d%d",&data[j].x,&data[j].y,&data[j].z);
			
		}
		if(n==2)
		{
			printf("%d\n",max(data[1].x+max(data[2].y,data[2].z),max(data[1].y+max(data[2].x,data[2].z),data[1].z+max(data[2].x,data[2].y))));
			continue;	
		}
		else if(n==4)
		{
			int ans=0;
			for(int x=1;x<=3;x++)
			{
				for(int xx=1;xx<=3;xx++)
				{
					for(int xxx=1;xxx<=3;xxx++)
					{
						for(int xxxx=1;xxxx<=3;xxxx++)
						{
							int numa=0,numb=0,numc=0;
							if(x==1)
								numa++;
							if(xx==1)
								numa++;
							if(xxx==1)
								numa++;
							if(xxxx==1)
								numa++;
							if(x==2)
								numb++;
							if(xx==2)
								numb++;
							if(xxx==2)
								numb++;
							if(xxxx==2)
								numb++;
							if(x==3)
								numc++;
							if(xx==3)
								numc++;
							if(xxx==3)
								numc++;
							if(xxxx==3)
								numc++;
							if(max(numa,max(numb,numc))<=n/2)
							{
								int sans=0;
								if(x==1)
									sans+=data[1].x;
								else if(x==2)
									sans+=data[1].y;
								else
									sans+=data[1].z;
								if(xx==1)
									sans+=data[2].x;
								else if(xx==2)
									sans+=data[2].y;
								else
									sans+=data[2].z;
								if(xxx==1)
									sans+=data[3].x;
								else if(xxx==2)
									sans+=data[3].y;
								else
									sans+=data[3].z;
								if(xxxx==1)
									sans+=data[4].x;
								else if(xxxx==2)
									sans+=data[4].y;
								else
									sans+=data[4].z;
									//cout<<sans<<endl;
								ans=max(ans,sans);
							}
						}
					}
				}
			}
			printf("%d\n",ans);
			continue;
		}
		sort(data+1,data+n+1,cmp);
		int ans=0,ca=0,cb=0,cc=0;
		for(int j=1;j<=n;j++)
		{
			if((cb>=n/2 && cc>=n/2 || data[j].x>data[j].y && data[j].x>data[j].z) && ca<n/2)
			{
				ca++;
				ans+=data[j].x;
			}
			else if((cc>=n/2 || data[j].y>data[j].x && data[j].y>data[j].z) && cb<n/2)
			{
				cb++;
				ans+=data[j].y;
			}
			else
			{
				cc++;
				ans+=data[j].z;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
