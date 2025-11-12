#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll t,n,ans,sl[5],A1,A2,A3;
struct node
{
	ll my1,my2,my3;
}s[N];
bool cmpA(node x,node y)
{
	return x.my1>y.my1;
}
bool cmpB(node x,node y)
{
	return abs(x.my1-x.my2)>abs(y.my1-y.my2);
}
void sf(ll xh,ll dx)
{
	if(xh==n+1)
	{
		ans=max(dx,ans);
	}
	if(sl[1]<n/2)
	{
		sl[1]++;
		sf(xh+1,dx+s[xh].my1);
		sl[1]--;
	}
	if(sl[2]<n/2)
	{
		sl[2]++;
		sf(xh+1,dx+s[xh].my2);
		sl[2]--;
	}
	if(sl[3]<n/2)
	{
		sl[3]++;
		sf(xh+1,dx+s[xh].my3);
		sl[3]--;
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		ans=0;
		sl[1]=0;
		sl[2]=0;
		sl[3]=0;
		A1=0;
		A2=0;
		A3=0;
		for(int i=1;i<=n;i++)
		{
			ll x,y,z;
			cin>>x>>y>>z;
			if(x==0)
			{
				A1++;
			}
			if(y==0)
			{
				A2++;
			}
			if(z==0)
			{
				A3++;
			}
			s[i]={x,y,z};
		}
		if(A2==n&&A3==n)
		{
			sort(s+1,s+1+n,cmpA);
			ll sum=0;
			for(int i=1;i<=n/2;i++)
			{
				sum+=s[i].my1;
			}
			cout<<sum<<"\n";
		}
		else if(A3==n)
		{
			sort(s+1,s+1+n,cmpB);
			ll sum=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i].my1>s[i].my2)
				{
					if(sl[1]<n/2)
					{
						sl[1]++;
						sum+=s[i].my1;
					}
					else
					{
						sl[2]++;
						sum+=s[i].my2;
					}
				}
				else if(s[i].my1==s[i].my2)
				{
					if(sl[1]<sl[2])
					{
						sl[1]++;
						sum+=s[i].my1;
					}
					else
					{
						sl[2]++;
						sum+=s[i].my2;
					}
				}
				else
				{
					if(sl[2]<n/2)
					{
						sl[2]++;
						sum+=s[i].my2;
					}
					else
					{
						sl[1]++;
						sum+=s[i].my1;
					}
				}
			}
			cout<<sum<<"\n";
		}
		else
		{
			sf(1,0);
			cout<<ans<<"\n";
		}
	}
	return 0;
}
