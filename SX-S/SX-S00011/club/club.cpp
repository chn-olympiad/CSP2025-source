#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct s
{
	ll x,y,z,g;
}a[100005];
ll ans,n,v[100005];
void dfs(int step,ll sum,int r1,int r2,int r3)
{
	if(step>n)
	{
		ans=max(ans,sum);
		return ;
	}
	if(r1<n/2) dfs(step+1,sum+a[step].x,r1+1,r2,r3);
	if(r2<n/2) dfs(step+1,sum+a[step].y,r1,r2+1,r3);
	if(r3<n/2) dfs(step+1,sum+a[step].z,r1,r2,r3+1);
}
bool cmp(s q,s w)
{
	if(q.x!=w.x)return q.x>w.x;
	return q.y>w.y;
}
bool cmp2(s q,s w)
{
	return q.y>w.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z;
		}
		if(n>=20)
		{
			sort(a+1,a+n+1,cmp);
			int tot=0,t1=1;
			for(int i=1;i<=n,t1<=n/2;i++)
			{
				if(a[i].y>a[i].x) continue;
				tot+=a[i].x;
				t1++;
				a[i].g=1;
			}
			sort(a+1,a+n+1,cmp2);
			t1=1;
			for(int i=1;i<=n,t1<=n/2;i++)
			{
				if(a[i].g==1)
				{
					a[i].g=0;
					continue;
				}
				tot+=a[i].y;
				t1++;
			}
			cout<<tot<<"\n";
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}