#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
struct node
{
	int d1,d2,d3;
	void r()
	{
		d1=read(),d2=read(),d3=read();
	}
}q[100005];
int max(int a,int b,int c)
{
	return max(max(a,b),c);
}
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int t,n,cnt1,cnt2,cnt3,ans;
bool cmp(node x,node y)
{
	return max(x.d1,x.d2,x.d3)-(x.d1+x.d2+x.d3-max(x.d1,x.d2,x.d3)-min(x.d1,x.d2,x.d3))>
	max(y.d1,y.d2,y.d3)-(y.d1+y.d2+y.d3-max(y.d1,y.d2,y.d3)-min(y.d1,y.d2,y.d3));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)q[i].r();
		sort(q+1,q+n+1,cmp);
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(q[i].d1>=q[i].d2&&q[i].d1>=q[i].d3)
			{
				if(cnt1==n/2)
				{
					if(q[i].d2>=q[i].d3)
					{
						cnt2++;
						ans+=q[i].d2;
					}
					else
					{
						cnt3++;
						ans+=q[i].d3;
					}
				}
				else
				{
					cnt1++;
					ans+=q[i].d1;
				}
			}
			else if(q[i].d2>=q[i].d3&&q[i].d2>=q[i].d1)
			{
				if(cnt2==n/2)
				{
					if(q[i].d1>=q[i].d3)
					{
						cnt1++;
						ans+=q[i].d1;
					}
					else
					{
						cnt3++;
						ans+=q[i].d3;
					}
				}
				else
				{
					cnt2++;
					ans+=q[i].d2;
				}
			}
			else
			{
				if(cnt3==n/2)
				{
					if(q[i].d1>=q[i].d2)
					{
						cnt1++;
						ans+=q[i].d1;
					}
					else
					{
						cnt2++;
						ans+=q[i].d2;
					}
				}
				else
				{
					cnt3++;
					ans+=q[i].d3;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
