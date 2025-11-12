#include<bits/stdc++.h>
using namespace std;
int p,n,cnt,mmax,xx,yy,zz;
struct node{
	int x,y,z;
}a[10];
void f(int x,int y)
{
	if(y==1)
	{
		cnt+=a[x].x;
		xx++;
	}
	else if(y==2)
	{
		cnt+=a[x].y;
		yy++;
	}
	else
	{
		cnt+=a[x].z;
		zz++;
	}
	if(x==n)
	{
		mmax=max(mmax,cnt);
		return;
	}
	for(int i=1;i<=3;i++)
	{
		f(x+1,i);
		if(i==1&&xx<n/2)
	{
		f(x+1,i);
		cnt-=a[x+1].x;
		xx--;
	}
	else if(i==2&&yy<n/2)
	{
		f(x+1,i);
		cnt-=a[x+1].y;
		yy--;
	}
	else if(i==3&&zz<n/2)
	{
		f(x+1,i);
		cnt-=a[x+1].z;
		zz--;
	}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>p;
	while(p--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n==2)
		{
			int c=a[1].x+max(a[2].y,a[2].z);
			int cc=a[1].y+max(a[2].x,a[2].z);
			int ccc=a[1].z+max(a[2].x,a[2].y);
			cout<<max(c,max(cc,ccc))<<endl;
			continue;
		}
		for(int i=1;i<=3;i++)
		{
		 	f(1,i);
		}
		cout<<mmax<<endl;
		mmax=0;
	}
	return 0;
} 