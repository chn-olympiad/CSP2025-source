#include<bits/stdc++.h>
using namespace std;
int n,m,k,c[20],b[10100],ans=0,t=0;
struct node
{
	int x,y,z;
}a[2000010];
bool cmp(node a,node b)
{
	return a.z<b.z;
}
int f(int x)
{
	if(b[x]!=x)
	{
		return b[x]=f(b[x]);
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++)
	{
		b[i]=i;
	}
	for(int i=1;i<=m+k;i++)
	{
		if(i<=n)
		{
			int x,y,z;
			t++;
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		else
		{
			cin>>c[i-m];
			for(int j=1;j<=n;j++)
			{
				a[++t].x=i;
				a[t].y=j;
				cin>>a[t].z;
			}
		}
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1,j=n;j>1;i++)
	{
		int xx=a[i].x,yy=a[i].y,zz=a[i].z;
		yy=f(yy);
		if(xx<=n)
		{
			xx=f(xx);
			if(xx!=yy)
			{
				b[yy]=xx;
				j--;
				ans+=zz;
			}
		}
		else
		{
			if(b[xx]==xx)
			{
				if(c[xx-m]!=-1)
				{
					if(zz+(c[xx-m])/j<=a[i+1].z&&xx!=yy)
					{
						ans+=c[xx-m]+zz;
						c[xx-m]=-1;
						b[yy]=xx;
					}
				}
				else
				{
					xx=f(xx);
					if(yy!=xx)
					{
						ans+=zz;
						j--;
						b[yy]=xx;
					}
				}
			}
			else
			{
				xx=f(xx);
				if(xx!=yy)
				{
					b[yy]=xx;
					j--;
					ans+=zz;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}