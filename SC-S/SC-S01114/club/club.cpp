#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
priority_queue<pii,vector<pii>,greater<pii>> qx,qy,qz;
int n;
const int N=1e5+5;
struct Node
{
	int x,y,z;
}a[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			a[i].x=x,a[i].y=y,a[i].z=z;
			int maxn=max(x,max(y,z));
			if(maxn==x)
			{
				if(qx.size()==n/2)
				{
					auto pai=qx.top();
					if(x-pai.first>max(y,z))  //max(a[qx.top().second].y,a[qx.top().second].z)-qx.top().first
					{
						ans+=x-pai.first;
						qx.pop();
						qx.push({x-max(y,z),i});
						if(a[pai.second].y>=a[pai.second].z)
							qy.push({a[pai.second].y-max(a[pai.second].x,a[pai.second].z),pai.second});
						else 
							qz.push({a[pai.second].z-max(a[pai.second].x,a[pai.second].y),pai.second});
					}
					else
					{
						ans+=max(y,z);
						if(y>=z)
							qy.push({y-max(x,z),i});
						else 
							qz.push({z-max(x,y),i});
					}
				}
				else
				{
					ans+=x;
					qx.push({x-max(y,z),i});
				}
			}
			else if(maxn==y)
			{
				if(qy.size()==n/2)
				{
					auto pai=qy.top();
					if(y-pai.first>max(x,z))
					{
						ans+=y-pai.first;
						qy.pop();
						qy.push({y-max(x,z),i});
						if(a[pai.second].x>=a[pai.second].z)
							qx.push({a[pai.second].x-max(a[pai.second].y,a[pai.second].z),pai.second});
						else 
							qz.push({a[pai.second].z-max(a[pai.second].x,a[pai.second].y),pai.second});
					}
					else
					{
						ans+=max(x,z);
						if(x>=z)
							qx.push({x-max(y,z),i});
						else 
							qz.push({z-max(x,y),i});
					}
				}
				else
				{
					ans+=y;
					qy.push({y-max(x,z),i});
				}
			}
			else if(maxn==z)
			{
				if(qz.size()==n/2)
				{
					auto pai=qz.top();
					if(z-pai.first>max(x,y))
					{
						ans+=z-pai.first;
						qz.pop();
						qz.push({z-max(x,y),i});
						if(a[pai.second].x>=a[pai.second].y)
							qx.push({a[pai.second].x-max(a[pai.second].y,a[pai.second].z),pai.second});
						else 
							qy.push({a[pai.second].y-max(a[pai.second].x,a[pai.second].z),pai.second});
					}
					else
					{
						ans+=max(y,x);
						if(x>=y)
							qx.push({x-max(y,z),i});
						else 
							qy.push({y-max(x,z),i});
					}
				}
				else
				{
					ans+=z;
					qz.push({z-max(x,y),i});
				}
			}
		}
		while(!qx.empty())
		{
			qx.pop();
		}
		while(!qy.empty())
		{
			qy.pop();
		}
		while(!qz.empty())
		{
			qz.pop();
		}
		cout<<ans<<"\n";
	}
	return 0;
}