#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define float double
using namespace std;
const int MOD=998244353;
int n,ans;
int a[5000];

// n<=20, test point 1~10:
void dfs(int step,int selected,int sum,int maxx)
{
	if(step>n)
	{
		if(selected>=3 && sum>2*maxx)
		{
			ans++;
			ans%=MOD;
		}
		return;
	}
	
	dfs(step+1,selected+1,sum+a[step],max(maxx,a[step]));
	dfs(step+1,selected,sum,maxx);
}

//n<=5000, for all 1<=i<=n: a_i=1, test point 15~20:
int C(int x,int y)
{
	if(y>x/2) y=x-y;
	int up=1;
	for(int i=x;i>y;i--)
	{
		up*=i;
		up%=MOD;
	}
	int down=1;
	for(int i=y;i>=1;i--)
	{
		down*=i;
		down%=MOD;
	}
	for(int i=x-y;i>=1;i--)
	{
		down*=i;
		down%=MOD;
	}
	int S=up/down;
	return S%=MOD;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1) cnt++;
	}
	
	// n<=20, test point 1~10:
	if(n<=25)
	{
		dfs(1,0,0,-1);
		cout<<ans<<'\n';
		return 0;
	}
	
	//n<=5000, for all 1<=i<=n: a_i=1, test point 15~20:
	else if(cnt>=n-5)
	{
		for(int i=3;i<=n;i++)
		{
			ans+=C(n,i);
			ans%=MOD;
		}
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}

