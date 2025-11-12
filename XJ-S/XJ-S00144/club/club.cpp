#include<iostream>
using namespace std;
int n,t,i,j,k,a[100005],b[100005],c[100005],z,l=1;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(z=1;z<=t;z++)
	{
		cin>>n;
		if(n==2)
		{
			int a1,a2,a3,b1,b2,b3,aa;
			cin>>a1>>a2>>a3;
			cin>>b1>>b2>>b3;
			aa=0;
			if((a1+b2)>aa)
			{
				aa=a1+b2;
			}
			if((a1+b3)>aa)
			{
				aa=a1+b3;
			}
			if((a2+b1)>aa)
			{
				aa=a2+b1;
			}
			
			if((a2+b3)>aa)
			{
				aa=a2+b3;
			}
			if((a3+b1)>aa)
			{
				aa=a3+b1;
			}
			if((a3+b2)>aa)
			{
				aa=a3+b2;
			}
			
			if(z!=t)
			{
				cout<<aa<<endl;
				return 0;
			}
			else
			{
				cout<<aa;
				return 0;
			}
		}
		for(i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(a[i]<a[j])
				{
					int w;
					w=a[i];a[i]=a[j];a[j]=w;
				}
			}
		}
		int ans=0;
		for(i=1;i<=(n/2);i++)
		{
			ans+=a[i];
		}
		if(z!=t)
			{
				cout<<ans<<endl;
				return 0;
			}
			else
			{
				cout<<ans;
				return 0;
			}
	}
	return 0;	
} 
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
