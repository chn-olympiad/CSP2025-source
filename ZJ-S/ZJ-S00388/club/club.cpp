#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int t,n,ans;
int c1,c2,c3,p1[N],p2[N],p3[N];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int x,y,z;
	cin>>t;
	while(t--)
	{
		cin>>n;
		c1=c2=c3=ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				p1[++c1]=x-max(y,z);
				ans+=x;
			}else if(y>=x&&y>=z)
			{
				p2[++c2]=y-max(x,z);
				ans+=y;
			}else if(z>=x&&z>=y)
			{
				p3[++c3]=z-max(x,y);
				ans+=z;
			}
		}
		if(c1>n/2)
		{
			sort(p1+1,p1+1+c1);
			for(int i=1;i<=c1-n/2;i++)
			{
				ans-=p1[i];
			}
		}
		if(c2>n/2)
		{
			sort(p2+1,p2+1+c2);
			for(int i=1;i<=c2-n/2;i++)
			{
				ans-=p2[i];
			}
		}
		if(c3>n/2)
		{
			sort(p3+1,p3+1+c3);
			for(int i=1;i<=c3-n/2;i++)
			{
				ans-=p3[i];
			}
		}
		cout<<ans<<"\n";
	}
}