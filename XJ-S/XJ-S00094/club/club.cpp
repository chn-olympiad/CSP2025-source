#include<bits/stdc++.h>
using namespace std;
struct node1
{
	int c1,c2,c3,maxc,secc;
}a[100005];
struct node2
{
	int maxc,ms,s,zz,xx,yy;
}b[100005];
bool cmp0(node1 x,node1 y)
{
	return x.maxc>y.maxc;
}
bool cmp1(node2 x,node2 y)
{
	return x.ms<y.ms;
}
bool cmp2(node2 x,node2 y)
{
	return x.s<y.s;
}
int bsecc[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,x=0,y=0,z=0,ans=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].c1>>a[i].c2>>a[i].c3;
			if(a[i].c2!=0||a[i].c3!=0)c=1;
			a[i].maxc=max(a[i].c1,max(a[i].c2,a[i].c3));
			if(a[i].maxc==a[i].c1)
			{
				x++;
				b[x].xx=i;
				b[i].maxc=1;
				a[i].secc=max(a[i].c2,a[i].c3);
				bsecc[i]=(a[i].c2>a[i].c3?2:3);
				b[i].s=a[i].secc-min(a[i].c2,a[i].c3);
			}
			else if(a[i].maxc==a[i].c2)
			{
				y++;
				b[y].yy=i;
				b[i].maxc=2;
				a[i].secc=max(a[i].c1,a[i].c3);
				bsecc[i]=(a[i].c1>a[i].c3?1:3);
				b[i].s=a[i].secc-min(a[i].c1,a[i].c3);
			}
			else if(a[i].maxc==a[i].c3)
			{
				z++;
				b[z].zz=i;
				b[i].maxc=3;
				a[i].secc=max(a[i].c2,a[i].c1);
				bsecc[i]=(a[i].c2>a[i].c1?2:1);
				b[i].s=a[i].secc-min(a[i].c2,a[i].c1);
			}
			b[i].ms=a[i].maxc-a[i].secc;
			ans+=a[i].maxc;
		}
		if(c==0)
		{
			sort(a+1,a+n+1,cmp0);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[i].maxc;
			}
		}
		if(c==1)
		{
			if(x<=n/2&&y<=n/2&&z<=n/2)
			{
				cout<<ans<<'\n';
			}
			else
			{
				sort(b+1,b+n+1,cmp1);
				if(x>n/2&&x>=y&&x>=z)
				{
					int i=1,j=1;
					while(j<=x-n/2)
					{
						if(b[i].maxc==1)
						{
							j++;
							ans-=b[i].ms;
							if(bsecc[i]==2)y++;
							else z++;
						}
						i++;
					}
					if(y>n/2||z>n/2)	sort(b+1,b+n+1,cmp2);
					if(y>n/2)
					{
						int i=1;j=1; 
						while(j<=y-n/2)
						{
							if(b[i].maxc==2)
							{
								j++;
								ans-=b[i].s;
								z++;
							}
							i++;
						}
					}
					else if(z>n/2)
					{
						int i=1;j=1; 
						while(j<=z-n/2)
						{
							if(b[i].maxc==3)
							{
								j++;
								ans-=b[i].s;
								y++;
							}
							i++;
						}
					}
				}
				else if(y>n/2&&y>=z&&y>=x)
				{
					int i=1,j=1;
					while(j<=y-n/2)
					{
						if(b[i].maxc==2)
						{
							j++;
							ans-=b[i].ms;
							if(bsecc[i]==3)z++;
							else x++;
						}
						i++;
					}
					if(x>n/2||z>n/2)	sort(b+1,b+n+1,cmp2);
					if(z>n/2)
					{
						int i=1;j=1; 
						while(j<=z-n/2)
						{
							if(b[i].maxc==3)
							{
								j++;
								ans-=b[i].s;
								x++;
							}
							i++;
						}
					}
					else if(x>n/2)
					{
						int i=1;j=1; 
						while(j<=x-n/2)
						{
							if(b[i].maxc==1)
							{
								j++;
								ans-=b[i].s;
								z++;
							}
							i++;
						}
					}
				}
				else if(z>n/2&&z>=y&&z>=x)
				{
					int i=1,j=1;
					while(j<=z-n/2)
					{
						if(b[i].maxc==3)
						{
							j++;
							ans-=b[i].ms;
							if(bsecc[i]==2)y++;
							else x++;
						}
						i++;
					}
					if(y>n/2||x>n/2)	sort(b+1,b+n+1,cmp2);
					if(y>n/2)
					{
						int i=1;j=1; 
						while(j<=y-n/2)
						{
							if(b[i].maxc==2)
							{
								j++;
								ans-=b[i].s;
								x++;
							}
							i++;
						}
					}
					if(x>n/2)
					{
						int i=1;j=1; 
						while(j<=x-n/2)
						{
							if(b[i].maxc==1)
							{
								j++;
								ans-=b[i].s;
								y++;
							}
							i++;
						}
					}
				}
				cout<<ans<<'\n';
			}
			ans=0;
		}
	}
	return 0;
}
