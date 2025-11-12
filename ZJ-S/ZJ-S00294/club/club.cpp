#include <iostream>
#include <algorithm>
using namespace std;
int t,a[100005][4];
int vis[4];
struct NODE
{
	int MAX,LMAX,c,Mid,LMid;
}p[1000005];
bool cmp(NODE x,NODE y)
{
	return x.c>y.c;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int op=n/2;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			p[i].MAX=max(a[i][1],max(a[i][2],a[i][3]));
			for(int j=1;j<=3;j++)
			{
				if(p[i].MAX==a[i][j])
				{
					p[i].Mid=j;
					continue;
				}
				if(a[i][j]>p[i].LMAX)
				{
					p[i].LMAX=a[i][j];
					p[i].LMid=j;
				}
			}
			p[i].c=p[i].MAX-p[i].LMAX;
		}
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(vis[p[i].Mid]==op)
			{
				ans+=p[i].LMAX;
				vis[p[i].LMid]++;
			}
			else
			{
				ans+=p[i].MAX;
				vis[p[i].Mid]++;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=3;i++)
		{
			vis[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			p[i].MAX=0;
			p[i].LMAX=0;
			p[i].Mid=0;
			p[i].LMid=0;
			p[i].c=0;
		}
	}
	return 0;
	
}