// SN-S00090  华紫陌   西安辅轮中学 
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[100001][4];
int cho[100001];
int b[4];
int ans=0;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(cho,0,sizeof(cho));
		vector<int>x[4];
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
		for(int i=1;i<=n;i++)
		{
			if(a[i][1]>a[i][2] && a[i][1]>a[i][3])
			{
				cho[i]=1;
				ans+=a[i][1];
				b[1]++;
				continue;
			} 
			if(a[i][2]>a[i][1] && a[i][2]>a[i][3])
			{
				cho[i]=2;
				ans+=a[i][2];
				b[2]++;
				continue;
			} 
			if(a[i][3]>a[i][1] && a[i][3]>a[i][2]) 
			{
				cho[i]=3;
				ans+=a[i][3];
				b[3]++;
				continue;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(cho[i])
			{
				continue;
			} 
			if(a[i][1]==a[i][2] && a[i][2]==a[i][3])
			{
				if(b[1]<b[2] && b[1]<b[3]) cho[i]=1,ans+=a[i][1];
				if(b[2]<b[1] && b[2]<b[3]) cho[i]=2,ans+=a[i][2];
				if(b[3]<b[1] && b[3]<b[2]) cho[i]=3,ans+=a[i][3];
			}
			if(a[i][1]==a[i][2])
			{
				if(b[1]<b[2]) b[1]++,cho[i]=1,ans+=a[i][1];
				if(b[2]<b[1]) b[2]++,cho[i]=2,ans+=a[i][2];
			}
			if(a[i][2]==a[i][3])
			{
				if(b[2]<b[3]) b[2]++,cho[i]=2,ans+=a[i][2];
				if(b[3]<b[2]) b[3]++,cho[i]=3,ans+=a[i][3];
			}
			if(a[i][1]==a[i][3])
			{
				if(b[1]<b[3]) b[1]++,cho[i]=1,ans+=a[i][1];
				if(b[3]<b[1]) b[3]++,cho[i]=3,ans+=a[i][3];
			}
		}
		if(b[1]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(cho[i]==1)
				{
					int cnt=a[i][1]-max(a[i][2],a[i][3]);
					x[1].push_back(cnt);
				}
			sort(x[1].begin(),x[1].end());
			int y=0;
			for(int i=b[1];i>n/2;i--)
			{
				ans-=x[1][y];
				y++;
			}
		}
		if(b[2]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(cho[i]==2)
				{
					int cnt=a[i][2]-max(a[i][1],a[i][3]);
					x[2].push_back(cnt);
				}
			sort(x[2].begin(),x[2].end());
			int y=0;
			for(int i=b[2];i>n/2;i--)
			{
				ans-=x[2][y];
				y++;
			}
		}
		if(b[3]>n/2)
		{
			for(int i=1;i<=n;i++)
				if(cho[i]==3)
				{
					int cnt=a[i][3]-max(a[i][2],a[i][1]);
					x[3].push_back(cnt);
				}
			sort(x[3].begin(),x[3].end());
			int y=0;
			for(int i=b[3];i>n/2;i--)
			{
				ans-=x[3][y];
				y++;
			}
	 	}
		cout<<ans<<"\n";
	}
	return 0;
}
