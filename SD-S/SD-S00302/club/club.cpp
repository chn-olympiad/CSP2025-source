#include<bits/stdc++.h>
using namespace std;
int n,T;
int a[100005][3],mx[100005][3];
int cnt[3],ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		ans=0;
		memset(a,0,sizeof(a));
		memset(mx,0,sizeof(mx));
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2])
			{
				mx[i][0]=0;
				if(a[i][1]>a[i][2])
				{
					mx[i][1]=1;
					mx[i][2]=2;
				}
				else
				{
					mx[i][1]=2;
					mx[i][2]=1;
				}
			}
			else if(a[i][1]>a[i][2])
			{
				mx[i][0]=1;
				if(a[i][0]>a[i][2])
				{
					mx[i][1]=0;
					mx[i][2]=2;
				}
				else
				{
					mx[i][1]=2;
					mx[i][2]=0;
				}
			}
			else
			{
				mx[i][0]=2;
				if(a[i][0]>a[i][1])
				{
					mx[i][1]=0;
					mx[i][2]=1;
				}
				else
				{
					mx[i][1]=1;
					mx[i][2]=0;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans+=a[i][mx[i][0]];
			cnt[mx[i][0]]++;
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		else if(cnt[0]>n/2)
		{
			while(cnt[0]>n/2)
			{
				int mn=20005,mi=0;
				for(int i=1;i<=n;i++)
				{
					if(mx[i][0]!=0)
					{
						continue;
					}
					if(a[i][mx[i][0]]-a[i][mx[i][1]]<mn)
					{
						mn=a[i][mx[i][0]]-a[i][mx[i][1]];
						mi=i;
					}
				}
				cnt[0]--;
				cnt[mx[mi][1]]++;
				mx[mi][0]=3;
				ans-=mn;
			}
		}
		else if(cnt[1]>n/2)
		{
			while(cnt[1]>n/2)
			{
				int mn=20005,mi=0;
				for(int i=1;i<=n;i++)
				{
					if(mx[i][0]!=1)
					{
						continue;
					}
					if(a[i][mx[i][0]]-a[i][mx[i][1]]<mn)
					{
						mn=a[i][mx[i][0]]-a[i][mx[i][1]];
						mi=i;
					}
				}
				cnt[1]--;
				cnt[mx[mi][1]]++;
				mx[mi][0]=3;
				ans-=mn;
			}
		}
		else
		{
			while(cnt[2]>n/2)
			{
				int mn=20005,mi=0;
				for(int i=1;i<=n;i++)
				{
					if(mx[i][0]!=2)
					{
						continue;
					}
					if(a[i][mx[i][0]]-a[i][mx[i][1]]<mn)
					{
						mn=a[i][mx[i][0]]-a[i][mx[i][1]];
						mi=i;
					}
				}
				cnt[2]--;
				cnt[mx[mi][1]]++;
				mx[mi][0]=3;
				ans-=mn;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
