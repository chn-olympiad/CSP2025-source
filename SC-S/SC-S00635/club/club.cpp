#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st
{
	int sum1,sum2,sum3;
}a[100005];
int T,n,ans,vis[105][55][55][55],dp[105][55][55][55],now[100005];
bool vis1[100005],wich[100005];
int f(int x,int _1,int _2,int _3)
{
	if(_1<0||_2<0||_3<0)	return LONG_LONG_MIN/2;
	if(x>n)	return 0;
	if(vis[x][_1][_2][_3]==T+1)	return dp[x][_1][_2][_3];
	vis[x][_1][_2][_3]=T+1;
	return dp[x][_1][_2][_3]=max(max(f(x+1,_1,_2,_3),f(x+1,_1,_2,_3-1)+a[x].sum3),max(f(x+1,_1-1,_2,_3)+a[x].sum1,f(x+1,_1,_2-1,_3)+a[x].sum2));
}
bool cmd(st x,st y){return x.sum1>y.sum1;}
priority_queue<pair<int,int> > _1,f1,f2;
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)	cin>>a[i].sum1>>a[i].sum2>>a[i].sum3;
		if(n<=100){cout<<f(1,n/2,n/2,n/2)<<"\n";continue;}
		sort(a+1,a+n+1,cmd);
		while(!_1.empty())	_1.pop();
		while(!f1.empty())	f1.pop();
		while(!f2.empty())	f2.pop();
		for(int i=1;i<=n;i++)	vis1[i]=wich[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(i<=n/2)	ans+=a[i].sum1,_1.push({a[i].sum2-a[i].sum1,i});
			else	f2.push({a[i].sum2,i}),f1.push({a[i].sum1,i});
		}
		for(int i=1;i<=n/2;i++)
		{
			while(!f1.empty()&&vis1[f1.top().second])	f1.pop();
			while(!f2.empty()&&vis1[f2.top().second])	f2.pop();
			if(!f2.empty()&&f2.top().first>=f1.top().first+_1.top().first)
			{
				ans+=f2.top().first;
				vis1[f2.top().second]=1;
				wich[f2.top().second]=1;
				f2.pop();
			}
			else
			{
				ans+=f1.top().first+_1.top().first;
				vis1[f1.top().second]=1;
				wich[_1.top().second]=1;
				_1.pop();
				_1.push({a[f1.top().second].sum2-a[f1.top().second].sum1,f1.top().second});
				f1.pop();
			}
		}
		for(int i=1;i<=n;i++)	now[i]=a[i].sum3-(wich[i]?a[i].sum2:a[i].sum1);
		sort(now+1,now+n+1);
		for(int i=n;i>=n/2;i--)
		{
			if(now[i]<=0)	break;
			ans+=now[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}