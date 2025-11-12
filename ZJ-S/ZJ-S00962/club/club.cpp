#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
int n;
int a[100005][4];
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q[4];
priority_queue <int> qq;
signed main()
{
//	system("fc club.out club5.ans");
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)
		{
			int maxx=max(a[i][1],max(a[i][2],a[i][3]));//d
			int minn=min(a[i][1],min(a[i][2],a[i][3]));//f
			int mid=a[i][1]+a[i][2]+a[i][3]-maxx-minn;//e
			int id=0;//d
			if(a[i][1]==maxx) id=1;
			if(a[i][2]==maxx) id=2;
			if(a[i][3]==maxx) id=3;
			q[id].push({maxx,i});
		}
		int ans=0;
		int id=0;
		if(q[1].size()>n/2) id=1;
		if(q[2].size()>n/2) id=2;
		if(q[3].size()>n/2) id=3;
		if(id==0)
		{
			for(int i=1;i<=3;i++)
			{
				while(!q[i].empty())
				{
					ans+=q[i].top().first;
					q[i].pop();
				}
			}
		}
		else
		{
			for(int i=1;i<=3;i++)
			{
				if(id==i) continue;
				while(!q[i].empty())
				{
					ans+=q[i].top().first;
					q[i].pop();
				}
			}
			int sz=q[id].size()-n/2;
			while(!q[id].empty())
			{
				int i=q[id].top().second;
				int maxx=max(a[i][1],max(a[i][2],a[i][3]));
				int minn=min(a[i][1],min(a[i][2],a[i][3]));
				int mid=a[i][1]+a[i][2]+a[i][3]-maxx-minn;
				qq.push(mid-maxx);
				ans+=q[id].top().first;
				q[id].pop();
			}
			while(sz--)
			{
				ans+=qq.top();
				qq.pop();
			}
			while(!qq.empty()) qq.pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}
