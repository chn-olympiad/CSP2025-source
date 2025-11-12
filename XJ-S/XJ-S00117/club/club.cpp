#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long int x,y,z;
}a[100005];
struct node1
{
	long long int x,k;
}b[100005],c[100005],d[100005];
long long int t,s,n,k1,k2,k3,i;
bool cmp(node1 a,node1 b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		s=0; k1=0; k2=0; k3=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
			{
				b[++k1].x=a[i].x;
				b[k1].k=i;
			}
			else
			{
				if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
				{
					c[++k2].x=a[i].y;
					c[k2].k=i;
				}
				else
				{
					d[++k3].x=a[i].z;
					d[k3].k=i;
				}
			}
		}
		sort(b+1,b+k1+1,cmp);
		sort(c+1,c+k2+1,cmp);
		sort(d+1,d+k3+1,cmp);
		if(k1>n/2)
		{
			for(i=k1;i>=n/2+1;i--)
			{
				if(a[b[i].k].y>=a[b[i].k].z)
				{
					c[++k2].x=a[b[i].k].y;
				}
				else
				d[++k3].x=a[b[i].k].z;
				k1--;
			}
		}
		if(k2>n/2)
		{
			for(i=k2;i>=n/2+1;i--)
			{
				if(a[c[i].k].x>=a[c[i].k].z)
				{
					b[++k2].x=a[c[i].k].y;
				}
				else
				d[++k3].x=a[c[i].k].z;
				k2--;
			}
		}
		if(k3>n/2)
		{
			for(i=k3;i>=n/2+1;i--)
			{
				if(a[d[i].k].x>=a[d[i].k].y)
				{
					b[++k2].x=a[d[i].k].y;
				}
				else
				c[++k3].x=a[d[i].k].z;
				k3--;
			}
		}
		for(i=1;i<=k1;i++)
		s+=b[i].x;
		for(i=1;i<=k2;i++)
		s+=c[i].x;
		for(i=1;i<=k3;i++)
		s+=d[i].x;
		cout<<s<<endl<<k1<<" "<<k2<<" "<<k3<<endl;
	}
	return 0;
}
