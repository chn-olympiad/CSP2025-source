#include <bits/stdc++.h> 
using namespace std;
struct s
{
	int a,b,c,d;
}a[100005];
bool cmp(s x,s y)
{
	return x.a+x.b+x.c>y.a+y.b+y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,suma=0,sumb=0,sumc=0,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		suma=n/2-1,sumb=n/2-1,sumc=n/2-1;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].d=a[i].a+a[i].b+a[i].c;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int x=max(max(a[i].a,a[i].b),a[i].c),z=min((a[i].a,a[i].b),a[i].c),y=a[i].d-x-z;
			if(a[i].a==x&&suma!=0)
			{
				ans+=x;
				suma--;
			}
			else if(a[i].b==x&&sumb!=0)
			{
				ans+=x;
				sumb--;
			}
			else if(a[i].c==x&&sumc!=0)
			{
				ans+=x;
				sumc--;
			}
			else
			{
				int x1=max(max(a[i-1].a,a[i-1].b),a[i-1].c),z1=min((a[i-1].a,a[i-1].b),a[i-1].c),y1=a[i-1].d-x-z;
				{
					if(x1+y<y1+x)
					{
						if(x1==a[i-1].a)
						{
							suma++;
						}
						if(x1==a[i-1].b)
						{
							sumb++;
						}
						if(x1==a[i-1].c)
						{
							sumc++;
						}
						if(y==a[i].a)
						{
							suma++;
						}
						if(y==a[i].b)
						{
							sumb++;
						}
						if(y==a[i].c)
						{
							sumc++;
						}
						if(y1==a[i-1].a)
						{
							suma--;
						}
						if(y1==a[i-1].b)
						{
							sumb--;
						}
						if(y1==a[i-1].c)
						{
							sumc--;
						}
						if(x==a[i].a)
						{
							suma--;
						}
						if(x==a[i].b)
						{
							sumb--;
						}
						if(x==a[i].c)
						{
							sumc--;
						}
						ans-=(x1+y);
						ans+=(y1+x);
					}
					else 
					{
						if(a[i].a==y)
						{
							ans+=y;
							suma--;
						}
						else if(a[i].b==y)
						{
							ans+=y;
							sumb--;
						}
						else if(a[i].c==y)
						{
							ans+=y;
							sumc--;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}