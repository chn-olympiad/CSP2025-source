#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
struct node
{
	int x,y,z,t;
}a[N];
int pd(int x,int y,int z)
{
	if(x==0)return max(y,z)-min(y,z);
	if(y==0)return max(x,z)-min(x,z);
	if(z==0)return max(x,y)-min(x,y);
}
int cmp(node a,node b)
{
	return a.t>b.t;
}
void solve()
{
	cin>>n;
	int MIN;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		MIN=min(min(a[i].z,a[i].y),a[i].x);
		sum+=MIN;
		a[i].x-=MIN;a[i].y-=MIN;a[i].z-=MIN;
		a[i].t=pd(a[i].x,a[i].y,a[i].z);
	}
	sort(a+1,a+n+1,cmp);
	int pdx=n/2,pdy=n/2,pdz=n/2;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
		{
			if(pdx>0)
			{
				pdx--;
				sum+=a[i].x;
			}
			else
			{
				sum+=max(a[i].y,a[i].z);
			}
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
		{
			if(pdy>0)
			{
				pdy--;
				sum+=a[i].y;
			}
			else
			{
				sum+=max(a[i].x,a[i].z);
			}
		}
		else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)
		{
			if(pdz>0)
			{
				pdz--;
				sum+=a[i].z;
			}
			else
			{
				sum+=max(a[i].y,a[i].x);
			}
		}
	}
	cout<<sum<<endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
