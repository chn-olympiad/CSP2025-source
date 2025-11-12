#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int t;
int n;
int a[N][3];
int ans;
priority_queue<int,vector<int>,greater<int> > q;
void solve(int k,int x)
{
	while(!q.empty())
	{
		q.pop();
	}
	int u=0,v=0;
	if(k==1)
	{
		u=0;
		v=2;
	}
	else if(k==2)
	{
		u=1;
		v=0;
	}
	else
	{
		u=1;
		v=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i][k]==max(a[i][0],max(a[i][1],a[i][2])))
		{
			q.push(a[i][k]-max(a[i][u],a[i][v]));
		}
	}
	for(int i=x;i>n/2;i--)
	{
		if(q.empty())break;
		int oo=q.top();
		ans-=oo;
		q.pop();
	}
	return;
}


signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
			}
			int o=max(a[i][0],max(a[i][1],a[i][2]));
			ans+=o;
			if(a[i][0]==o)
			{
				cnt1++;
			}
			else if(a[i][1]==o)
			{
				cnt2++;
			}
			else
			{
				cnt3++;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2)
		{
			cout<<ans<<endl;
			continue;
		}
		if(cnt1>n/2)
		{
			solve(0,cnt1);
		}
		else if(cnt2>n/2)
		{
			solve(1,cnt2);
		}
		else
		{
			solve(2,cnt3);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
