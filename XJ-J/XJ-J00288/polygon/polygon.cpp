#include<bits/stdc++.h>
using namespace std;
int m=0,y=0,l=0;
bool na (int p,int e[5010],int k,int d)
{
	if(k-m>=4)
	{
		for(int i=1;i<=k-m;i++)
		{
			if(e[i]!=0)
			{
				if(e[i]!=d)
				{
					if(p-e[i]>d*2)
					{
						p-=e[i];
						e[i]=0;	
						y++;
						m++;
						na(p,e,k,d);
					}
				}
				else
				{
					d=e[i-1];
					if(p-e[i]>d*2)
					{
						p-=e[i];
						e[i]=0;
						y++;
						m++;
						na(p,e,k,d);
					}
				}
			}
		}
	}
	else
	{
		return 0;
	}
	l+=y;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5010],h,z=-1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h+=a[i];
		if(z<a[i])
		{
			z=a[i];
		}
	}
	sort(a+1,a+n+1);
	na(h,a,n,z);
	if(h>z*2)
	{
		l++;
	}
	cout<<l;
	return 0;
}
