#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct ss{
	int a,b,c,t,m;
}a[100005];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		int n,b[3]={},ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			int maxn=max(max(a[i].a,a[i].b),a[i].c);
			if(maxn==a[i].a)
			{
				a[i].t=0;
				b[0]++;
				a[i].m=min(a[i].a-a[i].b,a[i].a-a[i].c);
			}
			if(maxn==a[i].b)
			{
				a[i].t=1;
				b[1]++;
				a[i].m=min(a[i].b-a[i].a,a[i].b-a[i].c);
			}
			if(maxn==a[i].c)
			{
				a[i].t=2;
				b[2]++;
				a[i].m=min(a[i].c-a[i].b,a[i].c-a[i].a);
			}
			ans+=maxn;
		}
		if(b[0]<=n/2&&b[2]<=n/2&&b[1]<=n/2)
		{
			cout<<ans;
		}
		else if(b[0]>n/2)
		{
			int x1[100005],xx=0;
			for(int i=0;i<n;i++)
			{
				if(a[i].t==0)
				{
					x1[xx]=a[i].m;
					xx=xx+1;
				}
			}
			sort(x1,x1+xx,cmp);
			for(int i=0;i<b[0]-n/2;i++)
				ans-=x1[i];
			cout<<ans;
		}
		else if(b[1]>n/2)
		{
			int x1[100005],xx=0;
			for(int i=0;i<n;i++)
			{
				if(a[i].t==1)
				{
					x1[xx]=a[i].m;
					xx=xx+1;
				}
			}
			sort(x1,x1+xx,cmp);
			for(int i=0;i<b[1]-n/2;i++)
				ans-=x1[i];
			cout<<ans;
		}
		else
		{
			int x1[100005],xx=0;
			for(int i=0;i<n;i++)
			{
				if(a[i].t==2)
				{
					x1[xx]=a[i].m;
					xx=xx+1;
				}
			}
			sort(x1,x1+xx,cmp);
			for(int i=0;i<b[2]-n/2;i++)
				ans-=x1[i];
			cout<<ans;
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}