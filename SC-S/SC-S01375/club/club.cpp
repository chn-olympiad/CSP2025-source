#include<bits/stdc++.h>
using namespace std;
const int N=1e5,D=3;
int t,n,a[N][D];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n;
		bool f=1,flag=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
			if(a[i][1]||a[i][2]) f=0;
			if(a[i][2]) flag=0;
		}
		if(n==2)
		{
			int ans=-1;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(i!=j) ans=max(ans,a[0][i]+a[1][j]);
				}
			}
			cout<<ans<<"\n";
		}
		else if(f)
		{
			int aa[N],ans=0;
			for(int i=0;i<n;i++)
			{
				aa[i]=a[i][1];
			}
			sort(aa,aa+n);
			for(int i=n/2;i<n;i++)
			{
				ans+=aa[i];
			}
			cout<<ans<<"\n";
		}
		else if(flag)
		{
			int ans=-1;
			for(int i=1;i<(1<<n);i++)
			{
				int s=0,ss=0,cnt=0;
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)
					{
						s+=a[j][0];
						cnt++;
					}
					else ss+=a[j][1];
				}
				if(cnt==n/2) ans=max(ans,s+ss);
			}
			cout<<ans<<"\n";
		}
		else
		{
			int ans=-1;
			for(int i=0;i<(1<<n);i++)
			{
				int s=0,s2=0,s3=0,cnt=0,cnt2=0,cnt3=0,p=-1,aa[N][D];
				for(int j=0;j<n;j++)
				{
					if((i>>j)&1)
					{
						s+=a[j][0];
						cnt++;
					}
					else
					{
						p++;
						aa[p][1]=a[j][1];
						aa[p][2]=a[j][2];
					}
				}
				for(int j=0;j<(1<<p);j++)
				{
					for(int k=0;k<p;k++)
					{
						if((j>>k)&1)
						{
							s2+=aa[k][1];
							cnt2++;
						}
						else
						{
							s3+=aa[k][2];
							cnt3++;
						}
					}
				}
				if(cnt<=n/2&&cnt2<=n/2&&cnt3<=n/2) ans=max(ans,s+s2+s3);
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}