#include<bits/stdc++.h>
using namespace std;
struct st
{
	int v;
	int id;
};
struct ts
{
	int v;
	int id;
	int fr;
};
int a[100005][3];
int b[100005][3];
int e[100005];
int f[100005];
st c[100005];
ts d[100005];
bool cmp(st x,st y)
{
	if(x.v==y.v)
	{
		return a[x.id][2]>a[y.id][2];
	}
	return x.v>y.v;
}
bool cnp(ts x,ts y)
{
	return x.v>y.v;
}
bool cmq(int x,int y)
{
	return x>y;
}
void solve(void)
{
	int n;
	cin>>n;
	int h=0;
	int x=n,y=0,z=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
		}
		h+=a[i][0];
		b[i][0]=1;
		c[i]={a[i][1]-a[i][0],i};
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int j=c[i].id;
		if(c[i].v<0||y==n/2)
		{
			d[j]={a[j][2]-a[j][0],i,0};
			continue;
		}
		h+=c[i].v;
		x--;
		y++;
		b[j][0]=0;
		b[j][1]=1;
		d[j]={a[j][2]-a[j][1],i,1};
	}
	sort(d+1,d+n+1,cnp);
	for(int i=1;i<=n;i++)
	{
		int j=d[i].id;
		f[j]=d[i].fr;
		int k=d[i].fr;
		if(d[i].v<0||z==n/2)
		{
			continue;
		}
		h+=d[i].v;
		if(d[i].fr==0)
		{
			x--;
		}
		else
		{
			y--;
		}
		z++;
		b[j][d[i].fr]=0;
		b[j][2]=1;
		f[j]=2;
	}
	if(x>n/2)
	{
		int p=x-n/2;
		for(int i=1;i<=n;i++)
		{
			int j=d[i].id;
			if(f[j]==0)
			{
				int q=0;
				if(y+1<=n/2)
				{
					y++;
					q=a[j][1];
				}
				if(z+1<=n/2&&a[j][2]>q)
				{
					y--;
					z++;
					q=a[j][2];
				}
			}
		}
		sort(e+1,e+n+1,cmq);
		for(int i=1;i<=p;i++)
		{
			h+=e[i];
		}
	}
	cout<<h<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
