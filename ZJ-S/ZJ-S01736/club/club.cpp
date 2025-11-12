#include<bits/stdc++.h>
using namespace std;
int t,n,i,x,y,z,f[5],sum;
struct student
{
	int x,y,id1,id2;
	friend bool operator<(student x,student y)
	{
		if(abs(x.x-x.y)<abs(y.x-y.y))
		  return true;
		return false;
	}
}a[100001];
int getint()
{
	int sum=0;
	char a=getchar();
	while(a<48||a>57)
	  a=getchar();
	while(a>=48&&a<=57)
	{
		sum=sum*10+a-48;
		a=getchar();
	}
	return sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=getint();
	while(t--)
	{
		sum=f[1]=f[2]=f[3]=0;
		n=getint();
		for(i=1;i<=n;i++)
		{
			x=getint();
			y=getint();
			z=getint();
			a[i].x=max(x,max(y,z));
			if(x>=y&&x>=z)
			  a[i].id1=1;
			else
			  if(y>=x&&y>=z)
			    a[i].id1=2;
			  else
			    a[i].id1=3;
			if(a[i].id1==1)
			{
				a[i].y=max(y,z);
				if(y>=z)
				  a[i].id2=2;
				else
				  a[i].id2=3;
			}
			if(a[i].id1==2)
			{
				a[i].y=max(x,z);
				if(x>=z)
				  a[i].id2=1;
				else
				  a[i].id2=3;
			}
			if(a[i].id1==3)
			{
				a[i].y=max(x,y);
				if(x>=y)
				  a[i].id2=1;
				else
				  a[i].id2=2;
			}
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		   sum+=a[i].x;
		for(i=1;i<=n;i++)
		   f[a[i].id1]++;
		for(i=1;f[1]>n/2;i++)
		   if(a[i].id1==1)
		   {
		   	sum+=a[i].y-a[i].x;
		   	f[1]--;
		   }
		for(i=1;f[2]>n/2;i++)
		   if(a[i].id1==2)
		   {
		   	sum+=a[i].y-a[i].x;
		   	f[2]--;
		   }
		for(i=1;f[3]>n/2;i++)
		   if(a[i].id1==3)
		   {
		   	sum+=a[i].y-a[i].x;
		   	f[3]--;
		   }
		cout<<sum<<endl;
	}
	return 0;
}
