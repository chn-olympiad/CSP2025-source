//SN-S00010 qiaoyuxiao
#include<bits/stdc++.h>
using namespace std;
int n,v[4];
long long ans;
struct node{
	int maxx,ci,cha,idm,idc;
}num[100010];
bool cmp(node x,node y)
{
	return x.cha>y.cha;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(a>=b&&b>=c)
			{
				num[i].maxx=a;num[i].ci=b;num[i].cha=a-b;num[i].idm=1;num[i].idc=2;
			}
			else if(a>=c&&c>=b)
			{
				num[i].maxx=a;num[i].ci=c;num[i].cha=a-c;num[i].idm=1;num[i].idc=3;
			}
			else if(b>=a&&a>=c)
			{
				num[i].maxx=b;num[i].ci=a;num[i].cha=b-a;num[i].idm=2;num[i].idc=1;
			}
			else if(b>=c&&c>=a)
			{
				num[i].maxx=b;num[i].ci=c;num[i].cha=b-c;num[i].idm=2;num[i].idc=3;
			}
			else if(c>=a&&a>=b)
			{
				num[i].maxx=c;num[i].ci=a;num[i].cha=c-a;num[i].idm=3;num[i].idc=1;
			}
			else if(c>=b&&b>=a)
			{
				num[i].maxx=c;num[i].ci=b;num[i].cha=c-b;num[i].idm=3;num[i].idc=2;
			}
		}
		int m=n/2;
		sort(num+1,num+n+1,cmp);
		for(int i=1;i<=3;i++)v[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(v[num[i].idm]<m)
			{
				ans+=num[i].maxx;
				v[num[i].idm]++;
			}
			else
			{
				ans+=num[i].ci;
				v[num[i].idc]++;
			}
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
