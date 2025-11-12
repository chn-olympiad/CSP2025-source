#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
	int x,y,z,c;
}a[100010];
bool cmp(node a,node b)
{
	return a.c>b.c;
}
void s()
{
	cin>>n;
	int b1=0,b2=0,b3=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].c=max(a[i].x,max(a[i].y,a[i].z))-min(a[i].x,min(a[i].y,a[i].z));
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int xx=a[i].x,yy=a[i].y,zz=a[i].z;
		if(xx>=yy&&xx>=zz&&b1<n/2)
		{
			b1++;
			ans+=xx;
		}
		else
		{
			if(yy>=zz&&b2<n/2)
			{
				b2++;
				ans+=yy;
			}
			else
			{
				if(b3<n/2)
				{
					b3++;
					ans+=zz;
				}
				else
				{
					if(xx>=yy&&b1<n/2)
					{
						b1++;
						ans+=xx;
					}
					else
					{
						if(b2<n/2)
						{
							b1++;
							ans+=xx;
						}
						else
						{
							b2++;
							ans+=yy;
						}
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s();
	}
	return 0;
}