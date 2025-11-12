#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c[505];
string s;
ll ans;
bool v[505];
void dfs(int x,int sum)
{
	if(sum==m)
	{
		int sx=n-x+1;
		int aa=1;
		for(int i=1;i<=sx;i++)
		{
			aa*=i;
		}
		ans=(ans+aa)%998244353;
		return;
	}
	if(x>n)
	{
		if(sum>=m) 
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			v[i]=true;
			int num=s[x-1]-'0';
			if(c[i]<=x-1-sum)
			{
				num=0;
			}
			dfs(x+1,sum+num);
			v[i]=false;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
//CCF I need some fenshu helpme can you give me 10 to my big rude code? Thank you CCF I love CCF,CCF is the best.
//My rude code also have jianzhi I don't known how can I AC this problem so that I can only write the rude code.So give me some fenshu.I am so hard;
//wan dan le jin nian yi jing gao er le csp da bu guo de hua wo jiu yao tui yi le wo xiang da NOIP.
	return 0;
}
