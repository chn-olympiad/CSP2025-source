#include<bits/stdc++.h>
using namespace std;
int ans[5];
int sum[1000],cs1,cs2,cs3;
struct shuliang
{
	int bm1;
	int bm2;
	int bm3;
}a[1000000];
long long n,t,oo;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	oo=t;
	while(t--)
	{
		cin>>n;
  		ans[1]=ans[2]=ans[3]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].bm1;
			cin>>a[i].bm2;
			cin>>a[i].bm3;
		}
		for(int i=1;i<=n;i++)
		{

			if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm1&&ans[1]<n/2)
  			{
  				ans[1]++;
  				cs1=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
				sum[t]+=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
			}
			else if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm2&&ans[2]<n/2)
  			{
  				cs2=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
  				ans[2]++;
				sum[t]+=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
			}
			else if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm3&&ans[3]<n/2)
  			{
  				cs3=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
  				ans[3]++;
				sum[t]+=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
			}
			else if(ans[1]==n/2)
			{
				if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm1&&a[i].bm1>cs1)
				{
					sum[t]+=a[i].bm1;
					sum[t]-=cs1;
					cs1=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
					continue;
				}
				if(max(a[i].bm2,a[i].bm3)==a[i].bm2)
				{
					ans[2]++;
					cs2=max(a[i].bm2,a[i].bm3);
					sum[t]+=max(a[i].bm2,a[i].bm3);
				}
				else if(max(a[i].bm3,a[i].bm2)==a[i].bm3)
				{
					ans[3]++;
					sum[t]+=max(a[i].bm3,a[i].bm2);
				}
			}
			else if(ans[2]==n/2)
			{
				if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm2&&a[i].bm2>cs2)
				{
					sum[t]+=a[i].bm2;
					sum[t]-=cs2;
					cs2=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
					continue;
				}
				if(max(a[i].bm1,a[i].bm3)==a[i].bm1);
				{
					ans[1]++;
					sum[t]+=max(a[i].bm1,a[i].bm3);
				}
				if(max(a[i].bm3,a[i].bm1)==a[i].bm3)
				{
					ans[3]++;
					sum[t]+=max(a[i].bm3,a[i].bm1);
				}
			}
			else if(ans[3]==n/2)
			{
				if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm3&&a[i].bm3>cs1)
				{
					sum[t]+=a[i].bm3;
					sum[t]-=cs3;
					cs3=max(a[i].bm1,max(a[i].bm2,a[i].bm3));
					continue;
				}
				if(max(a[i].bm2,a[i].bm1)==a[i].bm2)
				{
					ans[2]++;
					sum[t]+=max(a[i].bm2,a[i].bm1);
				}
				else if(max(a[i].bm1,a[i].bm2)==a[i].bm1)
				{
					ans[1]++;
					sum[t]+=max(a[i].bm1,a[i].bm2);
				}
			}
			else if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))-min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))<max(a[i+1].bm1,max(a[i+1].bm2,a[i+1].bm3)))
			{
				if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm1)
				{
					if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm2&&ans[2]<n/2)
					{
						ans[2]++;
		  				cs2=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
					else if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm3&&ans[3]<n/2)
					{
						ans[3]++;
		  				cs3=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
				}
				else if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm2)
				{
					if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm1&&ans[1]<n/2)
					{
						ans[1]++;
		  				cs1=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
					else if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm3&&ans[3]<n/2)
					{
						ans[3]++;
		  				cs3=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
				}
				else if(max(a[i].bm1,max(a[i].bm2,a[i].bm3))==a[i].bm3)
				{
					if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm2&&ans[2]<n/2)
					{
						ans[2]++;
		  				cs2=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
					else if(min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3))==a[i].bm1&&ans[1]<n/2)
					{
						ans[1]++;
		  				cs1=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
						sum[t]+=min(max(a[i].bm1,a[i].bm2),max(a[i].bm2,a[i].bm3));
					}
				}
			}
		}
	}
	for(int i=oo-1;i>=0;i--) cout<<sum[i]<<endl;
	return 0;
}