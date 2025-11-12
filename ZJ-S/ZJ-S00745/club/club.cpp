#include<bits/stdc++.h>
#define ll long lnog
#define fi first
#define se second
using namespace std;
int x;
int n;
int T;
int b[100001][20];
int a[100001][20];
int ans;
int f[100001];
int c[100001];
int maxn;
bool cmp(int a1,int b1)
{
	return a[x][a1]>a[x][b1];
}
bool cmp1(int a,int b){
	return a>b;
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q[20];
void dfs(int now,int ans)
{
	//cout<<now<<endl;
	for(int i=1;i<=3;i++)
		{
			if(c[i]>n/2)return;
			//f+=c[i];
			//cout<<c[i]<<' ';
		}
	if(now==n+1)
	{
		//int f=0;
		for(int i=1;i<=3;i++)
		{
			if(c[i]>n/2)return;
			//f+=c[i];
			//cout<<c[i]<<' ';
		}
//		if(f!=n)
//		{
//			return;
//		}
		//cout<<endl;
		maxn=max(maxn,ans);
		return;
	}
	for(int i=now;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			c[j]++;
			dfs(i+1,ans+a[i][j]);
			c[j]--;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n<=30)
		{
			maxn=0;
			for(int i=1;i<=4;i++)c[i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)cin>>a[i][j];
			}
			dfs(1,0);
			cout<<maxn<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=4;i++)
		while(!q[i].empty())q[i].pop();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			cin>>a[i][j],b[i][j]=j;
		}
		bool ff=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i][2]!=a[i][3]!=0)
			ff=0;
		}
		if(ff)
		{
			for(int i=1;i<=n;i++)c[i]=a[i][1];
			sort(c+1,c+n+1,cmp1);
			for(int i=1;i<=n/2;i++)
			ans+=c[i];
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			x=i;
			sort(b[i]+1,b[i]+4,cmp);
		}
		for(int i=1;i<=n;i++)f[i]=1;
		for(int i=1;i<=n;i++)
		{
			int x=b[i][f[i]];
			if(q[x].size()<n/2)
			{
				q[x].push({a[i][x],i});
				f[i]++;
			}
			else{
				pair<int,int> fh=q[x].top();
				int f1=b[fh.se][f[fh.se]];
				int f2=b[i][f[i]+1];
				if(a[i][x]+a[fh.se][f1]>fh.fi+a[i][f2])
				{
					q[x].pop();
					q[x].push({a[i][x],i});
					f[i]++;
					q[f1].push({a[fh.se][f1],fh.se});
					f[fh.se]++;
				}
				else{
					q[f2].push({a[i][f2],i});
					f[i]+=2;
				}
			}
			}
			for(int i=1;i<=3;i++)
			{
				while(!q[i].empty())
				{
					ans+=q[i].top().fi;
					q[i].pop();
				}
			}
			cout<<ans<<endl;
	}
	return 0;
}
//dp i j k









/*
for i 1 n
	for j 1 n/2
	 	for l 1 n/2
	 	1.dp i j l = dp 
*/
