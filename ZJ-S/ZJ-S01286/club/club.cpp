#include<bits/stdc++.h>
using namespace std;
struct P{
	int p,x;
	bool operator <(const P &A)const{
		return A.x<x;
	}
};
int x[100010],t[100010];
P m[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)
	{
		long long n,ans=0;
		cin >> n;
		for(int i=1;i<=n;i++)
		{
			P a,b,c;
			cin >> a.x >> b.x >> c.x;
			a.p=1,b.p=2,c.p=3;
			if(a.x<b.x)
			{
				swap(a,b);
			}
			if(a.x<c.x)
			{
				swap(a,c);
			}
			if(b.x<c.x)
			{
				swap(b,c);
			}
			x[i]=a.x-b.x;
			m[i].x=a.x;
			m[i].p=a.p;
			t[i]=b.p;
		}
		priority_queue<P> q[10];
		for(int i=1;i<=n;i++)
		{
			if(q[m[i].p].size()>=n/2)
			{
				if(q[m[i].p].top().x>x[i])
				{
					q[t[i]].push({i,x[i]});
					ans+=m[i].x-x[i];
				}
				else
				{
					q[t[q[m[i].p].top().p]].push(q[m[i].p].top());
					ans-=x[q[m[i].p].top().p];
					q[m[i].p].pop();
					q[m[i].p].push({i,x[i]});
					ans+=m[i].x;
				}
			}
			else
			{
				q[m[i].p].push({i,x[i]});
				ans+=m[i].x;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
