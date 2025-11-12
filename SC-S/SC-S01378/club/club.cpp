#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct v
{
	int f;
	int s;
}ab[N];
int a[N];
int b[N];
int c[N];
int ans;
int n;
bool cmp(v q,v p)
{
	if(q.f!=p.f)
		return q.f>p.f;
	return a[q.s]<a[p.s];
} 
void dfs(int id,int sum,int x,int y,int z)
{
//	cout<<id<<" "<<sum<<" "<<x<<" "<<y<<" "<<z<<"\n";
	if(id==n)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++)
	{
//		cout<<i<<" ";
		if(i==1&&x<n/2)
			dfs(id+1,sum+a[id+1],x+1,y,z);
		else if(i==2&&y<n/2)
			dfs(id+1,sum+b[id+1],x,y+1,z);
		else if(i==3&&z<n/2)
			dfs(id+1,sum+c[id+1],x,y,z+1);
	}
} 
void solve()
{
	ans=0;
	bool flag1=1,flag2=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0)
			flag1=0;
		if(c[i]!=0)
			flag2=0;
		ab[i].f=b[i]-a[i];
		ab[i].s=i;
	}
	if(flag1&&flag2)
	{
		sort(a+1,a+n+1);
		for(int i=n/2+1;i<=n;i++)
			ans+=a[i];
		cout<<ans<<"\n";
		return;
	}
	if(flag2)
	{
		sort(ab+1,ab+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=b[ab[i].s];
		for(int i=n/2+1;i<=n;i++)
			ans+=a[ab[i].s];
		cout<<ans<<"\n";
		return;
	}
	else
	{
		dfs(0,0,0,0,0);
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
} 