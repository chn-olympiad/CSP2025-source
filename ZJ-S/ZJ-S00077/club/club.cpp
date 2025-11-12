#include<bits/stdc++.h>
using namespace std;
int i,j,n,s,x,t,sk,my[4],ans,rs[4];
struct us
{
	int x1,x2,x3,zg;
}a[100005];
bool bmp(us xx,us yy)
{
	return xx.zg>yy.zg;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(sk=1;sk<=t;sk++)
	{
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
			a[i].zg=max(a[i].x1,max(a[i].x2,a[i].x3));
		}
		rs[1]=my[1]=rs[2]=my[2]=rs[3]=my[3]=0;
		sort(a+1,a+1+n,bmp);
		for(i=1;i<=n;i++)
		{
			if(a[i].x1==a[i].zg&&rs[1]<n/2)
			{
				rs[1]++;
				my[1]+=a[i].x1;
			}
			else if(rs[1]>=n/2)
			{
				if(a[i].x2>a[i].x3)
				{
					rs[2]++;
					my[2]+=a[i].x2;
				}
				else
				{
					rs[3]++;
					my[3]+=a[i].x3;
				}
			}
			else if(a[i].x2==a[i].zg&&rs[2]<n/2)
			{
				rs[2]++;
				my[2]+=a[i].x2;
			}
			else if(rs[2]>=n/2)
			{
				if(a[i].x1>a[i].x3)
				{
					rs[1]++;
					my[1]+=a[i].x1;
				}
				else
				{
					rs[3]++;
					my[3]+=a[i].x3;
				}
			}
			else if(a[i].x3==a[i].zg&&rs[3]<n/2)
			{
				rs[3]++;
				my[3]+=a[i].x3;
			}
			else if(rs[3]>=n/2)
			{
				if(a[i].x1>a[i].x2)
				{
					rs[1]++;
					my[1]+=a[i].x1;
				}
				else
				{
					rs[2]++;
					my[2]+=a[i].x2;
				}
			}
		}
		ans=my[1]+my[2]+my[3];
		cout<<ans<<endl;
	}
	return 0;
}
