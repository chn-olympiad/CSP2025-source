#include<bits/stdc++.h>
using namespace std;
string s;
char c[1005];
map<int,int> mp;
long long n,m,a[505],ans=0,tmp=0,minx=2;
long long f(int n)
{
	long long res=1;
	for(int i=1;i<=n;i++) res*=i;
	return res;
}
bool check(string c)
{
	int cnt1=0,cnt0=0;
	for(int i=0;i<c.size();i++)
	{
		if(c[i]=='0') cnt0++;
		else cnt1++;
	}
	if(cnt1!=mp[1] or cnt0!=mp[0]) 
		return false;
	else
	{
		int now0=0,suc=0;
		for(int i=1;i<=n;i++)
		{
			if(now0>a[i] and suc<m) 
				return false;
			else
			{
				if(c[i]='0') now0++;
				else suc++;
			}
		}
	}
	return true;
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(check(c)) ans++;
		return ;
	}
	for(int i=0;i<=1;i++)
	{
		c[tmp++]=char(i+48);
		dfs(k+1);
		tmp--;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++)
	{
		mp[s[i]-'0']++;
		minx=min(minx,(long long)s[i]-'0');
	}
	if(minx==1)
	{
		cout<<f(n);
	}
	else dfs(1);
	cout<<ans;
}
