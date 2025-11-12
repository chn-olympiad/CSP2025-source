#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct st{
	ll x,id;
	bool operator<(const st&a)const
	{
		return x<a.x;
	}
};
ll vis[101010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll t=0;
	cin>>t;
	while(t--)
	{
		priority_queue<st> q1;
		priority_queue<st> q2;
		priority_queue<st> q3;
		priority_queue<st> q;
		ll v1=0,v2=0,v3=0,ans1=0,ans2=0,ans3=0;
		ll n=0;
		cin>>n;
		for(ll i=1;i<=n;i++)
		{
			ll a,b,c;
			cin>>a>>b>>c;
			q1.push({a,i});
			q2.push({b,i});
			q3.push({c,i});
		}
		while(q1.size())
		{
			st a=q1.top();
			st b=q2.top();
			st c=q3.top();
			q1.pop();
			q2.pop();
			q3.pop();
			ll f1=1,f2=1,f3=1;
			if(v1>=n/2||vis[a.id])
			{
				f1=0;
			}
			if(v2>=n/2||vis[b.id])
			{
				f2=0;
			}
			if(v3>=n/2||vis[c.id])
			{
				f3=0;
			}
			if(a.id==b.id&&f1==1&&f2==1)
			{
				ll u=0,v=0,p1=min((ll)n-v1-v2-v3,(ll)n/2-v1),p2=min((ll)n-v1-v2-v3,(ll)n/2-v2);
				while(p1--&&q1.size())
				{
					st s=q1.top();
					q1.pop();
					q.push(s);
					if(vis[s.id])
					{
						p1++;
					}
					u=s.x;
				}
				while(q.size())
				{
					q1.push({q.top().x,q.top().id});
					q.pop();
				}
				while(p2--&&q2.size())
				{
					st s=q2.top();
					q2.pop();
					q.push(s);
					if(vis[s.id])
					{
						p2++;
					}
					v=s.x;
				}
				while(q.size())
				{
					q2.push({q.top().x,q.top().id});
					q.pop();
				}
				if(q1.size()==0)
				{
					u=v=0;
				}
				if(vis[q2.top().id])
				{
					u=0;
				}
				if(a.x+v>b.x+u)
				{
					f2=0;
				}
				else
				{
					f1=0;
				}
			}
			//cout<<f2<<'\n';
			if(c.id==b.id&&f3==1&&f2==1)
			{
				ll u=0,v=0,p1=min((ll)n-v1-v2-v3,(ll)n/2-v3),p2=min((ll)n-v1-v2-v3,(ll)n/2-v2);
				while(p1--&&q3.size())
				{
					st s=q3.top();
					q3.pop();
					q.push(s);
					if(vis[s.id])
					{
						p1++;
					}
					v=s.x;
				}
				while(q.size())
				{
					q3.push({q.top().x,q.top().id});
					q.pop();
				}
				while(p2--&&q2.size())
				{
					st s=q2.top();
					q2.pop();
					q.push(s);
					if(vis[s.id])
					{
						p2++;
					}
					u=s.x;
				}
				
				while(q.size())
				{
					q2.push({q.top().x,q.top().id});
					q.pop();
				}
				if(q1.size()==0)
				{
					u=0;
					v=0;
				}
				if(c.x+v>b.x+u)
				{
					f2=0;
				}
				else
				{
					f3=0;
				}
			}
			if(f2==1)
			{
				ans2+=b.x;
				vis[b.id]=1;
				v2++;
			}
			//cout<<q1.top().x<<q2.top().x<<q3.top().x<<'\n';
			if(a.id==c.id&&f1==1&&f3==1)
			{
				ll u=0,v=0,p1=min((ll)n-v1-v2-v3,(ll)n/2-v1),p2=min((ll)n-v1-v2-v3,(ll)n/2-v3);
				while(p1--&&q1.size())
				{
					st s=q1.top();
					q1.pop();
					q.push(s);
					if(vis[s.id])
					{
						p1++;
					}
					v=s.x;
				}
				while(q.size())
				{
					q1.push({q.top().x,q.top().id});
					q.pop();
				}
				while(p2--&&q3.size())
				{
					st s=q3.top();
					q3.pop();
					//cout<<"*"<<s.id<<'\n';
					if(vis[s.id])
					{
						p2++;
					}
					q.push(s);
					u=s.x;
				}
				
				while(q.size())
				{
					q3.push({q.top().x,q.top().id});
					q.pop();
				}
				if(q1.size()==0)
				{
					u=v=0;
				}
				//cout<<u<<v<<endl;
				if(a.x+u>c.x+v)
				{
					f3=0;
				}
				else
				{
					f1=0;
				}
			}
			//cout<<f1<<'\n';
			if(f1==1)
			{
				ans1+=a.x;
				vis[a.id]=1;
				v1++;
			}
			if(f3==1)
			{
				ans3+=c.x;
				vis[c.id]=1;
				v3++;
			}
		}
		cout<<ans1+ans2+ans3<<'\n';
		for(ll i=1;i<=n;i++)
		{
			vis[i]=0;
		}
	}
	
	return 0;
}