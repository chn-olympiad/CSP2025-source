#include<bits/stdc++.h>
using namespace std;
int a[100001][4];
int gs[4];
int fss[100001];
int hm[100001];
int cnt;
long long ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	int n;
	cin>>t;
	while(t--)
	{
		ans=0;
		gs[1]=0;
		gs[2]=0;
		gs[3]=0;
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
			{
				gs[1]++;
				fss[i]=1;
				ans+=a[i][1];
			}
			else if(a[i][2]>=a[i][3])
			{
				gs[2]++;
				fss[i]=2;
				ans+=a[i][2];
			}
			else
			{
				gs[3]++;
				fss[i]=3;
				ans+=a[i][3];
			}
		}
		if(gs[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(fss[i]==1)
				{
					cnt++;
					hm[cnt]=min(abs(a[i][1]-a[i][2]),abs(a[i][1]-a[i][3]));
				}
			}
			sort(hm+1,hm+1+cnt);
			int bla=gs[1]-n/2;
			for(int i=1;i<=bla;i++)
			{
				ans-=hm[i];
			}
		}
		if(gs[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(fss[i]==2)
				{
					cnt++;
					hm[cnt]=min(abs(a[i][2]-a[i][1]),abs(a[i][2]-a[i][3]));
				}
			}
			sort(hm+1,hm+1+cnt);
			int bla=gs[2]-n/2;
			for(int i=1;i<=bla;i++)
			{
				ans-=hm[i];
			}
		}
		if(gs[3]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(fss[i]==3)
				{
					cnt++;
					hm[cnt]=min(abs(a[i][3]-a[i][2]),abs(a[i][3]-a[i][1]));
				}
			}
			sort(hm+1,hm+1+cnt);
			int bla=gs[3]-n/2;
			for(int i=1;i<=bla;i++)
			{
				ans-=hm[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
