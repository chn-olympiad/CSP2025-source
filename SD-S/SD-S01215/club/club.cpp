#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,a[N][5],ans,vis[N][5],a2,a3;
void dfs(int x,int s1,int s2,int s3,int sum);
map<string,bool> s;
bool cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	cin>>n;
	a2=0,a3=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2])a2=1;
		if(a[i][3])a3=1;
	}
	if(a2==0&&a3==0)
	{
		int q[N];
		for(int i=1;i<=n;i++) q[i]=a[i][1];
		sort(q+1,q+n+1,cmp);
		ans=0;
		for(int i=1;i<=n/2;i++)ans+=q[i];
		cout<<ans<<"\n";
		return ;
	}
	memset(vis,0,sizeof vis);
	ans=0;
	dfs(1,0,0,0,0);
	cout<<ans<<"\n";
}
void dfs(int x,int s1,int s2,int s3,int sum)
{
	//cout<<"DOIN "<<x<<endl;
	if(x>n)
	{
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2&&!vis[x][1])
	{
	//	vis[x][1]=1;
		dfs(x+1,s1+1,s2,s3,sum+a[x][1]);
	//	vis[x][1]=0;
	}
	if(s2<n/2&&!vis[x][2])
	{
		vis[x][2]=1;
		dfs(x+1,s1,s2+1,s3,sum+a[x][2]);
	//	vis[x][2]=0;
	}
	if(s3<n/2&&!vis[x][3])
	{
	//	vis[x][3]=1;
		dfs(x+1,s1,s2,s3+1,sum+a[x][3]);
	//	vis[x][3]=0;
	}
	ans=max(ans,sum);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
