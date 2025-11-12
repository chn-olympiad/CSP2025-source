#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1e5;
struct node
{
	ll x,y,z;
}a[MX+10];
bool b[MX+10][4];
ll T,n,i,s,t,u,len,sum,cnt[MX+10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(b,0,sizeof(b));
		len=0;
		sum=0;s=t=u=0;
		for(i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].x>=max(a[i].y,a[i].z))
			{
				b[i][1]=1;sum+=a[i].x;s++;
			}
			else if(a[i].y>=max(a[i].x,a[i].z))
			{
				b[i][2]=1;sum+=a[i].y,t++;
			}
			else if(a[i].z>=max(a[i].x,a[i].y))
			{
				b[i][3]=1;sum+=a[i].z,u++;
			}
		}
		if(s>n/2)
		{
			for(i=1;i<=n;i++)
			{
				if(b[i][1])
				{
					cnt[++len]=min(a[i].x-a[i].y,a[i].x-a[i].z);
				}
			}
		}
		else if(t>n/2)
		{
			for(i=1;i<=n;i++)
			{
				if(b[i][2])
				{
					cnt[++len]=min(a[i].y-a[i].x,a[i].y-a[i].z);
				}
			}
		}
		else if(u>n/2)
		{
			for(i=1;i<=n;i++)
			{
				if(b[i][3])
				{
					cnt[++len]=min(a[i].z-a[i].y,a[i].z-a[i].x);
				}
			}
		}
		sort(cnt+1,cnt+len+1);
		if(s>n/2)
		{
			for(i=1;i<=s-n/2;i++)sum-=cnt[i];
		}
		else if(t>n/2)
		{
			for(i=1;i<=t-n/2;i++)sum-=cnt[i];
		}
		else if(u>n/2)
		{
			for(i=1;i<=u-n/2;i++)sum-=cnt[i];
		}
		cout<<sum<<'\n';
	}
	return 0;
}
