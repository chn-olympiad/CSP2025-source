#include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;
struct node
{
	int w1;//最满意的学院
	int f;//最大满意值
	int cz;//差值
}s[N];
int t,n,m,l1,l2,l3,ans,mr,tz;
bool cmp(node a,node b)
{
	return a.cz<b.cz;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		l1=l2=l3=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y)
			{
				if(x>=z)
				{
					s[i].w1=1;
					s[i].f=x;
					l1++;
					if(y>=z)
						s[i].cz=s[i].f-y;
					else
						s[i].cz=s[i].f-z;
				}
				else
				{
					s[i].w1=3;
					s[i].f=z;
					l3++;
					s[i].cz=s[i].f-x;
				}
			}
			else
			{
				if(y>=z)
				{
					s[i].w1=2;
					s[i].f=y;
					l2++;
					if(x>=z)
						s[i].cz=s[i].f-x;
					else
						s[i].cz=s[i].f-z;
					
				}
				else
				{
					s[i].w1=3;
					s[i].f=z;
					l3++;
					s[i].cz=s[i].f-y;
				}
			}
			ans+=s[i].f;
		}
		if(l1>m)
		{
			mr=1;
			tz=l1-m;
		}
		else if(l2>m)
		{
			mr=2;
			tz=l2-m;
		}
		else if(l3>m)
		{
			mr=3;
			tz=l3-m;
		}
		else
		{
			cout<<ans<<endl;
			continue;
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;tz>0;i++)
		{
			if(s[i].w1==mr)
			{
				ans-=s[i].cz;
				tz--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}