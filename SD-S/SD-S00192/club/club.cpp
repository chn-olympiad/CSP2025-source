#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10;
int T,n,ans,cnt[4];
pii a[3]; 
priority_queue<pii,vector<pii >,greater<pii > > q; 
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;ans=0;
		memset(cnt,0,sizeof(cnt));
		while(!q.empty()) q.pop();
		for(int i=1,x,y,z;i<=n;i++)
		{
			cin>>x>>y>>z;
			a[0]=make_pair(x,1);
			a[1]=make_pair(y,2);
			a[2]=make_pair(z,3);
			sort(a,a+3);
			ans+=a[2].first;
			cnt[a[2].second]++;
			q.push({a[2].first-a[1].first,a[2].second});
		}
		if(cnt[1]>(n/2)) 
		{
			int x=cnt[1]-(n/2);
			while(!q.empty()&&x)
			{
				if(q.top().second==1)
				{
					ans-=q.top().first;
					x--;
				}
				q.pop();
			}
		}
		else if(cnt[2]>(n/2)) 
		{
			int x=cnt[2]-(n/2);
			while(!q.empty()&&x)
			{
				if(q.top().second==2)
				{
					ans-=q.top().first;
					x--;
				}
				q.pop();
			}
		}
		else if(cnt[3]>(n/2)) 
		{
			int x=cnt[3]-(n/2);
			while(!q.empty()&&x)
			{
				if(q.top().second==3)
				{
					ans-=q.top().first;
					x--;
				}
				q.pop();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
