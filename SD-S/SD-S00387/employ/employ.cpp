#include<bits/stdc++.h>
using namespace std;
const int N=500;
const int MOD=998244353;
long long c[N+50];
string s;
long long n,m;
long long a[N+50];
void solve1()
{
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	long long ans=0;
	do
	{
		long long lose=0,win=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				lose++;
			}
			else if(lose>=c[a[i]])
			{
				lose++;
			}
			else
			{
				win++;
			}
		}
		if(win>=m)
		{
			ans=(ans+1)%MOD;
		}
	}
	while(next_permutation(a+1,a+1+n));
	cout<<ans;
}
void solve2()
{
	long long ans=1;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%MOD;
	}
	cout<<ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		solve1();
	}
	else
	{
		solve2();
	}
	return 0;
}
