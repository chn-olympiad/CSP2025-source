#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10,mod=998244353;
int n,m;
int flag;
int a[N];
int c[N];
int f[N];
ll ans;
string s;
void dfs(int now)
{
	if(now==n+1)
	{
		int cnt=0;
		string str="";
		int num=0;//几个人面试失败 
		for(int i=1;i<=n;i++)
		{
			if(cnt+n-i+1<m) return;
			str+=to_string(a[i]);
			if(s[i]=='0')
			{
				num++;
			}
			else
			{
				if(num<c[a[i]]) cnt++;
				else num++;
			}
		}
		if(cnt>=m)
		{
			ans++;
			ans%=mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=1;
			a[now]=i;
			dfs(now+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin >>s;
	int nn=n;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0') flag=1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(c[i]==0) nn--;
	}
	if(!flag)
	{
		ll ans=1;
		for(int i=1;i<=nn;i++)
		{
			ans=ans*i;
			ans%=mod;
		}
		printf("%lld",ans);
	}
	else
	{
		dfs(1);
		printf("%lld",ans);
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
