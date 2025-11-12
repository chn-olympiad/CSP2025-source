#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],vis[100010],cnt[3];
long long ans;
vector<int> v;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cnt[0]=cnt[1]=cnt[2]=0;cin>>n;ans=0;
		for(int i=1;i<=n;i++) vis[i]=0;v.clear();
		for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=1;i<=n;i++) 
		{
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) 
			{
				cnt[0]++;
				vis[i]=0;
				ans=ans+a[i][0];
			}
			else if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][0]) 
			{
				cnt[1]++;
				vis[i]=1;
				ans=ans+a[i][1];
			}
			else if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]) 
			{
				cnt[2]++;
				vis[i]=2;
				ans=ans+a[i][2];
			}
		}
		if(cnt[0]<=n/2&&cnt[1]<=n/2&&cnt[2]<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		if(cnt[0]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==0)
				{
					if(a[i][1]>=a[i][2]) v.push_back(a[i][1]-a[i][0]);
					else v.push_back(a[i][2]-a[i][0]);
				}
			}
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<cnt[0]-n/2;i++) ans=ans+v[i];
			cout<<ans<<endl;
		}
		if(cnt[1]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==1)
				{
					if(a[i][0]>=a[i][2]) v.push_back(a[i][0]-a[i][1]);
					else v.push_back(a[i][2]-a[i][1]);
				}
			}
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<cnt[1]-n/2;i++) ans=ans+v[i];
			cout<<ans<<endl;
		}
		if(cnt[2]>n/2)
		{
			for(int i=1;i<=n;i++)
			{
				if(vis[i]==2)
				{
					if(a[i][0]>=a[i][1]) v.push_back(a[i][0]-a[i][2]);
					else v.push_back(a[i][1]-a[i][2]);
				}
			}
			sort(v.begin(),v.end(),cmp);
			for(int i=0;i<cnt[2]-n/2;i++) ans=ans+v[i];
			cout<<ans<<endl;
		}
	}
	return 0;
}//fc club5.out club5.ans
