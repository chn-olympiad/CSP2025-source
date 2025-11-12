#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+5;
const int INF=0x3f3f3f3f;
struct node
{
	int x,y,z;
}a[N];
int t,n,tmp,ans1,ans2,ans3;
ll ans,cur;
bool vis[N];
inline void fre()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
void dfs(int l,ll res)
{
	if(l==n) 
	{
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(ans1<tmp&&!vis[i])
		{
			ans1++;
			vis[i]=1;
			dfs(l+1,res+a[i].x);
			vis[i]=0;
			ans1--;
		}
		if(ans2<tmp&&!vis[i])
		{
			ans2++;
			vis[i]=1;
			dfs(l+1,res+a[i].y);
			ans2--;	
			vis[i]=0;
		}
		if(ans3<tmp&&!vis[i])
		{
			ans3++;
			vis[i]=1;
			dfs(l+1,res+a[i].z);
			vis[i]=0;
			ans3--;	
		}
	}
	return;	
}
void solve()
{
	ans1=ans2=ans3=0;
	ans=0;cur=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].x>=a[i].y&&a[i].x>=a[i].z) 
		{
			ans+=a[i].x;
			ans1++;
		}
		else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) 
		{
			ans+=a[i].y;
			ans2++;
		}
		else if(a[i].z>=a[i].x&&a[i].z>=a[i].y) 
		{
			ans+=a[i].z;
			ans3++;
		}
	}
	tmp=n/2;
	if(ans1<=tmp&&ans2<=tmp&&ans3<=tmp)
	{
		cout<<ans<<'\n';
		return;
	}
	else if(n<=10)
	{
		ans=0;
		ans1=ans2=ans3=0;
		dfs(0,0);//
		cout<<ans<<'\n';
	}
		else cout<<ans-a[1].z<<'\n';
	return;
}
int main()
{
	fre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--) 
		solve();
	return 0;
}
