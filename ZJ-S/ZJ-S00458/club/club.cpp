#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node
{
	int tx,ty,tz,pai1,pai2,pai3,visit;
}a[100001];
int cmp1(node x,node y)
{
	return x.tx>y.tx;
}
int cmp2(node x,node y)
{
	return x.ty>y.ty;
}
int cmp3(node x,node y)
{
	return x.tz>y.tz;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++) 
	{
		cin>>n;
		int zb=n/2,ti1=0,ti2=0,ti3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].tx>>a[i].ty>>a[i].tz,a[i].visit=0;
			
			if(a[i].tx>=a[i].ty&&a[i].tx>=a[i].tz)
			{
				a[i].pai1=1;
				if(a[i].ty>=a[i].tz) a[i].pai2=2,a[i].pai3=3;
				else a[i].pai2=3,a[i].pai3=2;
			}
			if(a[i].ty>=a[i].tx&&a[i].ty>=a[i].tz)
			{
				a[i].pai1=2;
				if(a[i].tx>=a[i].tz) a[i].pai2=1,a[i].pai3=3;
				else a[i].pai2=3,a[i].pai3=1;
			}
			if(a[i].tz>=a[i].ty&&a[i].tz>=a[i].tx)
			{
				a[i].pai1=3;
				if(a[i].ty>=a[i].tx) a[i].pai2=2,a[i].pai3=1;
				else a[i].pai2=1,a[i].pai3=2;
			}
		}
		
		sort (a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++)
		{
			if(ti1<zb)
			{
				if(a[i].pai1==1)
				{
					ans+=a[i].tx;
					ti1++;
					a[i].visit=1;
				} 
			}
		}
		
		
		sort (a+1,a+1+n,cmp2);
		for (int i=1;i<=n;i++)
		{
			if(ti2<zb)
			{
				if(a[i].visit==0&&a[i].pai3!=2)
				{
					ans+=a[i].ty;
					ti2++;
					a[i].visit=1;
				}
			}
		}
		
		
		sort (a+1,a+1+n,cmp3);
		for (int i=1;i<=n;i++)
		{
			if(ti3<zb)
			{
				if(a[i].visit==0)
				{
					ans+=a[i].tz;
					ti3++;
				}
			}
		}
		
		cout<<ans;
	}
	return 0;
	//Ren5Jie4Di4Ling5%
}
