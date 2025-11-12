#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define x first
#define y second 
int const N=1e5+5;

int n,ans,cnt[5];

struct node
{
	pii a[5];
	bool operator < (const node &t)const
	{
		if(a[1].x!=t.a[1].x)
			return a[1]>t.a[1];
		return a[2].x<t.a[2].x;
	}
}a[N];
priority_queue<int> q[5];
void solve()
{
	cin>>n;
	cnt[1]=cnt[2]=cnt[3]=ans=0;
	for(int i=1;i<=3;i++)
		while(q[i].size())
			q[i].pop();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
			cin>>a[i].a[j].x,a[i].a[j].y=j;
		sort(a[i].a+1,a[i].a+4,[](pii a,pii b){return a.x>b.x;});	
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		pii b[5];
		for(int j=1;j<=3;j++)
			b[j]=a[i].a[j];
		if(cnt[b[1].y]<n/2)
		{
			cnt[b[1].y]++;
			ans+=b[1].x;
			q[b[1].y].push(b[2].x-b[1].x);
		}
		else
		{
			int t=q[b[1].y].top();
			if(t+b[1].x<=b[2].x)
				ans+=b[2].x;
			else
			{
				q[b[1].y].pop();
				ans+=t+b[1].x;
				q[b[1].y].push(b[2].x-b[1].x);
			}
		}
	}
	cout<<ans<<"\n";
} 
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}   
