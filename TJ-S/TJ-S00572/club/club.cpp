#include<bits/stdc++.h>
#define int long long
using namespace std; 
int t,n;
struct student{
	int a,b,c;
	int max1,max2,max3;
}x[100005];
struct ye{
	int cnt;
	int nxt;
	int seq;
}change[100005];
bool cmp1(ye x2,ye y2)
{
	if(x2.seq==1&&y2.seq!=1)
	{
		return true;
	}
	if(x2.seq!=1&&y2.seq==1)
	{
		return false;
	}
	return x2.cnt-x2.nxt<y2.cnt-y2.nxt;
}
bool cmp2(ye x2,ye y2)
{
	if(x2.seq==2&&y2.seq!=2)
	{
		return true;
	}
	if(x2.seq!=2&&y2.seq==2)
	{
		return false;
	}
	return x2.cnt-x2.nxt<y2.cnt-y2.nxt;
}
bool cmp3(ye x2,ye y2)
{
	if(x2.seq==3&&y2.seq!=3)
	{
		return true;
	}
	if(x2.seq!=3&&y2.seq==3)
	{
		return false;
	}
	return x2.cnt-x2.nxt<y2.cnt-y2.nxt;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while (t--)
	{
		memset(x,0,sizeof(x));
		memset(change,0,sizeof(change));
		cin>>n;
		int k1=0,k2=0,k3=0,ans=0;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i].a>>x[i].b>>x[i].c;
			if (x[i].a>=x[i].b&&x[i].a>=x[i].c)
			{
				x[i].max1=1;
				if(x[i].b>=x[i].c)
				{
					x[i].max2=2;x[i].max3=3;
				}
				else
				{
					x[i].max2=3;x[i].max3=2;
				}
			}
			else if (x[i].b>=x[i].a&&x[i].b>=x[i].c)
			{
				x[i].max1=2;
				if(x[i].a>=x[i].c)
				{
					x[i].max2=1;x[i].max3=3;
				}
				else
				{
					x[i].max2=3;x[i].max3=1;
				}
			}
			else
			{
				x[i].max1=3;
				{
					if (x[i].a>=x[i].b)
					{
						x[i].max2=1;x[i].max3=2;
					}
					else
					{
						x[i].max2=2;x[i].max3=1;
					}
				}
			}
			if(x[i].max1==1)
			{
				k1++;
				change[i].cnt=x[i].a;change[i].seq=1;ans+=change[i].cnt;
				if (x[i].max2==2)
				{
					change[i].nxt=x[i].b;
				}
				else
				{
					change[i].nxt=x[i].c;
				}
				
			}
			else if (x[i].max1==2)
			{
				k2++;
				change[i].cnt=x[i].b;change[i].seq=2;ans+=change[i].cnt;

				if (x[i].max2==1)
				{
					change[i].nxt=x[i].a;
				}
				else
				{
					change[i].nxt=x[i].c;
				}
				
			}
			else
			{
				k3++;
				change[i].cnt=x[i].c;change[i].seq=3;ans+=change[i].cnt;
				if (x[i].max2==1)
				{
					change[i].nxt=x[i].a;
				}
				else
				{
					change[i].nxt=x[i].b;
				}
				
			}
		}
		if(k1>n/2)
		{
			sort(change+1,change+n+1,cmp1);
			for (int i=1;i<=k1-n/2;i++)
			{
				
				ans-=change[i].cnt;ans+=change[i].nxt;
			}
			cout<<ans<<'\n';
		}
		else if(k2>n/2)
		{
			sort(change+1,change+n+1,cmp2);
			for (int i=1;i<=k2-n/2;i++)
			{
				
				ans-=change[i].cnt;ans+=change[i].nxt;
			}
			cout<<ans<<'\n';
		}
		else if(k3>n/2)
		{
			sort(change+1,change+n+1,cmp3);
			for (int i=1;i<=k3-n/2;i++)
			{
				
				ans-=change[i].cnt;ans+=change[i].nxt;
			}
			cout<<ans<<'\n';
		}
		else
		{
			cout<<ans<<'\n';
		}
	}
	return 0;
}
