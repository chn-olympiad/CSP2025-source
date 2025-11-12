#include<bits/stdc++.h>
using namespace std;	
int t,n,hgdm=0,ma1=0,ma2=0,ma3=0,x,j;
struct hgd
{
	int a1;
	int a2;
	int a3;
}a[100001];
int zzz(int a11,int b,int c)
{
	if(a11>=b&&a11>=c) return a11;
	if(b>=a11&&b>=c) return b;
	else return c;
}
int pp()
{
	if(x=a[j].a1)
	{
		ma1++;
		if(ma1>n/2)
		{
			a[j].a1=0;
			return 0;
		}
	}
	else if(x=a[j].a2)
	{
		ma2++;
		if(ma2>n/2)
		{
			a[j].a2=0;
			return 0;
		}
	}
	else if(x=a[j].a3)
	{
		ma3++;
		if(ma3>n/2)
		{
			a[j].a3=0;
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("club.in"，"r",stdin);
	freopen("club.out","w",stdout);

	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>a[j].a1>>a[j].a2>>a[j].a3;
			x=zzz(a[j].a1,a[j].a2,a[j].a3);
			while(pp()==0)
			{
				x=zzz(a[j].a1,a[j].a2,a[j].a3);
			}
			hgdm=hgdm+x;
		}
		cout<<hgdm<<endl;
	}
	return 0;
} 