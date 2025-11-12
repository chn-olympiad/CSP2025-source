#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[3];
priority_queue<pair<int,pair<int,pair<int,int>>>>q,q1,q2,q3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--)
	{
		cin>>n;
		while(!q.empty()) q.pop();
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		while(!q3.empty()) q3.pop();
		for(int i=1,a,b,c;i<=n;i++)
		{
			cin>>a>>b>>c;
			q.push(make_pair(max({a,b,c}),make_pair(a,make_pair(b,c))));
		}
		int ans=0;
		int a1,a2,a3;
		cnt[0]=cnt[1]=cnt[2]=0;
		while(!q.empty())
		{
			pair<int,pair<int,pair<int,int>>>p=q.top();
			int maxn=p.first;
			a1=p.second.first;
			a2=p.second.second.first;
			a3=p.second.second.second;
			//cerr<<a1<<" "<<a2<<" "<<a3<<" "<<maxn<<"\n";
			if(a1==a2&&a2==a3&&a1==0) break;
			q.pop();
			if(maxn==a1)
			{
				int t1=a1-maxn,t2=a2-maxn,t3=a3-maxn;
				if(cnt[0]<n/2) cnt[0]++,ans+=maxn,q1.push(make_pair(max({t2,t3}),make_pair(t1,make_pair(t2,t3))));
				else
				{
					pair<int,pair<int,pair<int,int>>>pp=q1.top();
					int minn=pp.first,b1=pp.second.first,b2=pp.second.second.first,b3=pp.second.second.second;
					if(a1+minn<=0)
					{
						q.push(make_pair(max(a2,a3),make_pair(0,make_pair(a2,a3))));
						continue;
					}
					q1.pop();
					ans+=a1+minn;q1.push(make_pair(max({t2,t3}),make_pair(t1,make_pair(t2,t3))));
				}
			}
			else if(maxn==a2)
			{
				int t1=a1-maxn,t2=a2-maxn,t3=a3-maxn;
				if(cnt[1]<n/2) cnt[1]++,ans+=maxn,q2.push(make_pair(max({t1,t3}),make_pair(t1,make_pair(t2,t3))));
				else
				{
					pair<int,pair<int,pair<int,int>>>pp=q2.top();
					int minn=pp.first,b1=pp.second.first,b2=pp.second.second.first,b3=pp.second.second.second;
					if(a2+minn<=0)
					{
						q.push(make_pair(max(a1,a3),make_pair(a1,make_pair(0,a3))));
						continue;
					}
					q2.pop();
					ans+=a2+minn;q2.push(make_pair(max({t1,t3}),make_pair(t1,make_pair(t2,t3))));
				}
			}
			else if(maxn==a3)
			{
				int t1=a1-maxn,t2=a2-maxn,t3=a3-maxn;
				if(cnt[2]<n/2) cnt[2]++,ans+=maxn,q3.push(make_pair(max({t1,t2}),make_pair(t1,make_pair(t2,t3))));
				else
				{
					pair<int,pair<int,pair<int,int>>>pp=q3.top();
					int minn=pp.first,b1=pp.second.first,b2=pp.second.second.first,b3=pp.second.second.second;
					if(a3+minn<=0)
					{
						q.push(make_pair(max(a1,a2),make_pair(a1,make_pair(a2,0))));
						continue;
					}
					q3.pop();
					ans+=a3+minn;q3.push(make_pair(max({t1,t2}),make_pair(t1,make_pair(t2,t3))));
				}
			}
		}
		cout<<ans<<"\n";
	}
	
}