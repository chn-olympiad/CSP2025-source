#include<bits/stdc++.h>
using namespace std;
struct st
{
	long long int d1,d2,d3;
}r[1000005];
long long int t,n,m1,m2,m3,sum,s1,s2,s3,r1,r2,r3,f;
bool cmp(st a,st b)
{
	if(a.d1>b.d1)
	return a.d1>b.d1;
	else
	if(a.d1==b.d1)
	return a.d2>b.d2;
	else
	if(a.d2==b.d2)
	return a.d3>b.d3;
	
}
int fun1(long long int m)
{
	long long int i,k,s=0,t=0;
	for(i=m+1;i<=n;)
	{
		if(r[i].d2<r[i].d3)
		return 0;
		if(r[i].d3<r[i].d2)
		return 1;
		if(r[i].d2==r[i].d3)
		i--;
	}
	return 2;
}
int fun2(long long int m)
{
	long long int i,k,s=0,t=0;
	for(i=m+1;i<=n;)
	{
		if(r[i].d1<r[i].d3)
		return 0;
		if(r[i].d3<r[i].d1)
		return 1;
		if(r[i].d1==r[i].d3)
		i++;
    }

	return 2;
}
int fun3(long long int m)
{
	long long int i,k,s=0,t=0;
	for(i=m+1;i<=n;)
	{
		if(r[i].d1<r[i].d2)
		return 0;
		if(r[i].d2<r[i].d1)
		return 1;
		if(r[i].d1==r[i].d2)
		i--;
	}
	return 2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int i,k;
	cin>>t;
	while(t--)
	{
		s1=0;
		s2=0;
		s3=0;
		r1=0;
		r2=0;
		r3=0;
		f=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>m1>>m2>>m3;
			r[i]={m1,m2,m3};
		}
		
		sort(r+1,r+1+n,cmp);
		
		for(i=1;i<=n;i++)
		{
			if(r[i].d1>r[i].d2&&r[i].d1>r[i].d3)
			{
				if(r1<n/2)
				{
					r1++;
					s1+=r[i].d1;
				}
				else
				{
					if(r[i].d2>r[i].d3)
					{
						if(r2<n/2)
						{
							s2+=r[i].d2;
							r2++;
						}
						else
						{
							r3++;
							s3+=r[i].d3;
						}
					}
					if(r[i].d3>r[i].d2)
					{
						if(r3<n/2)
						{
							s3+=r[i].d3;
							r3++;
						}
						else
						{
							s2+=r[i].d2;
							r2++;
						}
						
					}
					if(r[i].d2==r[i].d3)
					{
						f=fun1(i);
						if(f==1)
						{
							s2+=r[i].d2;
							r2++;
						}
						if(f==0)
						{
							s3+=r[i].d3;
							r3++;
						}
						if(f==2)
						{
							if(r2>r3)
							{
							    r2++;
								s2+=r[i].d2;
							}
							else
							{
								s3+=r[i].d3;
							    r3++;
							}
						}
					}
				}
			}
			
			if(r[i].d2>r[i].d3&&r[i].d2>r[i].d1)
			{
				if(r2<n/2)
				{
					r2++;
					s2+=r[i].d2;
				} 
				else
				{
					if(r[i].d1>r[i].d3)
					{
						if(r1<n/2)
						{
							s1+=r[i].d1;
							r1++;
						}
						else
						{
							r3++;
							s3+=r[i].d3;
						}
					}
					if(r[i].d3>r[i].d1)
					{
						if(r3<n/2)
						{
							r3++;
							s3+=r[i].d3;
						}
						else
						{
							r1++;
							s1+=r[i].d1;
						}
					}
					if(r[i].d1==r[i].d3)
					{
						f=fun2(i);
						if(f==1)
						{
							r1++;
							s1+=r[i].d1;
						}
						if(f==0)
						{
							r3++;
							s3+=r[i].d3;
						}
						if(f==2)
						{
							if(r1>r3)
							{
								r3++;
							    s3+=r[i].d3;
							}
							else
							{
								r1++;
							    s1+=r[i].d1;
							}
						}
					}
				}
			}
			
			if(r[i].d3>r[i].d1&&r[i].d3>r[i].d2)
			{
				if(r3<n/2)
				{
					r3++;
					s3+=r[i].d3;
				}
				else
				{
					if(r[i].d1>r[i].d2)
					{
						if(r1<n/2)
						{
						    r1++;
							s1+=r[i].d1;	
						}
						else
						{
							r2++;
							s2+=r[i].d2;
						}
					}
					if(r[i].d1<r[i].d2)
					{
						if(r2<n/2)
						{
						    r2++;
							s2+=r[i].d2;	
						}
						else
						{
							r1++;
							s1+=r[i].d1;
						}
					}
					if(r[i].d1==r[i].d2)
					{
						f=fun3(i);
						if(f==0)
						{
							r2++;
							s2+=r[i].d2;
						}
						if(f==1)
						{
							r1++;
							s1+=r[i].d1;
						}
						if(f==2)
						{
							if(r1>r2)
							{
								r2++;
							    s2+=r[i].d2;
							}
							else
							{
								r1++;
							    s1+=r[i].d1;
							}
						}
					}
				}
			} 
		}
		cout<<s1+s2+s3<<endl;
	}
	return 0;
}
