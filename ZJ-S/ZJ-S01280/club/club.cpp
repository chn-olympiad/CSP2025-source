#include<bits/stdc++.h>
using namespace std;
int n,a[3][100010],s[3],ss,tt[100010],cnt,T;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>T;
	while(T--)
	{
		cnt=ss=s[0]=s[1]=s[2]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[j][i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			ss+=max(a[0][i],max(a[1][i],a[2][i]));
			if(a[0][i]>a[1][i]&&a[0][i]>a[2][i])
			{
				s[0]++;
			}
			else if(a[1][i]>a[2][i])
			{
				s[1]++;
			}
			else
			{
				s[2]++;
			}
		}
		if(s[0]*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[0][i]>a[1][i]&&a[0][i]>a[2][i])
				{
					tt[++cnt]=min(a[0][i]-a[1][i],a[0][i]-a[2][i]);
				}
			}
			sort(tt+1,tt+cnt+1);
			for(int i=1;i<=s[0]-n/2;i++)
			{
				ss-=tt[i];
			}
		}
		if(s[1]*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[1][i]>a[0][i]&&a[1][i]>a[2][i])
				{
					tt[++cnt]=min(a[1][i]-a[0][i],a[1][i]-a[2][i]);
				}
			}
			sort(tt+1,tt+cnt+1);
			for(int i=1;i<=s[1]-n/2;i++)
			{
				ss-=tt[i];
			}
		}
		if(s[2]*2>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[2][i]>a[0][i]&&a[2][i]>a[1][i])
				{
					tt[++cnt]=min(a[2][i]-a[0][i],a[2][i]-a[1][i]);
				}
			}
			sort(tt+1,tt+cnt+1);
			for(int i=1;i<=s[2]-n/2;i++)
			{
				ss-=tt[i];
			}
		}
		cout<<ss<<'\n';
	}
	return 0;
}