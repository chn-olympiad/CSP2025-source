#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

const int N=100010;
int x1=0,x2=0,x3=0;
int m1=0,m2=0,m3=0;
int n,t,a1[N],a2[N],a3[N];
int v[N];
int t1=0,t2=0,t3=0;


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(a3,0,sizeof(a3));
		memset(v,0,sizeof(v));
		x1=0;x2=0;x3=0;
		m1=0;m2=0;m3=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]) 
			{
				x1++;
				v[i]=1;
				m1+=a1[i];
			}else 
			if(a2[i]>=a1[i]&&a2[i]>=a3[i])
			{
				x2++;
				v[i]=2;
				m2+=a2[i];
			 } 
			else
			{
				x3++;
				v[i]=3;
				m3+=a3[i];
			 } 
		} 
		int sum=m1+m2+m3;
		if(x1>n/2)
		{
			while(x1>n/2)
			{
				int t1=0x3f3f3f3f,t2;
				for(int j=1;j<=n;j++)
				{
					if(v[j]==1&&(a1[j]-a2[j]<t1||a1[j]-a3[j]<t1))
					{
						v[j]=4;
						if(a1[j]-a2[j]>a1[j]-a3[j])
						{
					    	t2=j;
							t1=a1[j]-a3[j];
						}
						else
						{
							t2=j;
							t1=a1[j]-a2[j];
						}
					 }	
				}
				sum=sum-t1;
				x1--;
			}
		}
		else if(x2>n/2)
		{
			while(x2>n/2)
			{
				int t1=0x3f3f3f3f,t2;
				for(int j=1;j<=n;j++)
				{
					if(v[j]==2&&(a2[j]-a1[j]<t1||a2[j]-a3[j]<t1))
					{
						v[j]=4;
						if(a2[j]-a1[j]>a2[j]-a3[j])
						{
					    	t2=j;
							t1=a2[j]-a3[j];
						}
						else
						{
							t2=j;
							t1=a2[j]-a1[j];
						}
					 }	
				}
				sum=sum-t1;
				x2--;
			}
		}
		else if(x3>n/2)
		{
		while(x3>n/2)
			{
				int t1=0x3f3f3f3f,t2;
				for(int j=1;j<=n;j++)
				{
					if(v[j]==3&&(a3[j]-a1[j]<t1||a3[j]-a2[j]<t1))
					{
						if(a3[j]-a1[j]>a3[j]-a2[j])
						{
					    	t2=j;
							t1=a3[j]-a2[j];
						}
						else
						{
							t2=j;
							t1=a3[j]-a1[j];
						}
					 }	
				}
				v[t2]=4;
				sum=sum-t1;
				x3--;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
 } 
 /*
 1
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

147325
 */
