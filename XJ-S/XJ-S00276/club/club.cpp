#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
long long t;
long long n;
long long maxpeople; 
long long ans;
long long apeople,bpeople,cpeople;//各部门人数
long long amydmax=0,bmydmax=0,cmydmax=0;
long long tans[MAXN]; 
struct
{
	long long people[MAXN];//成员
	long long bumenga[MAXN];
	long long bumengb[MAXN];
	long long bumengc[MAXN];
}manyidu;//满意度 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int sum=0;
	for(int k=1;k<=t;k++)
	{
 		cin>>n;
		maxpeople=n/2;//部门人数上限 
		ans=0;
		for(int i=1;i<=MAXN;i++)
		{
			manyidu.bumenga[i]=0;
			manyidu.bumengb[i]=0;
			manyidu.bumengc[i]=0;
			manyidu.people[i]=0;
		}//清零上一次满意度 
		for(int i=1;i<=n;i++)
		{
			cin>>manyidu.bumenga[i]>>manyidu.bumengb[i]>>manyidu.bumengc[i];
			manyidu.people[i]=1;
		}//输入各个部门满意度 
		apeople=0;
		bpeople=0;
		cpeople=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(manyidu.bumenga[i]>manyidu.bumengb[i]&&manyidu.bumenga[i]>manyidu.bumengc[i]&&manyidu.people[i]==1)
				{
					for(int j=1;j<=n;j++)
			{
					if(manyidu.bumenga[i]>=manyidu.bumenga[j]&&manyidu.bumenga[j]>manyidu.bumengb[j]&&manyidu.bumenga[j]>manyidu.bumengc[j]&&manyidu.people[j]==1&&apeople<maxpeople)
					{
						ans+=manyidu.bumenga[i];
						
						manyidu.people[i]=-1;
						apeople++;
					}
				}
					
				}
				else if(manyidu.bumengb[i]>manyidu.bumenga[i]&&manyidu.bumengb[i]>manyidu.bumengc[i]&&manyidu.people[i]==1)
				{
					for(int j=1;j<=n;j++)
			{
					if(manyidu.bumengb[i]>=manyidu.bumengb[j]&&manyidu.bumengb[j]>manyidu.bumenga[j]&&manyidu.bumengb[j]>manyidu.bumengc[j]&&bpeople<maxpeople&&manyidu.people[j]==1)
					{	
						ans+=manyidu.bumengb[i];						
						manyidu.people[i]=-1;
						bpeople++;
						
					}
				}
					
				}
				else if(manyidu.bumengc[i]>manyidu.bumenga[i]&&manyidu.bumengc[i]>manyidu.bumengb[i]&&manyidu.people[i]==1)
				{
					for(int j=1;j<=n;j++)
			{
					if(manyidu.bumengc[i]>=manyidu.bumengc[j]&&manyidu.bumengc[j]>manyidu.bumenga[j]&&manyidu.bumengc[j]>manyidu.bumengb[j]&&cpeople<maxpeople&&manyidu.people[j]==1)
					{
						ans+=manyidu.bumengc[i];
						
						manyidu.people[i]=-1;
						cpeople++;
					}
				}
				
				}
			}	
		}
		sum++;
		tans[sum]=ans;
	}
	for(int i=1;i<=sum;i++)
	{
		cout<<tans[i]<<endl;
	}
	return 0;
}
