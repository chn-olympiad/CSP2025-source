#include<bits/stdc++.h>
using namespace std;
struct node
{
	int shu,b;
}a[100005][5];
struct node1
{
	int c1,c2,b1,b2,b3,ii;
}c[100005];
struct node2
{
	int shu,b,c;
}d[100005];
bool cmp1(node a,node b)
{
	return a.shu>=b.shu;
}
bool cmp2(node1 a,node1 b)
{
	return a.c1>=b.c1;
}
bool cmp3(node1 a,node1 b)
{
	return a.c2>=b.c2;
}
bool cmp4(node2 a,node2 b)
{
	return a.shu>b.shu ;
}
long long int t,n,i,j,x,y,z,ans,flag[100005],k,flag1;
int sgs(int a,int b,int c)
{
	long long int m=max(a,b);
	if(a==b)
	return a;
	if(m==a)
	return min(b,c);
	if(m==b)
	return min(a,c);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(d,100005,sizeof(d));
		flag1=0;
		memset(c,100005,sizeof(c));
		memset(flag,100005,sizeof(flag));
		ans=0;x=0;y=0;z=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i][1].shu>>a[i][2].shu>>a[i][3].shu;
			a[i][1].b=1;a[i][2].b=2;a[i][3].b=3;
			sort(a[i]+1,a[i]+1+2,cmp1);
		}
		for(i=1;i<=n;i++)
		{
			if(a[i][3].shu!=0)
			flag1=1;
		}
		if(flag1==0)
		{
			for(i=1;i<=n;i++)
			{
				d[i].shu=max(a[i][2].shu,a[i][1].shu)-min(a[i][2].shu,a[i][1].shu);
				if(a[i][2].shu>a[i][1].shu)
				{
					d[i].b=2;
				d[i].c=a[i][2].shu;
				}
				
				else
				{
					d[i].b=1;
				d[i].c=a[i][1].shu;
				}
				
			}
			sort(d+1,d+1+n,cmp4);
			for(i=1;i<=n;i++)
			{
				if(d[i].b==1&&x<n/2)
				{
					x++;
					ans+=d[i].c;
				}
				else
				if(y<n/2)
				{
					y++;
					ans+=d[i].c;
				}
				else
				if(d[i].b<2)
				{
					x++;
					ans+=d[i].c;
				}
			}
			cout<<ans;
			continue;
		}
		for(i=1;i<=n;i++)
		{
			c[i].c1=a[i][1].shu-a[i][2].shu;
			c[i].c2=a[i][2].shu-a[i][3].shu;
			c[i].b1=a[i][1].b;
			c[i].b2=a[i][2].b;
			c[i].b3=a[i][3].b;
			c[i].ii=i;
		}
		sort(c+1,c+1+n,cmp2);
		for(i=1;i<=n;i++)
		{
			if(c[i].b1==1)
			{
				if(x<n/2)
				{
					ans+=a[c[i].ii][1].shu;
					x++;
				}
				else
				flag[i]=1;
			}
			if(c[i].b1==2)
			{
				if(y<n/2)
				{
					y++;
					ans+=a[c[i].ii][1].shu;
				}
				else
				flag[i]=1;
			}
			if(c[i].b1==3)
			{
				if(z<n/2)
				{
					ans+=a[c[i].ii][1].shu;
					z++;
				}
				else
				flag[i]=1;
			}
		}
		for(i=1;i<=n;i++)
		if(flag[c[i].ii]!=1)
		{
			c[i].c1=c[i+1].c1;
			c[i].c2=c[i+1].c2;
			c[i].b1=c[i+1].b1;
			c[i].b3=c[i+1].b3;
			c[i].b2=c[i+1].b2;
			c[i].ii=c[i+1].ii;
			i-=1;
		}
		sort(c+1,c+1+k,cmp3);
		long long int flag[100005];
		for(i=1;i<=n;i++)
		{
			if(c[i].b2==1)
			{
				if(x<n/2)
				{
					ans+=a[c[i].ii][2].shu;
					x++;
				}
				else
				flag[i]=1;
			}
			if(c[i].b2==2)
			{
				if(y<n/2)
				{
					y++;
					ans+=a[c[i].ii][2].shu;
				}
				else
				flag[i]=1;
			}
			if(c[i].b2==3)
			{
				if(z<n/2)
				{
					ans+=a[c[i].ii][2].shu;
					z++;
				}
				else
				flag[i]=1;
			}
		}
		for(i=1;i<=n;i++)
		if(flag[c[i].ii]!=1)
		{
			ans+=a[c[i].ii][3].shu;
		}
	}
	cout<<ans;
	
	return 0;
 } 
