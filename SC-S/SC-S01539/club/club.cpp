#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
struct Frisk
{
	int x,y,z,mx,md,mi;
	bool f;
}c[1000001];
bool Chara(Frisk n,Frisk m)
{
	if(n.mx==m.mx)
	{
		if(n.md==m.md) return n.mi>m.mi;
		return n.md>m.md;
	}
	return n.mx>m.mx;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int x=0,y=0,z=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>c[i].x>>c[i].y>>c[i].z;
			c[i].mx=max(c[i].x,max(c[i].y,c[i].z));
			c[i].md=min(max(c[i].x,c[i].y),max(c[i].x,c[i].z));
			c[i].mi=min(c[i].x,min(c[i].y,c[i].z));
			c[i].f=0;
		}
		if(n==2)
		{
			for(int i=1;i<=3;i++)
			{
				for(int j=1;j<=3;j++)
				{
					if(i==1&&j==2)
					{
						x=c[1].x+c[2].y;
						sum=max(sum,x);
					}
					else if(i==1&&j==3)
					{
						x=c[1].x+c[2].z;
						sum=max(sum,x);
					}
					else if(i==2&&j==1)
					{
						x=c[1].y+c[2].x;
						sum=max(sum,x);
					}
					else if(i==2&&j==3)
					{
						x=c[1].y+c[2].z;
						sum=max(sum,x);
					}
					else if(i==3&&j==1)
					{
						x=c[1].z+c[2].x;
						sum=max(sum,x);
					}
					else if(i==3&&j==2)
					{
						x=c[1].z+c[2].y;
						sum=max(sum,x);
					}
				}
			}
		}
		else
		{
			sort(c+1,c+n+1,Chara);
			for(int i=1;i<=n;i++)
			{
				if(c[i].mx==c[i].x&&x<n/2&&!c[i].f)
				{
					x++;
					sum+=c[i].mx;
					c[i].f=1;
				}
				else if(c[i].mx==c[i].y&&y<n/2&&!c[i].f)
				{
					y++;
					sum+=c[i].mx;
					c[i].f=1;
				}
				else if(c[i].mx==c[i].z&&z<n/2&&!c[i].f)
				{
					z++;
					sum+=c[i].mx;
					c[i].f=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(c[i].md==c[i].x&&x<n/2&&!c[i].f)
				{
					x++;
					sum+=c[i].md;
					c[i].f=1;
				}
				else if(c[i].md==c[i].y&&y<n/2&&!c[i].f)
				{
					y++;
					sum+=c[i].md;
					c[i].f=1;
				}
				else if(c[i].md==c[i].z&&z<n/2&&!c[i].f)
				{
					z++;
					sum+=c[i].md;
					c[i].f=1;
				}
			}
			for(int i=1;i<=n;i++)
			{
				if(c[i].mi==c[i].x&&x<n/2&&!c[i].f)
				{
					x++;
					sum+=c[i].mi;
					c[i].f=1;
				}
				else if(c[i].mi==c[i].y&&y<n/2&&!c[i].f)
				{
					y++;
					sum+=c[i].mi;
					c[i].f=1;
				}
				else if(c[i].mi==c[i].z&&z<n/2&&!c[i].f)
				{
					z++;
					sum+=c[i].mi;
					c[i].f=1;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}