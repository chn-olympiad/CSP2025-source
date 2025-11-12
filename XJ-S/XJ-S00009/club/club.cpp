#include<bits/stdc++.h>
#define N 100010 
#define M 210
using namespace std;

int a1[N],a2[N],a3[N];
int n,idx;
int T,ans=-1;
int dp[M][M][M];
priority_queue<int> q;

void dfs(int s,int t1,int t2,int val)
{	
	ans=max(ans,val);
	int t3=s-1-t1-t2;
	if(s>n)
	{
		return;
	}
	if(dp[t1][t2][t3]>=val)
	{
		idx++;
		return;
	}
	dp[t1][t2][t3]=val;
	
	for(int i=1;i<=3;i++)
	{
		int t3=s-1-t1-t2;
		
		if(a1[s]==0 && a2[s]==0 && a3[s]==3)
		{
			dfs(s+1,t1,t2,val);
		}
		
		if(i==1 && t1<n/2)
		{
			dfs(s+1,t1+1,t2,val+a1[s]);
		}
		if(i==2 && t2<n/2)                             
		{
			dfs(s+1,t1,t2+1,val+a2[s]);
		}
		if(i==1 && t3<n/2 && a3[s]!=0)
		{
			dfs(s+1,t1,t2,val+a3[s]);
		}
	}
}
void solve()
{
	memset(dp,-1,sizeof dp);
	cin>>n;
	ans=-1;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a2[i]!=0 || a3[i]!=0)
			flag=1;
	}
	if(!flag)
	{
		for(int i=1;i<=n;i++)
		{
			q.push(a1[i]);
		}
		int cnt=n/2;
		ans=0; 
		while(cnt--)
		{
			ans+=q.top();
			q.pop();
		} 
	}
	else
	{
		dfs(1,0,0,0);
	}
	//cout<<"DP:"<<idx<<'\n';
	cout<<ans<<endl;
}
int main()
{
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
