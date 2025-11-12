#include<bits/stdc++.h>
using namespace std;
#define int long long
const int P=998244353;
int n,m;
int h[555],b[12],vis[12],ans;
string s;
bool check1()
{
	for(int i=0;i<n;i++)
		if(s[i]=='0') return 0;
	return 1;
}
void dfs(int t)
{
	if(t>n)
	{
		int cnt=0,res=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0')
			{
				cnt++;
				continue;
			}
			if(cnt>=h[b[i+1]]) cnt++;
			else res++;
		}
		if(res>=m) ans=(ans+1)%P;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			b[t]=i;
			vis[i]=1;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>h[i];
	if(n<=18)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	if(check1())
	{
		int cnt=1;
		for(int i=2;i<=n;i++)
			cnt=(cnt*i)%P;
		cout<<cnt<<"\n";
		return 0;
	}
	return 0;
}